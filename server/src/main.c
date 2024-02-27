#include <stdio.h>
#include "server.h"
#include "schema.h"
#include "cell_utils.h"
#include "query.h"


int main() {

    FILE* database_file = fopen("database.db", "ab+");

    createFileAndInitEmptyStructure(database_file);

    struct TableScheme table1scheme;
    initTableScheme(database_file, "table1", 3, &table1scheme);
    schemaSetColumn(database_file, &table1scheme, 1, TABLE_TYPE_INT, "id");
    schemaSetColumn(database_file, &table1scheme, 2, TABLE_TYPE_BOOL, "value");
    schemaSetColumn(database_file, &table1scheme, 3, TABLE_TYPE_VARCHAR, "string");
    struct TableScheme table2scheme;
    initTableScheme(database_file, "table2", 3, &table2scheme);
    struct TableScheme table3scheme;
    initTableScheme(database_file, "table3", 3, &table3scheme);
    struct TableScheme table4scheme;
    initTableScheme(database_file, "table4", 3, &table4scheme);
    struct TableScheme table5scheme;
    initTableScheme(database_file, "table5", 3, &table5scheme);

    run_server(database_file);

    fclose(database_file);

    return 0;
}
