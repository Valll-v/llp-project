#include "stdio.h"
#include "client.h"
#include "serialization.h"

int main(int argc, char* argv[]) {
    FILE *f = NULL;
    if (argc < 3) {
        printf("Wrong number of arguments, expected <ip_address> <port> \n");
        return -1;
    } else if (argc == 3) {
        f = stdin;
    } else {
        char* filename = argv[3];
        f = fopen(filename, "r");
        if (f == NULL) {
            printf("Can't read file: %s \n", filename);
            return -1;
        }
    }

    char *host = argv[1];
    int port = strtol(argv[2], NULL, DEFAULT_PORT);

    printf("File has been read! Enter your query, if you using stdin.\n");

    Node *tree = parseQuery(f);
    if (tree == NULL) {
        printf("tree is NULL, fault!!! \n");
    } else {
        run_client(tree, "127.0.0.1", 1337);
    }

    freeNode(tree);
    fclose(f);
    return 0;
}
