#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 10
#define OUT 1
#define IN 0

int main(){
  char wordlist[30][10] = {"zebra", "car", "cat", "box", "computer", "machine", "lion", "tower", "road", "ball", "woman", "sun", "shop"};
  char word[MAXLINE];
  int guesses = MAXLINE + 5;
  int state = OUT;
  char choice;

  while(state){
    printf("Word guessing game");
    strcpy(word, wordlist[rand()%13]);
    printf("%s\n", word);
    printf("Will you try guessing the entire word or a letter?");
    printf("\n");
    while(guesses){
      while(state){
	if((choice = getchar()) == 'w' || choice == 'l'){
	  state = IN;
	}else{
	  printf("\nInsert a valid character\n");
	  state = IN;
	  break;
	}	
      }
      if(choice == 'w'){
	getword(word);
	printf("%s", word);
      }
      printf("%c", choice);
      printf("hey");
      guesses = 0;

      }
    }
  }

  int getword(char line[]){
    int i;
    for(i=0; i < MAXLINE && scanf("%c", &line[i]) == 1 && line[i] >= 0; i++);
      
    
  }












