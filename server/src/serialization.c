#include <stdio.h>


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
        node_copy->data.QUERIES_LIST.query = treeFromQuery(queries_list[k]);
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
            node = treeFromSelect(query->select_exp);
            break;
        case QUERY__CONTENT_UPDATE_EXP:
            node = treeFromUpdate(query->update_exp);
            break;
        case QUERY__CONTENT_CREATE_EXP:
            node = treeFromCreate(query->create_exp);
            break;
        case QUERY__CONTENT_DELETE_EXP:
            node = treeFromDelete(query->delete_exp);
            break;
        case QUERY__CONTENT_INSERT_EXP:
            node = treeFromInsert(query->insert_exp);
            break;
        case QUERY__CONTENT_DROP_EXP:
            node = treeFromDrop(query->drop_exp);
            break;
    }
    return node;
}

Node * treeFromInsert(InsertExp * insert_exp) {
    if (insert_exp == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_INSERT;
    node->data.INSERT.table = treeFromTable(insert_exp->table);
    node->data.INSERT.values_list = treeFromValuesList(insert_exp->values_list);
    return node;
}

Node * treeFromValuesList(ValuesList * values_list) {
    if (values_list == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_VALUES_LIST;
    Value ** values = values_list->values_list;
    size_t n_values_list = values_list->n_values_list;
    Node * node_copy = node;
    size_t pointer = 1;
    node_copy->data.VALUES_LIST.value = valueFromProto(values[0]);
    for (int k = pointer; k < n_values_list; ++k) {
        Node * next_node = createNode();
        next_node->type = NTOKEN_VALUES_LIST;
        node_copy->data.VALUES_LIST.next = next_node;
        node_copy = next_node;
        node_copy->data.VALUES_LIST.value = valueFromProto(values[k]);
    }
    return node;
}

Node * treeFromUpdate(UpdateExp * update_exp) {
    if (update_exp == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_UPDATE;
    node->data.UPDATE.table = treeFromTable(update_exp->table);
    node->data.UPDATE.where = treeFromWhere(update_exp->where);
    node->data.UPDATE.set_list = treeFromSetList(update_exp->set_list);
    return node;
}

Node * treeFromSetList(SetList * set_list) {
    if (set_list == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_SET_LIST;
    Set ** sets = set_list->set_list;
    size_t n_set_list = set_list->n_set_list;
    Node * node_copy = node;
    size_t pointer = 1;
    node_copy->data.SET_LIST.set = treeFromSet(sets[0]);
    for (int k = pointer; k < n_set_list; ++k) {
        Node * next_node = createNode();
        next_node->type = NTOKEN_SET_LIST;
        node_copy->data.SET_LIST.next = next_node;
        node_copy = next_node;
        node_copy->data.SET_LIST.set = treeFromSet(sets[k]);
    }
    return node;
}

Node * treeFromSet(Set * set) {
    if (set == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_SET;
    node->data.SET.column = treeFromColumn(set->column);
    node->data.SET.value = valueFromProto(set->value);
    return node;
}

Node * treeFromCreate(CreateExp * create_exp) {
    if (create_exp == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_CREATE;
    node->data.CREATE.table = treeFromTable(create_exp->table);
    node->data.CREATE.field_list = treeFromFieldList(create_exp->field_list);
    return node;
}

Node * treeFromFieldList(FieldList * field_list) {
    if (field_list == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_FIELD_LIST;
    Field ** fields = field_list->field;
    size_t n_field = field_list->n_field;
    Node * node_copy = node;
    size_t pointer = 1;
    node_copy->data.FIELD_LIST.field = treeFromField(fields[0]);
    for (int k = pointer; k < n_field; ++k) {
        Node * next_node = createNode();
        next_node->type = NTOKEN_FIELD_LIST;
        node_copy->data.FIELD_LIST.next = next_node;
        node_copy = next_node;
        node_copy->data.FIELD_LIST.field = treeFromField(fields[k]);
    }
    return node;
}

Node * treeFromField(Field * field) {
    if (field == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_FIELD;
    node->data.FIELD.column = treeFromColumn(field->column);
    node->data.FIELD.type = field->field_type;
    return node;
}

Node * treeFromDelete(DeleteExp * delete_exp) {
    if (delete_exp == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_DELETE;
    node->data.DELETE.table = treeFromTable(delete_exp->table);
    node->data.DELETE.where = treeFromWhere(delete_exp->where);
    return node;
}

Node * treeFromSelect(SelectExp * select_exp) {
    if (select_exp == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_SELECT;
    node->data.SELECT.table = treeFromTable(select_exp->table);
    node->data.SELECT.reference = treeFromReferenceList(select_exp->reference_list);
    node->data.SELECT.where = treeFromWhere(select_exp->where);
    node->data.SELECT.join_list = treeFromJoinList(select_exp->join_list);
    return node;
}

Node * treeFromJoinList(JoinList * join_list) {
    if (join_list == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_JOIN_LIST;
    Join ** joins = join_list->join;
    size_t n_join = join_list->n_join;
    Node * node_copy = node;
    size_t pointer = 1;
    node_copy->data.JOIN_LIST.join = treeFromJoin(joins[0]);
    for (int k = pointer; k < n_join; ++k) {
        Node * next_node = createNode();
        next_node->type = NTOKEN_JOIN_LIST;
        node_copy->data.JOIN_LIST.next = next_node;
        node_copy = next_node;
        node_copy->data.JOIN_LIST.join = treeFromJoin(joins[k]);
    }
    return node;
}

Node * treeFromJoin(Join * join) {
    if (join == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_JOIN;
    node->data.JOIN.table = treeFromTable(join->table);
    node->data.JOIN.left = treeFromReference(join->left);
    node->data.JOIN.right = treeFromReference(join->right);
    return node;
}

Node * treeFromWhere(Where * where) {
    if (where == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_WHERE;
    node->data.WHERE.logic = treeFromExp(where->exp);
    return node;
}

Node * treeFromLogic(LogicExp * logic) {
    if (logic == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_LOGIC;
    node->data.LOGIC.type = logic->logic;
    node->data.LOGIC.left = treeFromExp(logic->left);
    node->data.LOGIC.right = treeFromExp(logic->right);
    return node;
}

Node * treeFromExp(Exp * exp) {
    if (exp == NULL) {
        return NULL;
    }
    switch (exp->content_case) {
        case EXP__CONTENT_VALUE:
            return valueFromProto(exp->value);
        case EXP__CONTENT_LOGIC_EXP:
            return treeFromLogic(exp->logic_exp);
        case EXP__CONTENT_REFERENCE:
            return treeFromReference(exp->reference);
        case EXP__CONTENT_COMPARE_EXP:
            return treeFromCompare(exp->compare_exp);
    }
    return NULL;
}

Node * treeFromCompare(CompareExp * exp) {
    if (exp == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_COMPARE;
    node->data.COMPARE.type = exp->compare;
    node->data.COMPARE.left = treeFromExp(exp->left);
    node->data.COMPARE.right = treeFromExp(exp->right);
    return node;
}

Node * treeFromReferenceList(ReferenceList * reference_list) {
    if (reference_list == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_REFERENCE_LIST;
    Reference ** references = reference_list->reference;
    size_t n_reference = reference_list->n_reference;
    Node * node_copy = node;
    size_t pointer = 1;
    node_copy->data.REFERENCE_LIST.reference = treeFromReference(references[0]);
    for (int k = pointer; k < n_reference; ++k) {
        Node * next_node = createNode();
        next_node->type = NTOKEN_REFERENCE_LIST;
        node_copy->data.REFERENCE_LIST.next = next_node;
        node_copy = next_node;
        node_copy->data.REFERENCE_LIST.reference = treeFromReference(references[k]);
    }
    return node;
}


Node * treeFromReference(Reference * reference) {
    if (reference == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_REFERENCE;
    node->data.REFERENCE.table = treeFromTable(reference->table);
    node->data.REFERENCE.column = treeFromColumn(reference->column);
    return node;
}


Node * treeFromColumn(Column * column) {
    if (column == NULL) {
        return NULL;
    }
    Node * node = createNode();
    node->type = NTOKEN_COLUMN;
    node->data.COLUMN.column = column->column;
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
            tree->type = NTOKEN_FLOAT;
            tree->data.FLOAT.value = protoValue->float_;
            return tree;
        case VALUE__CONTENT_INT:
            tree->type = NTOKEN_INT;
            tree->data.INT.value = protoValue->int_;
            return tree;
        case VALUE__CONTENT_STRING:
            tree->type = NTOKEN_STRING;
            tree->data.STRING.value = protoValue->string;
            return tree;
        case VALUE__CONTENT_BOOL:
            tree->type = NTOKEN_BOOL;
            tree->data.BOOL.value = protoValue->bool_;
            return tree;
    }
    printf("NULL!\n");
    return NULL;
}
