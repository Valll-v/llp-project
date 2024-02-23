#include "../include/index.h"
#include "file.h"

struct TableIndexArray *allocateEmptyTableIndex() {
    struct TableIndexArray *index_array = malloc(sizeof(struct TableIndexArray));
    index_array->nextTableSector = HASH_NONE;
    for (int i = 0; i < MAX_TABLES_COUNT; i++) {
        index_array->tableMap[i].tableNameHash = HASH_NONE;
    }
    return index_array;
}

int addTableIndex(
        uint32_t indices_sector, FILE *file,
        const char *table_name, uint32_t data_sector
) {
    struct TableIndexArray* index_table = allocateEmptyTableIndex();
    readTableIndexFromSector(file, indices_sector, index_table);
    for (int i = 0; i < MAX_TABLES_COUNT; i++) {
        if (index_table->tableMap[i].tableNameHash == HASH_NONE) {
            uint32_t new_hash = hashStringDefault(table_name);
            index_table->tableMap[i].tableNameHash = new_hash;
            index_table->tableMap[i].schemaSector = data_sector;
            return writeTableIndexToSector(file, indices_sector, index_table);
        }
    }
    return -1;
}

int updateTableSectorLink(
        uint32_t indices_sector, FILE *file,
        const char *table_name, uint32_t data_sector
) {
    struct TableIndexArray* index_table = allocateEmptyTableIndex();
    readTableIndexFromSector(file, indices_sector, index_table);
    uint32_t table_hash = hashStringDefault(table_name);
    for (int i = 0; i < MAX_TABLES_COUNT; i++) {
        if (index_table->tableMap[i].tableNameHash == table_hash) {
            index_table->tableMap[i].schemaSector = data_sector;
            return writeTableIndexToSector(file, indices_sector, index_table);
        }
    }
    return -1;
}

int removeTableIndex(
        uint32_t indices_sector, FILE *file,
        const char *table_name
) {
    struct TableIndexArray* index_table = allocateEmptyTableIndex();
    readTableIndexFromSector(file, indices_sector, index_table);
    uint32_t table_hash = hashStringDefault(table_name);
    for (int i = 0; i < MAX_TABLES_COUNT; i++) {
        if (index_table->tableMap[i].tableNameHash == table_hash) {
            index_table->tableMap[i].tableNameHash = HASH_NONE;
            index_table->tableMap[i].schemaSector = HASH_NONE;
            return writeTableIndexToSector(file, indices_sector, index_table);
        }
    }
    return -1;
}

uint32_t findTableSector(
        uint32_t indices_sector, FILE *file,
        const char *table_name
) {
    struct TableIndexArray* index_table = allocateEmptyTableIndex();
    readTableIndexFromSector(file, indices_sector, index_table);
    uint32_t table_hash = hashStringDefault(table_name);
    for (int i = 0; i < MAX_TABLES_COUNT; i++) {
        if (index_table->tableMap[i].tableNameHash == table_hash) {
            return index_table->tableMap[i].schemaSector;
        }
    }
    return 0;
}
