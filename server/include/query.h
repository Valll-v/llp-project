struct TableScheme * getTableList(FILE *);

Response * CreateTable(FILE *, Node *);

int tableTypeFromTree(Node *);

Response * makeResponse(char *);