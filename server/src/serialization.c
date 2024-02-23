#include "serialization.h"


Node * treeFromMessage(Message * message) {
    if (message == NULL) {
        return NULL;
    }
    if (message->content_case != MESSAGE__CONTENT_REQUEST) {
        return NULL;
    }
    Request * request = message->request;
    return treeFromRequest(request);
}


Node * treeFromRequest(Request * request) {
    if (request == NULL) {
        return NULL;
    }
    Queries * queries = request->queries;
    if (queries == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_QUERIES_LIST;
    Query ** queries_list = queries->queries;
    size_t n_queries = queries->n_queries;
    Node * node_copy = node;
    size_t pointer = 1;
    node_copy->data.QUERIES_LIST.query = treeFromQuery(queries_list[0]);
    for (int k = pointer; k < n_queries; ++k) {
        Node * next_node = createNode();
        next_node->type = NTOKEN_QUERIES_LIST;
        node_copy->data.QUERIES_LIST.next = next_node;
        node_copy = next_node;
        node_copy->data.QUERIES_LIST.query = treeFromQuery(queries_list[0]);
    }
    return node;
}


Node * treeFromQuery(Query * query) {
    if (query == NULL) {
        return NULL;
    }
    Node * node;
    switch (query->content_case) {
        case QUERY__CONTENT_SELECT_EXP:
            break;
        case QUERY__CONTENT_UPDATE_EXP:
            break;
        case QUERY__CONTENT_CREATE_EXP:
            break;
        case QUERY__CONTENT_DELETE_EXP:
            break;
        case QUERY__CONTENT_INSERT_EXP:
            break;
        case QUERY__CONTENT_DROP_EXP:
            node = treeFromDrop(query->drop_exp);
            break;
    }
    return node;
}


Node * treeFromDrop(DropExp * drop_exp) {
    if (drop_exp == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_DROP;
    node->data.DROP.table = treeFromTable(drop_exp->table);
    return node;
}


Node * treeFromTable(Table * table) {
    if (table == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_TABLE;
    node->data.TABLE.table = table->table;
    return node;
}


Node * valueFromProto(Value *protoValue) {
    Value *value = protoValue;
    if (protoValue == NULL) {
        return NULL;
    }
    Node *tree = createNode();
    if (tree == NULL) {
        return NULL;
    }
    switch (value->content_case) {
        case VALUE__CONTENT_FLOAT:
            printf("FLOAT!\n");
            printf("%f\n", protoValue->float_);
            tree->type = NTOKEN_FLOAT;
            tree->data.FLOAT.value = protoValue->float_;
            return tree;
        case VALUE__CONTENT_INT:
            printf("INT!\n");
            printf("%d\n", protoValue->int_);
            tree->type = NTOKEN_INT;
            tree->data.INT.value = protoValue->int_;
            return tree;
        case VALUE__CONTENT_STRING:
            printf("STRING!\n");
            printf("%s", protoValue->string);
            tree->type = NTOKEN_STRING;
            tree->data.STRING.value = protoValue->string;
            return tree;
        case VALUE__CONTENT_BOOL:
            printf("BOOL!\n");
            printf("%d", protoValue->bool_);
            tree->type = NTOKEN_BOOL;
            tree->data.BOOL.value = protoValue->bool_;
            return tree;
    }
    printf("NULL!\n");
    return NULL;
}
