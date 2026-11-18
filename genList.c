#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAXSIZE 20

int getline(int data[]);

int main(){
  int elements[20];
  int c;

  while ( (c = getline(elements)) > 0){
    for( int i=0; i < MAXSIZE && elements[i] != '\n'; i++){
      printf("%d", elements[i]);
    }
  }
  return c;
}

int getline(int data[]){
  int c, i;

  for(i = 0; i < MAXSIZE && (c = getchar()) != '\0' && c != '\n'; i++){
    data[i] = c;
  }
  i++;
  data[i] = '\0';
  return 0;
  
}
