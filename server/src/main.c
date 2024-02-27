#include <stdio.h>
#include "server.h"
#include "schema.h"
#include "cell_utils.h"
#include "query.h"


int main() {

    FILE* database_file = fopen("database.db", "wb+");

    createFileAndInitEmptyStructure(database_file);

    run_server(database_file);

    fclose(database_file);

    return 0;
}
