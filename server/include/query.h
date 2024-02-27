#include "input.h"


struct TableScheme * getTableList(FILE *);

char * CreateTable(FILE *, Node *);

DynamicBuffer addStringToBuffer(DynamicBuffer, char *);

Response * executeRequest(FILE *, Node *);

int tableTypeFromTree(Node *);

Response * makeResponse(char *);
