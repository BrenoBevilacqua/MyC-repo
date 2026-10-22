#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXSIZE 2048

int main(int argc, char *argv[]){
  char buf[2048];
  int len = sizeof(struct sockaddr_in);
  int sockfd, cn, msg;
  
  
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    puts("Socket error!");
    exit(1);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[2]));
  inet_pton(AF_INET, argv[1], &addr.sin_addr);
  
  if((cn = connect(sockfd, (struct sockaddr *)&addr, len)) < 0){
    puts("Connection error!");
    exit(1);
  }
  printf("Connection established with %s\n", argv[1]);
  while((msg = read(sockfd, buf, MAXSIZE ))){
    buf[msg] = 0;
    if(fputs(buf, stdout) == EOF){
      puts("fputs error");
      exit(1);
    }
  }
  if(msg < 0){
    puts("Read error");
    exit(1);
  }
  exit(1);
  
}
