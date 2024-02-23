#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()

#include "tree.h"
#include "tree.pb-c.h"
#include "parser.h"

#define DEFAULT_PORT 8000
#define SA struct sockaddr

int sendMessage(int sockfd, Message *);

void run_client(Node*, char*, int);
