
#ifndef __TCP__NET__SOCKET__H
#define __TCP__NET__SOCKET__H
#include <arpa/inet.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

extern int tcp_init(const char *ip, int port);
extern int tcp_accept(int sfd);
extern int tcp_connect(const char *ip, int port);
extern void signalhandler(void);
#endif
