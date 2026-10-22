#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>




struct Node{
  int val;
  struct Node *next;
};

void list(int size);
struct Node* create(int i, struct Node *pt);

int main(){

  list(5);
  return 0;
}

void list(int size){
  struct Node *ptr = (struct Node *) malloc(sizeof(struct Node));
  ptr->val = 0;

  /*if(!ptr->next){
    puts("Fail");
    exit(1);
    }*/
  for(int i=1; i < size; i++){
      ptr = create(i, ptr);
  }
  ptr->next = NULL;
  
}

struct Node* create(int i, struct Node *pt){
  
  struct Node *newptr = (struct Node *) malloc(sizeof(struct Node));
  
  pt->next = newptr;
  printf("Modified pointer of previous node %p\n", pt->next);
  newptr->val = i;
  printf("Current Node address: %p\tValue: %d\n", newptr, newptr->val);
  
  return newptr;
}
  
 
