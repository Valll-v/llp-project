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
            query->select_exp = makeSelectFromTree(tree);
            printf("SELECT\n");
            break;
        case NTOKEN_UPDATE:
            query->content_case = QUERY__CONTENT_UPDATE_EXP;
            query->update_exp = makeUpdateFromTree(tree);
            printf("UPDATE\n");
            break;
        case NTOKEN_DELETE:
            printf("DELETE\n");
            query->content_case = QUERY__CONTENT_DELETE_EXP;
            query->delete_exp = makeDeleteFromTree(tree);
            break;
        case NTOKEN_CREATE:
            query->content_case = QUERY__CONTENT_CREATE_EXP;
            query->create_exp = makeCreateFromTree(tree);
            printf("CREATE\n");
            break;
        case NTOKEN_INSERT:
            query->content_case = QUERY__CONTENT_INSERT_EXP;
            query->insert_exp = makeInsertFromTree(tree);
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

UpdateExp * makeUpdateFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    UpdateExp * update_exp = malloc(sizeof(UpdateExp));
    update_exp__init(update_exp);
    update_exp->table = makeTableFromTree(tree->data.UPDATE.table);
    update_exp->where = makeWhereFromTree(tree->data.UPDATE.where);
    update_exp->set_list = makeSetListFromTree(tree->data.UPDATE.set_list);
    return update_exp;
}

SetList * makeSetListFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    SetList * set_list = malloc(sizeof(SetList));
    set_list__init(set_list);
    int count = 0;
    Node * tree_cp = tree;
    while (tree_cp->data.SET_LIST.set != NULL) {
        count++;
        if (tree_cp->data.SET_LIST.next == NULL) {
            break;
        }
        tree_cp = tree_cp->data.SET_LIST.next;
    }
    set_list->n_set_list = count;
    Set ** sets = malloc(sizeof(Set) * count);
    set_list->set_list = sets;
    size_t pointer = 0;
    while (tree->data.SET_LIST.set != NULL) {
        Node * set_tree = tree->data.SET_LIST.set;
        Set * set = makeSetFromTree(set_tree);
        sets[pointer] = set;
        if (tree->data.SET_LIST.next == NULL) {
            break;
        }
        tree = tree->data.SET_LIST.next;
        pointer++;
    }
    return set_list;
}

Set * makeSetFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    Set * set = malloc(sizeof(Set));
    set__init(set);
    set->column = makeColumnFromTree(tree->data.SET.column);
    set->value = makeValueFromQuery(tree->data.SET.value);
    return set;
}

InsertExp * makeInsertFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    InsertExp * insert_exp = malloc(sizeof(InsertExp));
    insert_exp__init(insert_exp);
    insert_exp->table = makeTableFromTree(tree->data.INSERT.table);
    insert_exp->values_list = makeValuesListFromTree(tree->data.INSERT.values_list);
    return insert_exp;
}

ValuesList * makeValuesListFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    ValuesList * values_list = malloc(sizeof(ValuesList));
    values_list__init(values_list);
    int count = 0;
    Node * tree_cp = tree;
    while (tree_cp->data.VALUES_LIST.value != NULL) {
        count++;
        if (tree_cp->data.VALUES_LIST.next == NULL) {
            break;
        }
        tree_cp = tree_cp->data.VALUES_LIST.next;
    }
    values_list->n_values_list = count;
    Value ** values = malloc(sizeof(Value) * count);
    values_list->values_list = values;
    size_t pointer = 0;
    while (tree->data.VALUES_LIST.value != NULL) {
        Node * value_tree = tree->data.VALUES_LIST.value;
        Value * value = makeValueFromQuery(value_tree);
        values[pointer] = value;
        if (tree->data.VALUES_LIST.next == NULL) {
            break;
        }
        tree = tree->data.VALUES_LIST.next;
        pointer++;
    }
    return values_list;
}

CreateExp * makeCreateFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    CreateExp * create_exp = malloc(sizeof(CreateExp));
    create_exp__init(create_exp);
    create_exp->table = makeTableFromTree(tree->data.CREATE.table);
    create_exp->field_list = makeFieldListFromTree(tree->data.CREATE.field_list);
    return create_exp;
}


FieldList * makeFieldListFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    FieldList * field_list = malloc(sizeof(FieldList));
    field_list__init(field_list);
    int count = 0;
    Node * tree_cp = tree;
    while (tree_cp->data.FIELD_LIST.field != NULL) {
        count++;
        if (tree_cp->data.FIELD_LIST.next == NULL) {
            break;
        }
        tree_cp = tree_cp->data.FIELD_LIST.next;
    }
    field_list->n_field = count;
    Field ** fields = malloc(sizeof(Field) * count);
    field_list->field = fields;
    size_t pointer = 0;
    while (tree->data.FIELD_LIST.field != NULL) {
        Node * field_tree = tree->data.FIELD_LIST.field;
        Field * field = makeFieldFromTree(field_tree);
        fields[pointer] = field;
        if (tree->data.FIELD_LIST.next == NULL) {
            break;
        }
        tree = tree->data.FIELD_LIST.next;
        pointer++;
    }
    return field_list;
}


Field * makeFieldFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    Field * field = malloc(sizeof(Field));
    field__init(field);
    field->column = makeColumnFromTree(tree->data.FIELD.column);
    field->field_type = tree->data.FIELD.type;
    return field;
}


DeleteExp * makeDeleteFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    DeleteExp * delete_exp = malloc(sizeof(DeleteExp));
    delete_exp__init(delete_exp);
    delete_exp->table = makeTableFromTree(tree->data.DELETE.table);
    delete_exp->where = makeWhereFromTree(tree->data.DELETE.where);
    return delete_exp;
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

SelectExp * makeSelectFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    SelectExp * select_exp = malloc(sizeof(SelectExp));
    select_exp__init(select_exp);
    select_exp->table = makeTableFromTree(tree->data.SELECT.table);
    select_exp->reference_list = makeReferenceListFromTree(tree->data.SELECT.reference);
    select_exp->where = makeWhereFromTree(tree->data.SELECT.where);
    return select_exp;
}

Where * makeWhereFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    Where * where = malloc(sizeof(Where));
    where__init(where);
    where->exp = makeExpFromTree(tree->data.WHERE.logic);
    return where;
}

LogicExp * makeLogicListFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    LogicExp * logic = malloc(sizeof(LogicExp));
    logic_exp__init(logic);
    logic->logic = tree->data.LOGIC.type;
    logic->left = makeExpFromTree(tree->data.LOGIC.left);
    logic->right = makeExpFromTree(tree->data.LOGIC.right);
    return logic;
}

Exp * makeExpFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    Exp * exp = malloc(sizeof(Exp));
    exp__init(exp);
    switch (tree->type) {
        case NTOKEN_INT:
        case NTOKEN_FLOAT:
        case NTOKEN_BOOL:
        case NTOKEN_STRING:
            exp->content_case = EXP__CONTENT_VALUE;
            exp->value = makeValueFromQuery(tree);
            break;
        case NTOKEN_LOGIC:
            exp->content_case = EXP__CONTENT_LOGIC_EXP;
            exp->logic_exp = makeLogicListFromTree(tree);
            break;
        case NTOKEN_REFERENCE:
            exp->content_case = EXP__CONTENT_REFERENCE;
            exp->reference = makeReferenceFromTree(tree);
            break;
        case NTOKEN_COMPARE:
            exp->content_case = EXP__CONTENT_COMPARE_EXP;
            exp->compare_exp = makeCompareFromTree(tree);
            break;
    }
    return exp;
}

CompareExp * makeCompareFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    CompareExp * compare_exp = malloc(sizeof(CompareExp));
    compare_exp__init(compare_exp);
    compare_exp->compare = tree->data.COMPARE.type;
    compare_exp->left = makeExpFromTree(tree->data.COMPARE.left);
    compare_exp->right = makeExpFromTree(tree->data.COMPARE.right);
    return compare_exp;
}

ReferenceList * makeReferenceListFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    ReferenceList * reference_list = malloc(sizeof(ReferenceList));
    reference_list__init(reference_list);
    int count = 0;
    Node * tree_cp = tree;
    while (tree_cp->data.REFERENCE_LIST.reference != NULL) {
        count++;
        if (tree_cp->data.REFERENCE_LIST.next == NULL) {
            break;
        }
        tree_cp = tree_cp->data.REFERENCE_LIST.next;
    }
    size_t n_reference = count;
    reference_list->n_reference = n_reference;
    reference_list->reference = malloc(sizeof(Reference) * count);
    size_t pointer = 0;
    while (tree->data.REFERENCE_LIST.reference != NULL) {
        Reference * reference = makeReferenceFromTree(tree->data.REFERENCE_LIST.reference);
        reference_list->reference[pointer] = reference;
        if (tree->data.REFERENCE_LIST.next == NULL) {
            break;
        }
        tree = tree->data.REFERENCE_LIST.next;
        pointer++;
    }
    return reference_list;
}

Reference * makeReferenceFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    Reference * reference = malloc(sizeof(Reference));
    reference__init(reference);
    reference->table = makeTableFromTree(tree->data.REFERENCE.table);
    reference->column = makeColumnFromTree(tree->data.REFERENCE.column);
    return reference;
}

Column * makeColumnFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    Column * column = malloc(sizeof(Column));
    column__init(column);
    column->column = tree->data.COLUMN.column;
    return column;
}

Table * makeTableFromTree(Node * tree) {
    if (tree == NULL) {
        return NULL;
    }
    Table * table = malloc(sizeof(Table));
    table__init(table);
    tree->data;
    tree->data.TABLE;
    tree->data.TABLE.table;
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
            data->float_ = tree->data.FLOAT.value;
            break;
        case NTOKEN_STRING:
            data->content_case = VALUE__CONTENT_STRING;
            data->string = tree->data.STRING.value;
            break;
        case NTOKEN_BOOL:
            data->content_case = VALUE__CONTENT_BOOL;
            data->bool_ = tree->data.BOOL.value;
            break;
    }
    return data;
}
