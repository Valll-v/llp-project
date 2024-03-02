#include "input.h"
#include "schema.h"


struct TableScheme * getTableList(FILE *);

char * CreateTable(FILE *, Node *);

Response * executeRequest(FILE *, Node *);

int tableTypeFromTree(Node *);

Response * makeResponse(char *);

char * DropTable(FILE *, Node *);

char * insertRow(FILE *, struct TableScheme*, Node *);

struct TableScheme getTable(FILE *, char *);

char * InsertInto(FILE *, Node *);

char * TableList(FILE *, Node *);

char * SelectFrom(FILE *, Node *);

bool checkRowForWhere(FILE*, union TableCellWithData*, Node *, int, struct HeaderCell *);

bool bothLogic(int, int, Node *);

char * getRowsString(FILE *, Node *, int, struct HeaderCell *, union TableCellWithData **, int);
