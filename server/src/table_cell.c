#include "../include/cell_utils.h"

int rowSetCellValue(
        FILE *file, const struct TableScheme *scheme, union TableCellWithData *rows, int col_num,
        enum CellType cell_type, void *value
) {
    if (col_num > scheme->columnsCount) return -1;
    int col = col_num - 1;

    switch (cell_type) {
        case TABLE_TYPE_INT:
            rows[col].intC.meta.cell_type = cell_type;
            rows[col].intC.value = *(int *) value;
            break;
        case TABLE_TYPE_BIGINT:
            rows[col].bigintC.meta.cell_type = cell_type;
            rows[col].bigintC.value = *(int64_t *) value;
            break;
        case TABLE_TYPE_VARCHAR:
            rows[col].stringC.meta.cell_type = cell_type;
            size_t str_size = strlen((char *) value);
            uint32_t sector = writeStringToSector(file, (char *) value);
            rows[col].stringC.string_size = str_size;
            rows[col].stringC.string_value_sector = sector;
            break;
        case TABLE_TYPE_FLOAT:
            rows[col].floatC.meta.cell_type = cell_type;
            rows[col].floatC.value = *(float *) value;
            break;
        case TABLE_TYPE_BOOL:
            rows[col].boolC.meta.cell_type = cell_type;
            rows[col].boolC.value = *(bool *) value;
            break;
        case TABLE_TYPE_EMPTY:
            break;
    }
    return 0;
}

void printCellValue(FILE *file, enum CellType cell_type, void *value) {
    union TableCellWithData cell = *(union TableCellWithData *) value;
    switch (cell_type) {
        case TABLE_TYPE_INT:
        case TABLE_TYPE_BIGINT:
            printf("%d", cell.intC.value);
            break;
        case TABLE_TYPE_VARCHAR: {
            struct StringTableCell val = cell.stringC;
            printStringFromSector(file, val.string_value_sector, val.string_size);
            break;
        }
        case TABLE_TYPE_FLOAT:
            printf("%.2f", cell.floatC.value);
            break;
        case TABLE_TYPE_BOOL:
            printf(cell.boolC.value ? "true" : "false");
            break;
        case TABLE_TYPE_EMPTY:
            printf("NaN");
            break;
    }
}
