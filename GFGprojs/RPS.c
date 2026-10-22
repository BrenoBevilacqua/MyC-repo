#include <stdio.h>
#include <stdlib.h>
#define ROCK 33
#define PAPER 66
#define SCISSORS 99
#define QUIT 71


int main(){
  srand(1);
  int V = 0;
  int D = 0;
  int c;
  int e;
  int state = true;
  printf("\t\t\tRock, paper and scissor game!\n\n");
  printf("\t\t\t\tRock: 0\n\t\t\t\t|--------------|\n\t\t\t\tPaper: 1\n\t\t\t\t|--------------|\n\t\t\t\tScissors: 2\n\t\t\t\t|--------------|\n"); 
  while(true){ 
    printf("\n\t\t\t  Victories: %d | Defeats: %d\n\n", V, D); 
     while(state == true ){ 
	 printf("\t\t\t\t   Your turn!\n\t\t\t\t");
	 if((c = getchar()) <= 73 && c >= 71){
	   c = (c - 70) * 33;
	   state = false; 
	   e = rand()%100; 
	   fflush(stdin); 
       }else{ 
   	printf("Invalid char\n"); 
   	exit(0); 
       } 

     }
     printf("\t\t\t\t     %d, %d\n\t\t\t\t   ", c, e); 
     if((c - e <= 32) && c - e > 0){
       printf("Tie!");

     }
     if(c - e >= 33 || c - e <= -34){
       printf("You win!");
     }
     else{
       printf("You lose!");
     }
     
     /*if((c == ROCK && e ) || (c == PAPER && (e > 33 && e <= 66)) || (c == SCISSORS && e == ROCK)){ 
       printf("You lose!"); 
       D++; 
     } 
   else if( (e == ROCK && c == PAPER) || (e == PAPER && c == SCISSORS) || (e == SCISSORS && c == ROCK)){
      printf("You win!");
      V++;
   }
    else{
      printf("   Tie!");
      }*/
    state = true;
  }
		       	      
  
 
}
