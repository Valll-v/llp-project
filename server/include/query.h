#include "input.h"


struct TableScheme * getTableList(FILE *);

char * CreateTable(FILE *, Node *);

Response * executeRequest(FILE *, Node *);

int tableTypeFromTree(Node *);

Response * makeResponse(char *);

char * DropTable(FILE *, Node *);

int insertRow(FILE *, struct TableScheme*, Node *);
