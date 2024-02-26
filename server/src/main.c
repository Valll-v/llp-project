#include <stdio.h>
#include "server.h"
#include "schema.h"
#include "cell_utils.h"
#include "query.h"


const char* db_file_name = "database.db";


int main() {

    FILE* database_file = fopen(db_file_name, "wb+");

    createFileAndInitEmptyStructure(database_file);
    struct StaticFileHeader header;
    readStaticHeader(database_file, &header);

    struct TableScheme table1scheme;
    initTableScheme(database_file, "table1", 3, &table1scheme);
    struct TableScheme table2scheme;
    initTableScheme(database_file, "table2", 3, &table2scheme);
    struct TableScheme table3scheme;
    initTableScheme(database_file, "table3", 3, &table3scheme);
    struct TableScheme table4scheme;
    initTableScheme(database_file, "table4", 3, &table4scheme);
    struct TableScheme table5scheme;
    initTableScheme(database_file, "table5", 3, &table5scheme);

    readStaticHeader(database_file, &header);
    printf("%d\n", header.lastSector);

    struct TableScheme * table_list = getTableList(database_file);

    printf("%s\n", table_list[1].name);

    fclose(database_file);

    return 0;
}
