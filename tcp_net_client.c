
#include "tcp_net_socket.h"

int main(int argc, char const *argv[]) {
  if (argc < 3) {
    printf("usage:./clienttcp ip port\n");
    exit(-1);
  }

  while (1) {
    char buf[512] = {0};
    printf("> ");
    gets(buf);
    int sfd = tcp_connect(argv[1], atoi(argv[2]));
    send(sfd, buf, strlen(buf), 0);
    if (!strcmp(buf, "exit")) {
      close(sfd);
      break;
    }
    recv(sfd, buf, sizeof(buf), 0);
    printf("[Server]:%s\n", buf);
    close(sfd);
  }
  return 0;
}
