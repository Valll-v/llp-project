#include "client.h"

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Wrong number of arguments, expected <ip_address> <port> \n");
        return -1;
    }

    char *host = argv[1];
    int port = strtol(argv[2], NULL, 10);
    run_client(host, port);

    return 0;
}
