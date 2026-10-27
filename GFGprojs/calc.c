#include <stdio.h>
#include <stdlib.h>

int calc(char arguments[], int max);
  
int main(int argc, char argv[]){
  puts("Simple calculator");
  calc(argv, argc);
}

int calc(char arguments[], int max){
  int i;
  for(i=0; i < max; i++){
    printf("%s", arguments[i]);
  }
  return 0;
}
