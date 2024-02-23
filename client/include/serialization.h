#include "tree.pb-c.h"

Queries * makeQueriesFromTree(Node *);

Query * makeQueryFromTree(Node *);

Request * makeRequestFromTree(Node *);

Value * makeValueFromQuery(Node *);

DropExp * makeDropFromTree(Node *);

Table * makeTableFromTree(Node *);