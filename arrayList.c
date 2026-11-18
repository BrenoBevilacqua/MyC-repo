#include <stdio.h>
#include <stdlib.h>
#include <malloc.h
#define MAX 10

void listinitialize(int next[]);


int main(){
  int key[MAX+2], next[MAX+2];
  listinitialize(key);

}

void listinitialize(int next[]){
  int head = 0, z = 1, x = 2;
  next[head] = z, next[z] = z;
}
