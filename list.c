#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>




typedef struct Node{
  int val;
  struct Node *next;
}node;

node* list(int size);
node* create(int i, node *pt);
void printlist(node* list);
void insert(node* list, int index, int value);

int main(){

  node* mylist = list(5);

  printlist(mylist);

  insert(mylist, 5, 55);
  printlist(mylist);
  printf("%d\n", mylist->val);

  
  return 0;
  
}

node* list(int size){
  node *ptr = (struct Node *) malloc(sizeof(struct Node));
  node *temp = ptr;
  
  ptr->val = 0;

  /*if(!ptr->next){
    puts("Fail");
    exit(1);
    }*/
  for(int i=1; i < size; i++){
      ptr = create(i, ptr);
  }
  ptr->next = NULL;
  return temp;
}

node* create(int i, struct Node *pt){
  
  node *newptr = (struct Node *) malloc(sizeof(struct Node));
  
  pt->next = newptr;
  //printf("Modified pointer of previous node %p\n", pt->next);
  newptr->val = i;
  //printf("Current Node address: %p\tValue: %d\n", newptr, newptr->val);
  
  return newptr;
}

void printlist(node* list){

  while(list->next != NULL){
    printf("%d ", list->val);
    list = list->next;
  }
  printf("%d\n", list->val);
}

void insert(node* list, int index, int value){
  int i;
  for(i=0; i < index-1 ; i++){
    list = list->next;
  }
  node *newnode = (struct Node *) malloc(sizeof(struct Node *));
  printf("new node: %p\n", newnode);
  node *temp = list->next;
  printf("previous node: %p\n", list->next);
  list->next = newnode;
  printf("changed address: %p\n", list->next);
  printf("%p", newnode->next);

  newnode->next = temp;
  newnode->val = value;
}
 
