#include <stdio.h>
#include "table.h"
#include "tree.h"
#include "tree.pb-c.h"
#include "file.h"
#include "input.h"
#include "cell_utils.h"
#include "schema.h"


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
    for (int i = 0; i < count; ++i) {
        index = index_table->tableMap[i];
        printf("%d\n", i);
        printf("%u\n", index.tableNameHash);
        if (index.tableNameHash == HASH_NONE) {
            count++;
            continue;
        }
        schemaSector = index.schemaSector;
        readDataFromSector(database_file, &(table_list[i]), sizeof(struct TableScheme), schemaSector);
    }
    return table_list;
}


int isTableExists(FILE * database_file, char * table_name) {
    struct StaticFileHeader header;
    readStaticHeader(database_file, &header);
    int count = header.tableCount;
    if (!count) {
        return 0;
    }

    struct TableScheme * table_list = getTableList(database_file);
    for (int i = 0; i < count; ++i) {
        if (strcmp(table_name, table_list[i].name) == 0) {
            return 1;
        }
    }
    return 0;
}

Response * makeResponse(char * response_text) {
    Response * response = malloc(sizeof(Response));
    response__init(response);
    response->string = response_text;
    return response;
}

int tableTypeFromTree(Node * node) {
    switch (node->data.FIELD.type) {
        case NTOKEN_INTEGER_FIELD:
            return TABLE_TYPE_INT;
        case NTOKEN_FLOAT_FIELD:
            return TABLE_TYPE_FLOAT;
        case NTOKEN_STRING_FIELD:
            return TABLE_TYPE_VARCHAR;
        case NTOKEN_BOOL_FIELD:
            return TABLE_TYPE_BOOL;
    }
    return TABLE_TYPE_EMPTY;
}

int insertRow(FILE * file, struct TableScheme* scheme, Node * node) {
    int id = 1;
    bool val = true;
    char* str = "test_string";
    union TableCellWithData table_row[scheme->columnsCount];

    rowSetCellValue(file, scheme, table_row, 1, TABLE_TYPE_INT, &id);
    rowSetCellValue(file, scheme, table_row, 2, TABLE_TYPE_BOOL, &val);
    rowSetCellValue(file, scheme, table_row, 3, TABLE_TYPE_VARCHAR, str);

    addRowToFile(file, scheme, table_row);

    return 0;
}

char * CreateTable(FILE * database_file, Node * create_tree) {
    if (create_tree->type != NTOKEN_CREATE) {
        return "Invalid Tree!\n";
    }

    Node * field_list = create_tree->data.CREATE.field_list;
    char * table_name = create_tree->data.CREATE.table->data.TABLE.table;

    if (isTableExists(database_file, table_name)) {
        return "Table already exists!\n";
    }

    int count = 1;
    Node * field_list_cp = field_list;
    while (field_list_cp->data.FIELD_LIST.next != NULL) {
        count++;
        field_list_cp = field_list_cp->data.FIELD_LIST.next;
    }

    struct TableScheme table_scheme;

    initTableScheme(database_file, table_name, count, &table_scheme);

    count = 1;
    schemaSetColumn(
        database_file,
        &table_scheme,
        count,
        tableTypeFromTree(field_list->data.FIELD_LIST.field),
        field_list->data.FIELD_LIST.field->data.FIELD.column->data.COLUMN.column
    );
    while (field_list->data.FIELD_LIST.next != NULL) {
        count++;
        field_list = field_list->data.FIELD_LIST.next;
        schemaSetColumn(
            database_file,
            &table_scheme,
            count,
            tableTypeFromTree(field_list->data.FIELD_LIST.field),
            field_list->data.FIELD_LIST.field->data.FIELD.column->data.COLUMN.column
        );
    }

    return "Created\n";
}

char * DropTable(FILE * database_file, Node * drop_tree) {
    if (drop_tree->type != NTOKEN_DROP) {
        return "Invalid Tree!\n";
    }

    char * table_name = drop_tree->data.DROP.table->data.TABLE.table;
    return table_name;
}

Response * executeRequest(FILE * database_file, Node * tree) {
    if (tree == NULL || tree->type != NTOKEN_QUERIES_LIST) {
        return makeResponse("Invalid Tree!\n");
    }

    DynamicBuffer buffer = {0};

    while (tree->data.QUERIES_LIST.query != NULL) {
        char * string;
        Node * query = tree->data.QUERIES_LIST.query;
        switch (query->type) {
            case NTOKEN_CREATE:
                string = CreateTable(database_file, query);
                break;
            case NTOKEN_DELETE:
                string = CreateTable(database_file, query);
                break;
            case NTOKEN_INSERT:
                string = CreateTable(database_file, query);
                break;
            case NTOKEN_DROP:
                string = DropTable(database_file, query);
                break;
            case NTOKEN_SELECT:
                string = CreateTable(database_file, query);
                break;
            case NTOKEN_UPDATE:
                string = CreateTable(database_file, query);
                break;
        }
        buffer = addStringToBuffer(
            buffer, string
        );
        if (tree->data.QUERIES_LIST.next == NULL) {
            break;
        }
        tree = tree->data.QUERIES_LIST.next;
    }

    Response * resp = makeResponse(buffer.data);
    return resp;
}
