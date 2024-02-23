#include "tree.h"
#include "parser.h"


void yyerror() {
    fprintf(stderr, "%d: Syntax Error.\n", yylineno);
}

Node *parseQuery(FILE *f) {
    yyin = f;
    Node *nodeRef = NULL;
    yyparse(&nodeRef);
    return nodeRef;
}