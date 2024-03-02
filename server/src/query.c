#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "table.h"
#include "tree.h"
#include "tree.pb-c.h"
#include "file.h"
#include "input.h"
#include "cell_utils.h"
#include "schema.h"

int getTableCount(FILE * database_file) {
    struct StaticFileHeader header;
    readStaticHeader(database_file, &header);
    int count = header.tableCount;
    return count;
}

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

struct TableScheme * getTable(FILE * database_file, char * table_name) {
    struct StaticFileHeader header;
    readStaticHeader(database_file, &header);
    int count = header.tableCount;
    if (!count) {
        return NULL;
    }

    struct TableScheme * table_list = getTableList(database_file);
    for (int i = 0; i < count; ++i) {
        if (strcmp(table_name, table_list[i].name) == 0) {
            return &table_list[i];
        }
    }
    return NULL;
}

bool bothLogic(int left, int right, Node * node) {
    switch (node->type) {
        case NTOKEN_LOGIC:
            switch (node->data.LOGIC.type) {
                case NTOKEN_OR:
                    return (right || left);
                case NTOKEN_AND:
                    return (right && left);
                case NTOKEN_NOT:
                    return (!left);
            }
        case NTOKEN_COMPARE:
            switch (node->data.COMPARE.type) {
                case NTOKEN_GEQ:
                    return (left >= right);
                case NTOKEN_LEQ:
                    return (left <= right);
                case NTOKEN_LESS:
                    return (left < right);
                case NTOKEN_GREATER:
                    return (left >= right);
                case NTOKEN_EQ:
                    return (left == right);
                case NTOKEN_NEQ:
                    return (left != right);
            }
    }
    return 0;
}

bool checkRowForWhere(FILE* file, union TableCellWithData* row, Node * logic_tree,
    int columnsCount, struct HeaderCell * columns
) {
    if (logic_tree == NULL) {
        return 1;
    }

    switch (logic_tree->type) {
        case NTOKEN_INT:
        case NTOKEN_FLOAT:
        case NTOKEN_BOOL:
        case NTOKEN_STRING:
        case NTOKEN_REFERENCE:
            return 1;
    }

    Node * left;
    Node * right;

    int left_bool_value = -1;
    int right_bool_value = -1;
    switch (logic_tree->type) {
        case NTOKEN_LOGIC:
            left = logic_tree->data.LOGIC.left;
            right = logic_tree->data.LOGIC.right;
            break;
        case NTOKEN_COMPARE:
            left = logic_tree->data.COMPARE.left;
            right = logic_tree->data.COMPARE.right;
            break;
    }

    switch (left->type) {
        case NTOKEN_LOGIC:
        case NTOKEN_COMPARE:
            left_bool_value = checkRowForWhere(file, row, left, columnsCount, columns);
    }
    switch (right->type) {
        case NTOKEN_LOGIC:
        case NTOKEN_COMPARE:
            right_bool_value = checkRowForWhere(file, row, right, columnsCount, columns);
    }

    if (left_bool_value > -1) {
        if (right_bool_value > -1) {
            return bothLogic(left_bool_value, right_bool_value, logic_tree);
        }
        else {
            switch (right->type) {
                case NTOKEN_INT:
                    return bothLogic(left_bool_value, right->data.INT.value, logic_tree);
                case NTOKEN_FLOAT:
                    return bothLogic(left_bool_value, (int) right->data.FLOAT.value, logic_tree);
                case NTOKEN_BOOL:
                    return bothLogic(left_bool_value, right->data.BOOL.value, logic_tree);
                case NTOKEN_STRING:
                case NTOKEN_REFERENCE:
                    return 0;
            }
        }
    }
    else {
        if (right_bool_value > -1) {
            switch (left->type) {
                case NTOKEN_INT:
                    return bothLogic(left->data.INT.value, right_bool_value, logic_tree);
                case NTOKEN_FLOAT:
                    return bothLogic((int) left->data.FLOAT.value, right_bool_value, logic_tree);
                case NTOKEN_BOOL:
                    return bothLogic(left->data.BOOL.value, right_bool_value, logic_tree);
                case NTOKEN_STRING:
                case NTOKEN_REFERENCE:
                    return 0;
            }
        }
        else {
            if (left->type != right->type) {
                if (left->type == NTOKEN_REFERENCE) {
                    char * columnName = left->data.REFERENCE.column->data.COLUMN.column;
                    int right_value;
                    printf("%d\n", right->data.INT.value);
                    switch (right->type) {
                        case NTOKEN_INT:
                            right_value = right->data.INT.value;
                            break;
                        case NTOKEN_FLOAT:
                            right_value = (int) right->data.FLOAT.value;
                            break;
                        case NTOKEN_BOOL:
                            right_value = (int) right->data.BOOL.value;
                            break;
                        case NTOKEN_STRING:
                            return 1;
                    }
                    for (int i = 0; i < columnsCount; ++i) {
                        if (strcmp(columnName, columns[i].column_name) == 0) {
                            printf("%d\n", row[i].intC.value);
                            int value_for_cmp;
                            switch (columns[i].meta.cell_type) {
                                case TABLE_TYPE_INT:
                                    value_for_cmp = row[i].intC.value;
                                    break;
                                case TABLE_TYPE_BIGINT:
                                    value_for_cmp = row[i].bigintC.value;
                                    break;
                                case TABLE_TYPE_FLOAT:
                                    value_for_cmp = (int) row[i].floatC.value;
                                    break;
                                case TABLE_TYPE_BOOL:
                                    value_for_cmp = (int) row[i].boolC.value;
                                    break;
                                case TABLE_TYPE_VARCHAR:
                                    return 1;
                            }
                            return bothLogic(value_for_cmp, right_value, logic_tree);
                        }
                    }
                }
                else if (right->type == NTOKEN_REFERENCE) {
                    char * columnName = right->data.REFERENCE.column->data.COLUMN.column;
                    int left_value;
                    switch (left->type) {
                        case NTOKEN_INT:
                            left_value = left->data.INT.value;
                            break;
                        case NTOKEN_FLOAT:
                            left_value = (int) left->data.FLOAT.value;
                            break;
                        case NTOKEN_BOOL:
                            left_value = (int) left->data.BOOL.value;
                            break;
                        case NTOKEN_STRING:
                            return 1;
                    }
                    for (int i = 0; i < columnsCount; ++i) {
                        if (strcmp(columnName, columns[i].column_name) == 0) {
                            int value_for_cmp;
                            switch (columns[i].meta.cell_type) {
                                case TABLE_TYPE_INT:
                                    value_for_cmp = row[i].intC.value;
                                    break;
                                case TABLE_TYPE_BIGINT:
                                    value_for_cmp = row[i].bigintC.value;
                                    break;
                                case TABLE_TYPE_FLOAT:
                                    value_for_cmp = (int) row[i].floatC.value;
                                    break;
                                case TABLE_TYPE_BOOL:
                                    value_for_cmp = (int) row[i].boolC.value;
                                    break;
                                case TABLE_TYPE_VARCHAR:
                                    return 1;
                            }
                            return bothLogic(left_value, value_for_cmp, logic_tree);
                        }
                    }
                }
                else {
                    return 0;
                }
            }
            else {
                switch (left->type) {
                    case NTOKEN_INT:
                        return bothLogic(left->data.INT.value, right->data.INT.value, logic_tree);
                    case NTOKEN_FLOAT:
                        return bothLogic((int) left->data.FLOAT.value, (int) right->data.FLOAT.value, logic_tree);
                    case NTOKEN_BOOL:
                        return bothLogic(left->data.BOOL.value, right->data.BOOL.value, logic_tree);
                    case NTOKEN_STRING:
                        return (strcmp(left->data.STRING.value, right->data.STRING.value) == 0);
                    case NTOKEN_REFERENCE:
                        char * columnNameLeft = left->data.REFERENCE.column->data.COLUMN.column;
                        char * columnNameRight = right->data.REFERENCE.column->data.COLUMN.column;
                        int value_for_cmp_left;
                        int value_for_cmp_right;
                        for (int i = 0; i < columnsCount; ++i) {
                            if (strcmp(columnNameLeft, columns[i].column_name) == 0) {
                                switch (columns[i].meta.cell_type) {
                                    case TABLE_TYPE_INT:
                                        value_for_cmp_left = row[i].intC.value;
                                        break;
                                    case TABLE_TYPE_BIGINT:
                                        value_for_cmp_left = row[i].bigintC.value;
                                        break;
                                    case TABLE_TYPE_FLOAT:
                                        value_for_cmp_left = (int) row[i].floatC.value;
                                        break;
                                    case TABLE_TYPE_BOOL:
                                        value_for_cmp_left = (int) row[i].boolC.value;
                                        break;
                                }
                            }
                            if (strcmp(columnNameRight, columns[i].column_name) == 0) {
                                switch (columns[i].meta.cell_type) {
                                    case TABLE_TYPE_INT:
                                        value_for_cmp_right = row[i].intC.value;
                                        break;
                                    case TABLE_TYPE_BIGINT:
                                        value_for_cmp_right = row[i].bigintC.value;
                                        break;
                                    case TABLE_TYPE_FLOAT:
                                        value_for_cmp_right = (int) row[i].floatC.value;
                                        break;
                                    case TABLE_TYPE_BOOL:
                                        value_for_cmp_right = (int) row[i].boolC.value;
                                        break;
                                }
                            }
                        }
                        return bothLogic(value_for_cmp_left, value_for_cmp_right, logic_tree);
                }
            }
        }
    }
}

char * getRowsString(FILE * file, Node * where, int columnsCount, struct HeaderCell * columns, union TableCellWithData **rows, int rowsCount) {
    enum CellType cell_type;
    DynamicBuffer buffer = {0};

    buffer = addStringToBuffer(
        buffer, "|"
    );

    int string_length = 0;
    char * string;
    char string_max[16] = "";

    for (int i = 0; i < columnsCount; i++) {
        buffer = addStringToBuffer(
            buffer, " "
        );

        string = columns[i].column_name;
        string_length = strlen(string);
        if (string_length > 15) {
            strncpy(string_max, string + 0, 15);
            buffer = addStringToBuffer(
                buffer, string_max
            );
            string_length = 15;
        } else {
            buffer = addStringToBuffer(
                buffer, string
            );
        }

        while (string_length < 16) {
            buffer = addStringToBuffer(
                buffer, " "
            );
            string_length++;
        }
        buffer = addStringToBuffer(
            buffer, "|"
        );
    }
    buffer = addStringToBuffer(
        buffer, "\n|"
    );

    for (int i = 0; i < rowsCount; ++i) {

        if (where && !checkRowForWhere(file, rows[i],
            where->data.WHERE.logic, columnsCount, columns)) {
            continue;
        }

        for (int t = 0; t < columnsCount; ++t) {
            cell_type = columns[t].meta.cell_type;
            string = getStringCellValue(file, cell_type, rows[i][t]);
            buffer = addStringToBuffer(
                buffer, " "
            );

            string_length = strlen(string);
            if (string_length > 15) {
                strncpy(string_max, string + 0, 15);
                buffer = addStringToBuffer(
                    buffer, string_max
                );
                string_length = 15;
            } else {
                buffer = addStringToBuffer(
                    buffer, string
                );
            }

            while (string_length < 16) {
                buffer = addStringToBuffer(
                    buffer, " "
                );
                string_length++;
            }
            buffer = addStringToBuffer(
                buffer, "|"
            );
        }
        buffer = addStringToBuffer(
            buffer, "\n|"
        );
    }
    return buffer.data;
}

char * DeleteFrom(FILE * database_file, Node * delete_tree) {
    if (delete_tree->type != NTOKEN_DELETE) {
        return "Invalid Tree!\n";
    }

    char * table_name = delete_tree->data.DELETE.table->data.TABLE.table;

    if (!isTableExists(database_file, table_name)) {
        return "Table does not exists!\n";
    }

    struct TableScheme * scheme = getTable(database_file, table_name);

    int rowsCount = getRowCount(database_file, scheme);
    if (!rowsCount) {
        return "EMPTY TABLE!\n";
    }

    Node * where = delete_tree->data.DELETE.where;

    union TableCellWithData * row = malloc(sizeof(union TableCellWithData) * scheme->columnsCount);
    int sum_deleted = 0;

    for (int i = rowsCount; i > 0; --i) {
        getRowByNumber(database_file, i, scheme, row);
        deleteRowFromFile(database_file, i, scheme);

        sum_deleted++;
    }

    DynamicBuffer buffer = {0};

    buffer = addStringToBuffer(
        buffer, "Deleted "
    );

    int length = snprintf( NULL, 0, "%d", sum_deleted );
    char* str = malloc( length + 1 );
    snprintf( str, length + 1, "%d", sum_deleted );

    buffer = addStringToBuffer(
        buffer, str
    );

    free(str);

    buffer = addStringToBuffer(
        buffer, " rows.\n"
    );
    return buffer.data;
}


struct HeaderCell * getColumnsDynamic(FILE * database_file, struct TableScheme * schemeJoin, int columnsCount, int columnsCountJoin) {
    struct HeaderCell columnsAfterJoin[columnsCount + columnsCountJoin];
    size_t colBuffSize = sizeof(struct HeaderCell) * columnsCountJoin;
    readDataFromSector(database_file, &columnsAfterJoin, colBuffSize, schemeJoin->columnsInfoSector);
    struct HeaderCell * columns = malloc(sizeof(struct HeaderCell) * (columnsCount + columnsCountJoin));
    for (int i = 0; i < columnsCount; i++) {
        columns[i] = columnsAfterJoin[i];
    }
    return columns;
}


Node * whereToJoin(Node * where, Node * join) {
    Node * new_where = createNode();
    new_where->type = NTOKEN_WHERE;

    Node * logic_right = createNode();
    logic_right->type = NTOKEN_COMPARE;
    logic_right->data.COMPARE.type = NTOKEN_EQ;
    logic_right->data.COMPARE.left = join->data.JOIN.left;
    logic_right->data.COMPARE.right = join->data.JOIN.right;

    if (where != NULL) {
        Node * logic = createNode();
        logic->type = NTOKEN_LOGIC;
        logic->data.LOGIC.type = NTOKEN_AND;
        logic->data.LOGIC.left = where->data.WHERE.logic;
        logic->data.LOGIC.right = logic_right;
        new_where->data.WHERE.logic = logic;
    } else {
        new_where->data.WHERE.logic = logic_right;
    }
    printTree(logic_right, 0);
    return new_where;
}


char * SelectFrom(FILE * database_file, Node * select_tree) {
    if (select_tree->type != NTOKEN_SELECT) {
        return "Invalid Tree!\n";
    }

    char * table_name = select_tree->data.SELECT.table->data.TABLE.table;

    if (!isTableExists(database_file, table_name)) {
        return "Table does not exists!\n";
    }

    struct TableScheme * scheme = getTable(database_file, table_name);

    int rowsCount = getRowCount(database_file, scheme);
    if (!rowsCount) {
        return "EMPTY TABLE!\n";
    }
    int columnsCount = scheme->columnsCount;

    struct HeaderCell columnsStatic[columnsCount];
    size_t colBuffSize = sizeof(struct HeaderCell) * columnsCount;
    readDataFromSector(database_file, &columnsStatic, colBuffSize, scheme->columnsInfoSector);

    union TableCellWithData **rows = getAllRows(database_file, scheme, rowsCount);

    Node * where = select_tree->data.SELECT.where;
    Node * join_list = select_tree->data.SELECT.join_list;

    struct HeaderCell * columns = malloc(colBuffSize);
    for (int i = 0; i < columnsCount; i++) {
        columns[i] = columnsStatic[i];
    }

    if (join_list != NULL) {
        int rowsCountJoin = 0;
        int columnsCountJoin = 0;
        struct HeaderCell * columnsAfterJoin;
        union TableCellWithData **rowsJoin;
        union TableCellWithData **rowsAfterJoin;
        char * tableNameJoin;
        struct TableScheme * schemeJoin;
        while (join_list != NULL) {
            tableNameJoin = join_list->data.JOIN_LIST.join->data.JOIN.table->data.TABLE.table;
            if (!isTableExists(database_file, tableNameJoin)) {
                return "Table from join does not exists!\n";
            }

            schemeJoin = getTable(database_file, tableNameJoin);
            columnsCountJoin = schemeJoin->columnsCount;
            rowsCountJoin = getRowCount(database_file, schemeJoin);

            columnsAfterJoin = getColumnsDynamic(database_file, schemeJoin, columnsCount, columnsCountJoin);
            for (int i = 0; i < columnsCount; i++) {
                columnsAfterJoin[columnsCountJoin + i] = columns[i];
            }
            columns = columnsAfterJoin;
            columnsCount += columnsCountJoin;

            if (rowsCountJoin == 0) {
                return "EMPTY JOIN TABLE!\n";
            }
            rowsJoin = getAllRows(database_file, schemeJoin, rowsCountJoin);
            rowsAfterJoin = malloc(sizeof(union TableCellWithData *) * (rowsCount * rowsCountJoin));
            for (int i = 0; i < rowsCountJoin; i++) {
                for (int t = 0; t < rowsCount; t++) {
                    rowsAfterJoin[i * rowsCount + t] = malloc(sizeof(union TableCellWithData) * columnsCount);
                    for (int j = 0; j < columnsCountJoin; j++) {
                        rowsAfterJoin[i * rowsCount + t][j] = rowsJoin[i][j];
                    }
                    for (int j = 0; j < (columnsCount - columnsCountJoin); j++) {
                        rowsAfterJoin[i * rowsCount + t][j + columnsCountJoin] = rows[t][j];
                    }
                }
            }

            rows = rowsAfterJoin;
            rowsCount *= rowsCountJoin;

            where = whereToJoin(where, join_list->data.JOIN_LIST.join);

            if (join_list->data.JOIN_LIST.next == NULL) {
                break;
            }
            join_list = join_list->data.JOIN_LIST.next;
        }
    }

    char * result = getRowsString(database_file, where, columnsCount, columns, rows, rowsCount);

    return result;
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

char * insertRow(FILE * file, struct TableScheme* scheme, Node * node) {
    if (node->type != NTOKEN_VALUES_LIST) {
        return "Invalid tree!\n";
    }
    int columnsCount = scheme->columnsCount;
    enum CellType cell_type;

    struct HeaderCell columns[columnsCount];
    size_t colBuffSize = sizeof(struct HeaderCell) * columnsCount;
    readDataFromSector(file, &columns, colBuffSize, scheme->columnsInfoSector);

    union TableCellWithData table_row[scheme->columnsCount];
    int nodeCounter = 0;

    Node * valueNode;
    while (node->data.VALUES_LIST.value != NULL) {
        valueNode = node->data.VALUES_LIST.value;
        cell_type = columns[nodeCounter].meta.cell_type;
        if (nodeCounter >= columnsCount) {
            return "Too more args\n";
        }

        switch (cell_type) {
            case TABLE_TYPE_INT:
            case TABLE_TYPE_BIGINT:
                if (valueNode->type != NTOKEN_INT) {
                    return "Invalid INT value\n";
                }
                rowSetCellValue(
                    file, scheme, table_row, nodeCounter + 1,
                    cell_type, &valueNode->data.INT.value
                );
                break;
            case TABLE_TYPE_FLOAT:
                if (valueNode->type != NTOKEN_FLOAT) {
                    return "Invalid FLOAT value\n";
                }
                rowSetCellValue(
                    file, scheme, table_row, nodeCounter + 1,
                    cell_type, &valueNode->data.FLOAT.value
                );
                break;
            case TABLE_TYPE_VARCHAR:
                if (valueNode->type != NTOKEN_STRING) {
                    return "Invalid STRING value\n";
                }
                rowSetCellValue(
                    file, scheme, table_row, nodeCounter + 1,
                    cell_type, valueNode->data.STRING.value
                );
                break;
            case TABLE_TYPE_BOOL:
                if (valueNode->type != NTOKEN_BOOL) {
                    return "Invalid BOOL value\n";
                }
                rowSetCellValue(
                    file, scheme, table_row, nodeCounter + 1,
                    cell_type, &valueNode->data.BOOL.value
                );
                break;
        }
        nodeCounter++;
        if (node->data.VALUES_LIST.next == NULL) {
            break;
        }
        node = node->data.VALUES_LIST.next;
    }

    if (nodeCounter != columnsCount) {
        return "Too few args\n";
    }
    addRowToFile(file, scheme, table_row);

    return "INSERTED\n";
}

char * InsertInto(FILE * file, Node * insert_tree) {
    if (insert_tree->type != NTOKEN_INSERT) {
        return "Invalid Tree!\n";
    }

    Node * values_list = insert_tree->data.INSERT.values_list;
    char * table_name = insert_tree->data.INSERT.table->data.TABLE.table;

    if (!isTableExists(file, table_name)) {
        return "Table does not exists!\n";
    }

    struct TableScheme * scheme = getTable(file, table_name);
    if (scheme == NULL) {
        return "Table does not exists!\n";
    }
    return insertRow(file, scheme, values_list);
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

char * TableList(FILE * database_file, Node * tree) {
    if (tree->type != TABLE_LIST) {
        return "Invalid Tree!\n";
    }
    DynamicBuffer buffer = {0};

    int table_count = getTableCount(database_file);
    if (!table_count) {
        return "Table count: 0.\n";
    }
    buffer = addStringToBuffer(
        buffer, "Table count: "
    );

    int x = getTableCount(database_file);
    int length = snprintf( NULL, 0, "%d", x );
    char* str = malloc( length + 1 );
    snprintf( str, length + 1, "%d", x );
    buffer = addStringToBuffer(
        buffer, str
    );
    buffer = addStringToBuffer(
        buffer, "\n\n"
    );
    free(str);

    struct TableScheme * table_list = getTableList(database_file);

    struct TableScheme table;
    for (int i = 0; i < table_count; ++i) {
        table = table_list[i];
        buffer = addStringToBuffer(
            buffer, "Table name: "
        );
        buffer = addStringToBuffer(
            buffer, table.name
        );
        buffer = addStringToBuffer(
            buffer, "\n"
        );
    }

    free(table_list);
    return buffer.data;
}

Response * executeRequest(FILE * database_file, Node * tree) {
    if (tree == NULL || tree->type != NTOKEN_QUERIES_LIST) {
        return makeResponse("Invalid Tree!\n");
    }

    DynamicBuffer buffer = {0};
    struct TableScheme * table_list;

    while (tree->data.QUERIES_LIST.query != NULL) {
        char * string;
        Node * query = tree->data.QUERIES_LIST.query;
        switch (query->type) {
            case NTOKEN_CREATE:
                string = CreateTable(database_file, query);
                buffer = addStringToBuffer(
                    buffer, string
                );

                break;
            case NTOKEN_DELETE:
                string = DeleteFrom(database_file, query);
                buffer = addStringToBuffer(
                    buffer, string
                );
                break;
            case NTOKEN_INSERT:
                string = InsertInto(database_file, query);
                buffer = addStringToBuffer(
                    buffer, string
                );
                break;
            case NTOKEN_DROP:
                string = DropTable(database_file, query);
                buffer = addStringToBuffer(
                    buffer, string
                );
                break;
            case NTOKEN_SELECT:
                string = SelectFrom(database_file, query);
                buffer = addStringToBuffer(
                    buffer, string
                );
                break;
            case NTOKEN_UPDATE:
                string = CreateTable(database_file, query);
                buffer = addStringToBuffer(
                    buffer, string
                );
                break;
            case TABLE_LIST:
                string = TableList(database_file, query);
                buffer = addStringToBuffer(
                    buffer, string
                );
                break;
        }
        if (tree->data.QUERIES_LIST.next == NULL) {
            break;
        }
        tree = tree->data.QUERIES_LIST.next;
    }

    Response * resp = makeResponse(buffer.data);
    return resp;
}
