#include "client.h"
#include "serialization.h"


int sendMessage(int sockfd, Message * message) {
    uint8_t pad[128];
    ProtobufCBufferSimple simple = PROTOBUF_C_BUFFER_SIMPLE_INIT(pad);
    ProtobufCBuffer *buffer = (ProtobufCBuffer *) &simple;
    printf("%ld\n", sizeof(message));
    size_t size = message__pack_to_buffer(message, buffer);
    printf("boba\n");

    write(sockfd, &size, sizeof(size));
    printf("boba\n");
    write(sockfd, simple.data, size);
    printf("boba\n");
    PROTOBUF_C_BUFFER_SIMPLE_CLEAR(&simple);
    printf("boba\n");
    return 0;
}


void run_client(Node* tree, char* host, int port) {

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

    Message message;
    message__init(&message);
    message.content_case = MESSAGE__CONTENT_REQUEST;
    message.request = makeRequestFromTree(tree);

    sendMessage(sockfd, &message);
    printTree(tree, 0);
    close(sockfd);
}