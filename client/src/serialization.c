#include <stdlib.h>

#include "tree.h"
#include "serialization.h"


Request * makeRequestFromTree(Node * tree) {
    Request * request = malloc(sizeof(Request));
    request__init(request);
    request->queries = makeQueriesFromTree(tree);
    return request;
}


Queries * makeQueriesFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->type != NTOKEN_QUERIES_LIST) {
        printf("Invalid QUERY!");
        printTree(tree, 0);
        return NULL;
    }
    Queries * queries = malloc(sizeof(Queries));
    queries__init(queries);
    int count = 0;
    Node * tree_cp = tree;
    while (tree_cp->data.QUERIES_LIST.query != NULL) {
        count++;
        if (tree_cp->data.QUERIES_LIST.next == NULL) {
            break;
        }
        tree_cp = tree_cp->data.QUERIES_LIST.next;
    }
    size_t n_queries = count;
    queries->n_queries = n_queries;
    Query ** queries_list = malloc(sizeof(Query) * count);
    queries->queries = queries_list;
    size_t pointer = 0;
    while (tree->data.QUERIES_LIST.query != NULL) {
        Node * query_tree = tree->data.QUERIES_LIST.query;
        Query * query = makeQueryFromTree(query_tree);
        queries_list[pointer] = query;
        if (tree->data.QUERIES_LIST.next == NULL) {
            break;
        }
        tree = tree->data.QUERIES_LIST.next;
        pointer++;
    }
    return queries;
}


Query * makeQueryFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    Query * query = malloc(sizeof(Query));
    query__init(query);
    switch (tree->type) {
        case NTOKEN_SELECT:
            query->content_case = QUERY__CONTENT_SELECT_EXP;
            printf("SELECT\n");
            break;
        case NTOKEN_UPDATE:
            query->content_case = QUERY__CONTENT_UPDATE_EXP;
            printf("UPDATE\n");
            break;
        case NTOKEN_DELETE:
            query->content_case = QUERY__CONTENT_DELETE_EXP;
            printf("DELETE\n");
            break;
        case NTOKEN_CREATE:
            query->content_case = QUERY__CONTENT_CREATE_EXP;
            printf("CREATE\n");
            break;
        case NTOKEN_INSERT:
            query->content_case = QUERY__CONTENT_INSERT_EXP;
            printf("INSERT\n");
            break;
        case NTOKEN_DROP:
            query->content_case = QUERY__CONTENT_DROP_EXP;
            query->drop_exp = makeDropFromTree(tree);
            printf("DROP\n");
            break;
    }
    return query;
}


DropExp * makeDropFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    DropExp * drop_exp = malloc(sizeof(DropExp));
    drop_exp__init(drop_exp);
    drop_exp->table = makeTableFromTree(tree->data.DROP.table);
    return drop_exp;
}

Table * makeTableFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    Table * table = malloc(sizeof(Table));
    table__init(table);
    table->table = tree->data.TABLE.table;
    return table;
}

Value * makeValueFromQuery(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    Value *data = malloc(sizeof(Value));
    value__init(data);
    switch (tree->type) {
        case NTOKEN_INT:
            data->content_case = VALUE__CONTENT_INT;
            data->int_ = tree->data.INT.value;
            break;
        case NTOKEN_FLOAT:
            data->content_case = VALUE__CONTENT_FLOAT;
            data->int_ = tree->data.INT.value;
            break;
        case NTOKEN_STRING:
            data->content_case = VALUE__CONTENT_STRING;
            data->int_ = tree->data.INT.value;
            break;
        case NTOKEN_BOOL:
            data->content_case = VALUE__CONTENT_BOOL;
            data->int_ = tree->data.INT.value;
            break;
    }
    return data;
}
