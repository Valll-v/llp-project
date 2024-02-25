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

Node * treeFromUpdate(UpdateExp * );

Node * treeFromSetList(SetList *);

Node * treeFromSet(Set *);

Node * treeFromWhere(Where *);

Node * treeFromField(Field *);

Node * treeFromFieldList(FieldList *);

Node * treeFromCreate(CreateExp *);

Node * treeFromInsert(InsertExp *);

Node * treeFromValuesList(ValuesList *);

Node * treeFromJoin(Join *);

Node * treeFromJoinList(JoinList *);
