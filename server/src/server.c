#include "server.h"


Node * receiveTree(int connfd) {
    size_t size = 0;
    read(connfd, &size, sizeof(size));

    uint8_t* data = malloc(size);
    if (data == NULL) {
        return NULL;
    }

    read(connfd, data, size);

    Message * message = message__unpack(NULL, size, data);
    free(data);

    Node *tree = createNode();
    tree = treeFromMessage(message);
    return tree;
}


int run_server() {
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    connfd = accept(sockfd, (SA*)&cli, &len);
    if (connfd < 0) {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");

    Node * tree;
    for (;;) {
        tree = receiveTree(connfd);
        if (tree == NULL) {
            continue;
        }
        printTree(tree, 0);
        freeNode(tree);
    }
    close(connfd);
    close(sockfd);
}