#ifndef TABLE_INDEX_UTILS_H
#define TABLE_INDEX_UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "./table.h"
#include "./consts.h"
#include "./sector.h"

int readTableIndexFromSector(FILE *file, uint32_t sectorNumber, struct TableIndexArray *tableIndex);
int writeTableIndexToSector(FILE *file, uint32_t sectorNumber, struct TableIndexArray *tableIndex);
struct TableIndexArray *allocateEmptyTableIndex();
int addTableIndex(uint32_t indices_sector, FILE *file, const char *table_name, uint32_t data_sector);
int updateTableSectorLink(uint32_t indices_sector, FILE *file, const char *table_name, uint32_t data_sector);
int removeTableIndex(uint32_t indices_sector, FILE *file, const char *table_name);
uint32_t findTableSector(uint32_t indices_sector, FILE *file, const char *table_name);

#endif //TABLE_INDEX_UTILS_H
