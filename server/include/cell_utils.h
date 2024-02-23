#ifndef CELL_UTILS_H
#define CELL_UTILS_H

#include <string.h>
#include "./table.h"
#include "./file.h"

int rowSetCellValue(
        FILE *file, const struct TableScheme *scheme, union TableCellWithData *rows,
        int col_num, enum CellType cell_type, void *value
);

void printCellValue(FILE *file, enum CellType cell_type, void *value);

#endif //CELL_UTILS_H
