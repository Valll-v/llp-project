typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern YY_BUFFER_STATE yy_scan_string(char *str);

extern int yylineno;  /* Для отладки */

extern int yyparse(Node **result);

extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

void yyerror();

void yy_switch_to_buffer(YY_BUFFER_STATE new_buffer);

Node *parseQuery(char * string);
