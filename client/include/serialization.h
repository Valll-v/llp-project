#include "tree.pb-c.h"

Queries * makeQueriesFromTree(Node *);

Query * makeQueryFromTree(Node *);

Request * makeRequestFromTree(Node *);

Value * makeValueFromQuery(Node *);

SelectExp * makeSelectFromTree(Node *);

ReferenceList * makeReferenceListFromTree(Node *);

CompareExp * makeCompareFromTree(Node *);

DeleteExp * makeDeleteFromTree(Node *);

Column * makeColumnFromTree(Node *);

Where * makeWhereFromTree(Node *);

LogicExp * makeLogicListFromTree(Node *);

Reference * makeReferenceFromTree(Node *);

DropExp * makeDropFromTree(Node *);

Table * makeTableFromTree(Node *);

Exp * makeExpFromTree(Node *);

CreateExp * makeCreateFromTree(Node *);

FieldList * makeFieldListFromTree(Node *);

Field * makeFieldFromTree(Node *);
