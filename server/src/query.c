#include <stdio.h>
#include "table.h"
#include "file.h"


struct TableScheme * getTableList(FILE * database_file) {
    struct StaticFileHeader header;
    readStaticHeader(database_file, &header);
    int count = header.tableCount;

    struct TableScheme * table_list = malloc(sizeof(struct TableScheme) * count);

    if (table_list == NULL) {
        return NULL;
    }

    struct TableIndexArray* index_table = allocateEmptyTableIndex();
    readTableIndexFromSector(database_file, header.tableIndicesSector, index_table);

    struct TableIndex index;
    uint32_t schemaSector;
    for (int i; i < count; ++i) {
        index = index_table->tableMap[i];
        schemaSector = index.schemaSector;
        printf("%d\n", index.schemaSector);
        readDataFromSector(database_file, &(table_list[i]), sizeof(struct TableScheme), schemaSector);
    }
    printf("BEBRA\n");
    return table_list;
}