#include <stdio.h>
#include "server.h"
#include "schema.h"
#include "cell_utils.h"
#include "query.h"


int main() {

    FILE* database_file = fopen("database.db", "rb+");

    if (database_file == NULL) {
        database_file = fopen("database.db", "wsb+");
        createFileAndInitEmptyStructure(database_file);
    }

    run_server(database_file);

    fclose(database_file);

    return 0;
}
