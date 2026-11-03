#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check(char guess, char word[], char hold[]);

int main(){
  int guesses, ct=0;
  char guess;
  char words[10][10] = {"ball", "cat", "rain", "rock", "tower"};
  char word[10];
  char hold[10];

  printf("Hangman game\n\n");
  while(true){
    guesses = 10;
    strcpy(hold, "_________");
    strcpy(word, words[ct]);
    hold[strlen(word)] = '\0';
    printf("New word size: %ld\n\n", strlen(word));
    ct++;
    while(guesses){
      guess = getchar();
      fflush(stdin);

      if(guess < 'a' || guess > 'z'){
	//	puts("Insert a valid character!");
	continue;
      }

      if( (check(guess, word, hold)) ){
	puts("You've guessed it");
      }else{
	puts("Incorrect!");
	guesses--;
      }

      if( !(check('_', hold, hold)) ){
	printf("\nYou've guessed the word: %s\n", hold);
	break;
      }
      printf("%s\n", hold);
     
    }
  }
  
  
}

bool check(char guess, char word[], char hold[]){
  int i;
  int state = false;
  
  for(i=0; i < strlen(word); i++){
    if(guess == word[i]){
      hold[i] = word[i];
      word[i] = '_';
      state = true;
    }		     
  }
  return state;
}
