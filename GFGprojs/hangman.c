#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(char word[], char guess);
void hangman();

int main(){
  int tries, corrects;
  int wins=0;
  char static const words[20][10] = {"zebra", "ball", "computer", "mouse", "tower", "car"};
  char word[10];
  char guess;
  
  printf("Hangman game\n");
  while(true){
    printf("\nWin count: %d\n", wins);
    strcpy(word, words[1]);
    tries  = strlen(word) * 1.5;
    corrects = 0;
    while(tries){
      hangman();
      printf("Tries: %d\n", tries);
      if((guess = getchar()) == '0'){
	printf("Insert a valid character!");
	continue;
      }
      fflush(stdin);
      if(check(word, guess)){
	printf("Letter guessed\n");
	corrects++;
      }
      if(corrects >= strlen(word)){
	  printf("You've guessed the word '%s'\n", word);
	  wins++;
	  break;
      }
      tries--;
      if(!tries){
	printf("\nYou lost, the word was: '%s'\n", words[1]);
      }
    }
      
  }
}

void hangman(){
  char hangman[9][10] = {
    "   _____\n","   |\t|\n","   O\t|\n","  /|","\\\t|\n","   |\t|\n","  /"," \\\t|\n", "________|" };
  for(int i=0; i <9; i++){
    printf("%s", hangman[i]);
  }
  printf("\n");
}
int check(char word[], char guess){
  int i;
  int state = 0;
  for(i=0; i < strlen(word); i++){
    if(word[i] == guess){
      word[i] = '0';
      state = 1;
    }
  }
  return state;
}
