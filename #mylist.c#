#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
  int val;
  struct Node *next;
}node;

node* list(int size);
node* create(int value, node* prev);
void printlist(node* list);
void insert(node* list, int index, int value);
int delete(node* list, int index);
  
int main(){
  node* mylist = list(15);
  printlist(mylist);


  free(mylist);
  
}


node* list(int size){
  node *ptr = (node *) malloc(sizeof(node));
  ptr->val = 0;
  node *init = ptr;
  for(int i=1;i < size; i++){
    ptr = create(i, ptr);
  }
  ptr->next = NULL;
  
  return init;
}

node* create(int value, node* prev){
  node *new = (node *) malloc(sizeof(node));
  new->val = value;
  prev->next = new;
  //printf("Address pointed by previous node: %p\t ",prev->next);
  //printf("Current node address: %p\n ",new); 
  return new;
}

void printlist(node* list){
  while(list->next){
    printf("%d, ", list->val);
    list = list->next;
  }

  printf("%d\n", list->val);
}

void insert(node* list, int index, int value){
  int i;
  if(!index){
    list->val = value;
    
  }else{
    for(i =0; i < index - 2; i++){
      list = list->next;
    }
    node* temp = list->next;
    node* new = create(value, list);
    new->next = temp;


    
  }
  
}

int delete(node* list, int index){
  int i;
  if(!list->next){
    printf("Cannot delete more elements!\n");
    return 1;
  }
  if(!index){
    node *ptr = list->next;
    list->val = ptr->val;
    list->next = ptr->next;
    free(ptr);
    return 0;
  }

  for(i=0; i < index -2; i++){
    list = list->next;
  }
  if(list->next){
    node *ptr = list->next;
    list->next = ptr->next;
    free(ptr);
    return 0;
  }
  return 1;
  
}

