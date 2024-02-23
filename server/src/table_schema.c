#include "../include/schema.h"
#include "file.h"

int initTableScheme(
        FILE* file, const char *tableName, int columnCount, struct TableScheme* emptyScheme
) {
    if (columnCount > TABLE_MAX_COLUMNS) return -1;
    if (strlen(tableName) > TABLE_MAX_NAME_LENGTH) return -1;

    size_t columnHeadersBuffSize = sizeof(struct HeaderCell) * columnCount;
    size_t sectorsForTableSchema = calculateSectorsNeeded(sizeof(struct TableScheme));
    size_t sectorsForColumnHeaders = calculateSectorsNeeded(columnHeadersBuffSize);
    uint32_t tableSchemeSector = allocateSector(file, sectorsForTableSchema);
    uint32_t tableHeadersSector = allocateSector(file, sectorsForColumnHeaders);

    strcpy(emptyScheme->name, tableName);
    emptyScheme->columnsCount = columnCount;
    emptyScheme->columnsInfoSector = tableHeadersSector;
    emptyScheme->ownSector = tableSchemeSector;
    emptyScheme->dataFirstSector = HASH_NONE;
    emptyScheme->dataLastSector = HASH_NONE;

    struct HeaderCell* emptyColumns = malloc(columnHeadersBuffSize);
    struct HeaderCell empty_cell = {
            .column_name = "NaN", .meta = TABLE_TYPE_EMPTY
    };
    for (int i = 0; i < columnCount; i++) {
        emptyColumns[i] = empty_cell;
    }

    writeDataToSector(file, emptyScheme, sizeof(struct TableScheme), tableSchemeSector);
    writeDataToSector(file, emptyColumns, columnHeadersBuffSize, tableHeadersSector);
    free(emptyColumns);

    struct StaticFileHeader header;
    readStaticHeader(file, &header);
    addTableIndex(header.tableIndicesSector, file, tableName, tableSchemeSector);
    return 0;
}

int schemaSetColumn(
        FILE* file, struct TableScheme* scheme, int colNum, enum CellType cellType, const char* columnName
) {
    if (strlen(columnName) > COLUMN_MAX_NAME_LENGTH) return -1;
    if (colNum > scheme->columnsCount) return -1;

    struct HeaderCell newCell;
    struct HeaderCell columns[scheme->columnsCount];
    size_t colBuffSize = sizeof(struct HeaderCell) * scheme->columnsCount;
    readDataFromSector(file, &columns, colBuffSize, scheme->columnsInfoSector);

    strcpy(newCell.column_name, columnName);
    newCell.meta.cell_type = cellType;
    columns[colNum - 1] = newCell;

    writeDataToSector(file, &columns, colBuffSize, scheme->columnsInfoSector);
    return 0;
}
