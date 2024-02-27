#include "input.h"


struct TableScheme * getTableList(FILE *);

char * CreateTable(FILE *, Node *);

Response * executeRequest(FILE *, Node *);

int tableTypeFromTree(Node *);

Response * makeResponse(char *);

char * DropTable(FILE *, Node *);

char * insertRow(FILE *, struct TableScheme*, Node *);

struct TableScheme getTable(FILE *, char *);

char * InsertInto(FILE *, Node *);
