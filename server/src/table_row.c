#include "../include/schema.h"

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
        sector_ptr = header.nextSectorNumber;
        if (sector_ptr == HASH_NONE) return -1;
        row_count++;
    }

    size_t row_size = sizeof(union TableCellWithData) * scheme->columnsCount;
    readDataFromSector(file, row, row_size, sector_ptr);

    return 0;
}


