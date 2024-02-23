#ifndef TABLE_H
#define TABLE_H

#include <stdint.h>
#include <stddef.h>
#include "./cell.h"

union TableCellWithData {
    struct BigIntTableCell bigintC;
    struct BoolTableCell boolC;
    struct FloatTableCell floatC;
    struct IntTableCell intC;
    struct StringTableCell stringC;
};

struct SectorHeader {
    bool isTaken;
    size_t sectorsTakenInRow;
    uint16_t prevSectorNumber;
    uint16_t nextSectorNumber;

    uint16_t prevLogicalDataSector;
    uint16_t nextLogicalDataSector;
};

union SectorData {
    struct SectorHeader status;
    unsigned char data[SECTOR_SIZE];
};

struct StaticFileHeader {
    uint32_t tableCount;
    uint32_t tableIndicesSector;
    uint32_t lastSector;
    uint32_t firstAtEndFree;
};

struct TableScheme {
    char name[TABLE_MAX_NAME_LENGTH];
    int columnsCount;
    uint32_t columnsInfoSector;
    uint32_t dataFirstSector;
    uint32_t dataLastSector;
    uint32_t ownSector;
};

struct TableIndex {
    uint32_t tableNameHash;
    uint32_t schemaSector;
};

struct TableIndexArray {
    uint32_t nextTableSector;
    struct TableIndex tableMap[MAX_TABLES_COUNT];
};

#endif //TABLE_H
