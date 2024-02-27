#ifndef CELL_H
#define CELL_H

#include <stdbool.h>
#include <stdint.h>

#include "./consts.h"

enum CellType {
    TABLE_TYPE_INT = 0,
    TABLE_TYPE_BOOL,
    TABLE_TYPE_VARCHAR,
    TABLE_TYPE_BIGINT,
    TABLE_TYPE_FLOAT, // числа с плавающей точкой
    TABLE_TYPE_EMPTY,
};

struct TableCell {
    enum CellType cell_type;
};

struct HeaderCell {
    struct TableCell meta;
    char column_name[COLUMN_MAX_NAME_LENGTH];
};

struct BigIntTableCell {
    struct TableCell meta;
    int64_t value;
};

struct BoolTableCell {
    struct TableCell meta;
    bool value;
};

struct FloatTableCell {
    struct TableCell meta;
    float value;
};

struct IntTableCell {
    struct TableCell meta;
    int32_t value;
};

struct StringTableCell {
    struct TableCell meta;
    uint32_t string_size;
    uint32_t string_value_sector;
};

#endif //CELL_H
