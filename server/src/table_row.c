#include <stdlib.h>
#include "schema.h"
#include "input.h"
#include "cell_utils.h"

size_t addRowToFile(FILE *file, struct TableScheme *scheme, union TableCellWithData *row) {
    size_t row_size = sizeof(union TableCellWithData) * scheme->columnsCount;
    size_t sectors_size = calculateSectorsNeeded(row_size);
    uint32_t allocated_sector = allocateSector(file, sectors_size);

    writeDataToSector(file, row, row_size, allocated_sector);

    // Change sector headers links
    if (scheme->dataFirstSector == HASH_NONE) {
        // Nothing to change in headers, no links
        scheme->dataFirstSector = allocated_sector;
    } else {
        // Make links for two sectors
        struct SectorHeader last_row_header;
        struct SectorHeader new_last_row_header;
        // Read last and new last
        readSectorHeaderByIndex(file, scheme->dataLastSector, &last_row_header);
        readSectorHeaderByIndex(file, allocated_sector, &new_last_row_header);
        // New links
        last_row_header.nextLogicalDataSector = allocated_sector;
        new_last_row_header.prevLogicalDataSector = scheme->dataLastSector;
        // Save in same place
        writeSectorHeaderByIndex(file, scheme->dataLastSector, &last_row_header);
        writeSectorHeaderByIndex(file, allocated_sector, &new_last_row_header);
    }
    // Change scheme signature
    scheme->dataLastSector = allocated_sector;
    writeDataToSector(file, scheme, sizeof(struct TableScheme), scheme->ownSector);
    return allocated_sector;
}

int deleteRowFromFile(FILE* file, uint32_t row_number, struct TableScheme* scheme) {
    uint32_t sector_ptr = scheme->dataFirstSector;
    uint32_t row_count = 1;
    struct SectorHeader header;
    readSectorHeaderByIndex(file, sector_ptr, &header);
    while (row_count != row_number) {
        readSectorHeaderByIndex(file, sector_ptr, &header);
        sector_ptr = header.nextLogicalDataSector;
        if (sector_ptr == HASH_NONE) return -1;
        row_count++;
    }
    // If deleting first or last, change signature
    if (sector_ptr == scheme->dataFirstSector) {
        scheme->dataFirstSector = header.nextLogicalDataSector;
        writeDataToSector(file, scheme, sizeof(struct TableScheme), scheme->ownSector);
    }
    if (sector_ptr == scheme->dataLastSector) {
        scheme->dataLastSector = header.prevLogicalDataSector;
        writeDataToSector(file, scheme, sizeof(struct TableScheme), scheme->ownSector);
    }

    // Change list links
    struct SectorHeader prev_logic_header;
    struct SectorHeader next_logic_header;
    readSectorHeaderByIndex(file, header.prevLogicalDataSector, &prev_logic_header);
    readSectorHeaderByIndex(file, header.nextLogicalDataSector, &next_logic_header);
    prev_logic_header.nextLogicalDataSector = header.nextLogicalDataSector;
    next_logic_header.prevSectorNumber = header.prevSectorNumber;
    writeSectorHeaderByIndex(file, header.prevLogicalDataSector, &prev_logic_header);
    writeSectorHeaderByIndex(file, header.nextLogicalDataSector, &next_logic_header);

    deallocateSector(file, sector_ptr);

    return 0;
}

int getRowByNumber(FILE* file, uint32_t row_number, struct TableScheme* scheme, union TableCellWithData* row) {
    uint32_t sector_ptr = scheme->dataFirstSector;
    uint32_t row_count = 1;

    struct SectorHeader header;
    while (row_count != row_number) {
        readSectorHeaderByIndex(file, sector_ptr, &header);
        sector_ptr = header.nextLogicalDataSector;
        if (sector_ptr == HASH_NONE) return -1;
        row_count++;
    }

    size_t row_size = sizeof(union TableCellWithData) * scheme->columnsCount;
    readDataFromSector(file, row, row_size, sector_ptr);

    return 0;
}

char * getRowsString(FILE * file, struct TableScheme* scheme) {
    int rowsCount = getRowCount(file, scheme);
    if (!rowsCount) {
        return "EMPTY TABLE!\n";
    }
    int columnsCount = scheme->columnsCount;
    enum CellType cell_type;

    struct HeaderCell columns[columnsCount];
    size_t colBuffSize = sizeof(struct HeaderCell) * columnsCount;
    readDataFromSector(file, &columns, colBuffSize, scheme->columnsInfoSector);

    union TableCellWithData **rows = getAllRows(file, scheme, rowsCount);
    DynamicBuffer buffer = {0};

    char * string;
    for (int i = 0; i < rowsCount; ++i) {
        string = "ROW;\n";
        buffer = addStringToBuffer(
            buffer, string
        );

        for (int t = 0; t < columnsCount; ++t) {
            cell_type = columns[t].meta.cell_type;
            string = getStringCellValue(file, cell_type, rows[i][t]);
            buffer = addStringToBuffer(
                buffer, string
            );
            buffer = addStringToBuffer(
                buffer, "\t string\n"
            );
        }
    }
    return buffer.data;
}

union TableCellWithData ** getAllRows(FILE * file, struct TableScheme* scheme, int rowsCount) {
    if (!rowsCount) {
        return NULL;
    }

    union TableCellWithData **rows = malloc(sizeof(union TableCellWithData *) * rowsCount);

    for (int i = 0; i < rowsCount; ++i) {
        rows[i] = malloc(sizeof(union TableCellWithData) * scheme->columnsCount);
        getRowByNumber(file, i + 1, scheme, rows[i]);
    }
    return rows;
}

int getRowCount(FILE * file, struct TableScheme* scheme) {
    uint32_t sector_ptr = scheme->dataFirstSector;
    if (scheme->dataFirstSector == HASH_NONE) {
        return 0;
    }
    uint32_t row_count = 1;

    struct SectorHeader header;
    while (sector_ptr != scheme->dataLastSector) {
        readSectorHeaderByIndex(file, sector_ptr, &header);
        if (header.isTaken) {
            row_count++;
        }
        sector_ptr = header.nextLogicalDataSector;
    }

    return row_count;
}

