#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXSIZE 2048

int Connect(int sock, struct sockaddr* pla, int len);
  
int main(){
  char buf[2048];
  int len = sizeof(struct sockaddr_in);
  int sockfd, cn, msg;
  
  
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
    puts("Socket error!");
    exit(1);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(13);
  if( (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr)) <= 0){
    puts("Addressing error");
  }
  
  Connect(sockfd, (struct sockaddr*)&addr, len);

  printf("Connection established with 127.0.0.1\n");
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

int Connect(int sock, struct sockaddr* pla, int len){
  int n;
  
  if( (n = connect(sock, (struct sockaddr *)&pla, len)) < 0 ){
    puts("connection error: ");
    printf("%d\n", n);
    exit(1);
  }
  return n;
}






