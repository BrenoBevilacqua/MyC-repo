#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
  void* val;
  struct Node* next;
}node;

int main(){
  int a = 3;
  char b = 'b';
  void* elements[] = {0};

  printf("%d %d", sizeof(a), sizeof(b));
  
}
