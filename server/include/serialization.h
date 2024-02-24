#include "tree.h"
#include "tree.pb-c.h"

Node * treeFromMessage(Message *);

Node * treeFromRequest(Request *);

Node * treeFromQuery(Query *);

Node * treeFromDrop(DropExp *);

Node * treeFromTable(Table *);

Node * treeFromSelect(SelectExp *);

Node * treeFromDelete(DeleteExp *);

Node * valueFromProto(Value *);

Node * treeFromColumn(Column *);

Node * treeFromReference(Reference *);

Node * treeFromReferenceList(ReferenceList *);

Node * treeFromCompare(CompareExp *);

Node * treeFromExp(Exp *);

Node * treeFromLogic(LogicExp *);

Node * treeFromWhere(Where *);
