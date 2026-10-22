#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 100
/*
  Problem outline
  -> Take a string from stdin and print out only the characters that fit inside the intervals specified
     by the pairs in a column[] array of integers.
  
  We first need to provide an array with an even number of elements called 'columns[]'

  -> columns[4,9,12,20] + -1 in the end
  Each pair represents an interval of columns where data will be printed. So if
  we provide the string:
  
  |abcdefghijkmn|fjojslv
  |    efghij  nlfjojslv|
  |    456789  234567890|

  Notice that only the letters inside the interval are printed

 */

int scramble(char input[], int col[]);
void getcolumns(int columns[]);

int main(){
  int columns[MAXSIZE];
  char input[MAXSIZE];

  puts("Insert the columns intervals!");
  getcolumns(columns);
  puts("Insert the string");
  fflush(stdin);
  if(scanf("%s", input) < 0){
      puts("Insert a smaller string!");
      exit(1);
  }
  scramble(input, columns);
  
}

void getcolumns(int columns[]){
  int i;
  for(i=0; i < MAXSIZE && (scanf("%d", &columns[i])); i++){
    if(columns[i] < columns[i-1] && i != 0){
      puts("Invalid Interval! Insert a larger number");
      i--;
    }
  }
  
  if(i % 2 != 0){
    puts("Insert another interval!");
    fflush(stdin);
    while(true){
      if(scanf("%d", &columns[i]) && columns[i] > columns[i-1]){
	i++;
	break;
      }
      puts("Invalid Interval! Insert a larger number");
    }
  }
  columns[i] = -1;
  
}


int scramble(char input[], int col[]){
  int i, ct = 0 , cur = 0;
  char scrambled[MAXSIZE];
  for(i = 0; i < MAXSIZE && col[ct] != -1; i++){
    if(i >= col[ct] && i <= col[ct+1] ){
      scrambled[cur] = input[i];
      cur++;
    }
    if(i >= col[ct+1]){
      ct = ct + 2;
    }
  }
  printf("%s", scrambled);
			       
  
}
