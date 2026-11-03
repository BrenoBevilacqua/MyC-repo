#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node{
  void* val;
  struct Node* next;
}node;

node* list(void* elements[], int size);
node* create(node* ptr, void* element);
void printlist(node* list);
void printstring(node* list);

int main(){
  void* elements[] = {0};
  elements[0] = (void*)13;
  elements[1] = (void*)'v';
  elements[2] = (void*)'b';
  elements[3] = (void*)22;
  elements[4] = (void*)'a';
  
  int size = sizeof(elements)/sizeof(elements[0]);
  //  void* myptr = &size;
  
  void* els = &elements;
  node* mylist = list(els, size);
  printlist(mylist);
  //printstring(mylist);

  



  
  
}

node* list(void* elements[], int size){
  int i;
  node* ptr = (node*) malloc(sizeof(node));
  node* head = ptr;
  ptr->val = elements[0];
  if(size){
    for(i = 1; i < 5; i++){
      ptr = create(ptr, elements[i]);
    }
  }
  ptr->next = NULL;
  return head;
}

node* create(node* ptr, void* element){
  node* new = (node*) malloc(sizeof(node));
  ptr->next = new;
  new->val = element;

  return new;
}

void printlist(node* list){
  while(list){
    printf("%d, ", list->val);
    list = list->next;
  }
  printf("\n");
}

void printstring(node* list){
  while(list){
    printf("%c", list->val);
    list = list->next;
  }
  printf("\n");
}

