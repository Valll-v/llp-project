#ifndef LAB1LLP_TABLE_SCHEMA_UTILS_H
#define LAB1LLP_TABLE_SCHEMA_UTILS_H

#include <string.h>
#include <stdlib.h>
#include "./table.h"
#include "./sector.h"
#include "./consts.h"
#include "./index.h"

int initTableScheme(FILE* file, const char *tableName, int columnCount, struct TableScheme* emptyScheme);
int schemaSetColumn(FILE* file, struct TableScheme* scheme, int colNum, enum CellType cellType, const char* columnName);

size_t addRowToFile(FILE* file, struct TableScheme* scheme, union TableCellWithData *row);
int deleteRowFromFile(FILE* file, uint32_t row_number, struct TableScheme* scheme);
int getRowByNumber(FILE* file, uint32_t row_number, struct TableScheme* scheme, union TableCellWithData* row);
int getRowCount(FILE *, struct TableScheme *);
union TableCellWithData ** getAllRows(FILE *, struct TableScheme *, int);

#endif //LAB1LLP_TABLE_SCHEMA_UTILS_H
