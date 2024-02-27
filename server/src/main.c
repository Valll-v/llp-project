#include <stdio.h>
#include "server.h"
#include "schema.h"
#include "cell_utils.h"
#include "query.h"


int main() {

    FILE* database_file = fopen("database.db", "wb+");

    createFileAndInitEmptyStructure(database_file);

    struct TableScheme table1scheme;
    initTableScheme(database_file, "table1", 3, &table1scheme);
    schemaSetColumn(database_file, &table1scheme, 1, TABLE_TYPE_INT, "id");
    schemaSetColumn(database_file, &table1scheme, 2, TABLE_TYPE_BOOL, "value");
    schemaSetColumn(database_file, &table1scheme, 3, TABLE_TYPE_VARCHAR, "string");

    Node * node = createNode();
    node->type = NTOKEN_FIELD_LIST;

    for (int i = 2; i < 11; i = i + 2) {
        insertRow(database_file, &table1scheme, node);
    }

    char * string = getRowsString(database_file, &table1scheme);

    printf("%s\n", string);

    fclose(database_file);

    return 0;
}
