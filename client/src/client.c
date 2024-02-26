#include "stdio.h"
#include "client.h"
#include "input.h"
#include "serialization.h"


Node * makeTree() {
    int s;
    DynamicBuffer buffer = {0};
    printf("Enter your query.\n");

    while ((s = getchar()) != 0) {
        if (s == '\\') {
            s = getchar();
            if (s == 's') {
                break;
            }
        } else {
            DynamicBufferPut(&buffer, (char) s);
        }
    }
    Node * tree = parseQuery(buffer.data);
    DynamicBufferFree(&buffer);
    if (tree == NULL) {
        printf("tree is NULL, fault!!! \n");
        freeNode(tree);
        return NULL;
    }
    return tree;
}

int sendMessage(int sockfd) {
    Node * tree = makeTree();

    Message message;
    message__init(&message);
    message.content_case = MESSAGE__CONTENT_REQUEST;
    message.request = makeRequestFromTree(tree);

    uint8_t pad[128];
    ProtobufCBufferSimple simple = PROTOBUF_C_BUFFER_SIMPLE_INIT(pad);
    ProtobufCBuffer *buffer = (ProtobufCBuffer *) &simple;
    size_t size = message__pack_to_buffer(&message, buffer);

    write(sockfd, &size, sizeof(size));
    write(sockfd, simple.data, size);

    PROTOBUF_C_BUFFER_SIMPLE_CLEAR(&simple);
    freeNode(tree);

    return 0;
}

void run_client(char* host, int port) {

    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

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
    servaddr.sin_addr.s_addr = inet_addr(host);
    servaddr.sin_port = htons(port);

    // connect the client socket to server socket
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr))
        != 0) {
        printf("connection with the server failed...\n");
        exit(0);
    }
    else
        printf("connected to the server..\n");

    while (1) {
        sendMessage(sockfd);
    }
    printf("END!!!!\n");
    close(sockfd);
}
