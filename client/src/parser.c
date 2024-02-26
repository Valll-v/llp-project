#include "tree.h"
#include "parser.h"


void yyerror() {
    fprintf(stderr, "%d: Syntax Error.\n", yylineno);
}

Node *parseQuery(char * string) {
    YY_BUFFER_STATE buffer = yy_scan_string(string);
    yy_switch_to_buffer(buffer);
    Node *nodeRef = NULL;
    yyparse(&nodeRef);
    yy_delete_buffer(buffer);
    return nodeRef;
}