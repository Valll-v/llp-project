#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()

#include "serialization.h"

#define PORT 1338
#define SA struct sockaddr

int run_server(FILE*);

Node * receiveTree(int);
