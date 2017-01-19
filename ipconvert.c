#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>

int main(int argc, char const *argv[]) {
  char ip[] = "192.168.0.101";
  struct in_addr myaddr;

  int iRet = inet_aton(ip, &myaddr);
  printf("%x\n", myaddr.s_addr);

  printf("%x\n", inet_addr(ip));

  iRet = inet_pton(AF_INET, ip, &myaddr);
  printf("%x\n", myaddr.s_addr);

  myaddr.s_addr = 0xac100ac4;

  printf("%s\n", inet_ntoa(myaddr));

  inet_ntop(AF_INET, &myaddr, ip, 16);
  puts(ip);

  return 0;
}
