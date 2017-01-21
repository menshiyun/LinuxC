
#include "tcp_net_socket.h"

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("usage:./servertcp ip port\n");
    exit(-1);
  }
  // signalhandler();
  int sfd = tcp_init(argv[1], atoi(argv[2]));

  int cfd = tcp_accept(sfd);

  while (1) {
    // int cfd = tcp_accept(sfd);
    char buf[512] = {0};
    if (recv(cfd, buf, sizeof(buf), 0) == -1) {
      perror("recv");
      close(cfd);
      close(sfd);
      exit(-1);
    }
    if (!strcmp(buf, "exit"))
      break;
    printf("[Client]:%s\n", buf);
    if (send(cfd, buf, strlen(buf), 0) == -1) {
      perror("send");
      close(cfd);
      close(sfd);
      exit(-1);
    }
    // close(cfd);
  }
  close(cfd);
  close(sfd);
  return 0;
}
