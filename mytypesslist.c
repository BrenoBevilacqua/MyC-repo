#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
  void* val;
  struct Node *next;
}node;

node* list(int elements[], int max);
node* create(int* value, node* prev);
void printlist(node* list);
void insert(node* list, int index, int value);
void* delete(node* list, int index);

void* search(node* list, int val);
int main(){

  int elements[] = {10,20,30,40,50,60,70,80,90,100};
  int max = sizeof(elements)/sizeof(elements[0]);
  node* mylist = list(elements, max);
  insert(mylist,3,100);
  insert(mylist,5,200);
  insert(mylist,9,300);
  printlist(mylist);

  void* ptr = delete(mylist, 0);
  printf("%d", *(int*)ptr);
  printlist(mylist);
  
  free(ptr);
  
  
  
  return 0;

  
}

void* search(node* list, int val){
  for(int i=0; i < val-1; i++){
    list = list->next;
  }
  void* ptr = list->val;
  return ptr;
}


node* list(int elements[], int max){
  node *ptr = (node *) malloc(sizeof(node));
  int *val = calloc(0, sizeof(int));
  val[0] = elements[0];
  ptr->val = val;
  node *init = ptr;
  for(int i=1;i < max; i++){
    int* val = calloc(0,sizeof(i));
    val[0] = elements[i];
    ptr = create(val, ptr);
  }
  ptr->next = NULL;
  
  return init;
}

node* create(int* value, node* prev){

  node* new = (node *) malloc(sizeof(node));
  new->val = value;
  //printf("%d\n", *(int*) new->val);
  prev->next = new;
  //printf("Address pointed by previous node: %p\t ",prev->next);
  //printf("Current node address: %p\n ",new);

  return new;
}

void printlist(node* list){
  while(list->next){
    printf("%d, ", *(int*) list->val);
    list = list->next;
  }

  printf("%d\n", *(int *) list->val);
}

void insert(node* list, int index, int value){
  int* val = (int *) calloc(0, sizeof(int));
  val[0] = value;
  if(!index){
    node* temp = list->next;
    node* new = create(list->val, list);
    list->val = val;
    new->next = temp;  
  }else{
    for(int i =0; i < index - 2; i++){
      list = list->next;
    }
    node* temp = list->next;
    node* new = create(val, list);
    new->next = temp;
  }
  
}

void* delete(node* list, int index){
  int i;
  if(!list->next){
    printf("Cannot delete more elements!\n");
    //    return 1;
  }
  if(!index){
    void* temp = list->val;
    
    node *ptr = list->next;
    list->next = ptr->next;
    list->val = ptr->val;
    free(ptr);
    //    printf("| %d and", *(int*)temp);
    //    printf("%d |", *(int*)list->val);
    return temp;
      //return 0;
  }

  for(i=0; i < index -2; i++){
    list = list->next;
  }
  if(list->next){
    
    node *ptr = list->next;
    void* temp = ptr->val;
    list->next = ptr->next;
    free(ptr);
    free(temp);
    //    return 0;
  }
  //  return 1;
  
}

