#include "tree.h"
#include "tree.pb-c.h"

Node * treeFromMessage(Message *);

Node * treeFromRequest(Request *);

Node * treeFromQuery(Query *);

Node * treeFromDrop(DropExp *);

Node * treeFromTable(Table *);

Node * valueFromProto(Value *);