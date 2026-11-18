#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ID_OFFSET 4
#define PASS_OFFSET 10
#define BAL_OFFSET 9
#define MAXSIZE 50

typedef struct Account{
  char id[MAXSIZE];
  int balance;
}account;

int Action(char opt);
int create(char id[], char password[]);
int login(char id[], char password[]);
int check(char search[], char type, int pos);
int session(account user);
int balance(int pos);
  
int main(){
  char opt;
  puts("Bank System!");
  while(true){
    puts("What will your action be?");
    puts("C: create new account | L: log into account");
    if( ((opt = getchar()) == 'C') || (opt == 'L') ){
      fflush(stdin);
      Action(opt);
    }
    else{
      puts("Insert a valid character!");
      continue;
    }
  }
}

int Action(char opt){
  char id[MAXSIZE], password[MAXSIZE];

  puts("Insert the id");
  fgets(id, MAXSIZE, stdin);
  fflush(stdin);
  puts("Insert the password");
  fgets(password, MAXSIZE, stdin);
  fflush(stdin);

  switch (opt){
  case 'C':
    create(id, password);
    break;
  case 'L':
    login(id, password);
    break;
  default:
    return 0;
  }
  
  return 1;
}

int create(char id[], char password[]){
  FILE* fptr;

  if ( !(fptr = fopen("data.txt", "a")) ){
    puts("Error: Couldn't open file");
    return 0;
  }
  fputs("{\n", fptr);
  fputs("ID: ", fptr);
  fputs(id, fptr);
  fputs("Password: ", fptr);
  fputs(password, fptr);
  fputs("Balance: 0\n", fptr);
  fputs("}\n", fptr);

  fclose(fptr);
  puts("\nAccount successfully created!\n");
  return 1;
}

int login(char id[], char password[]){
  int pos = 0;

  if ( !(pos = check(id, 'I', pos)) ){
    puts("Unable to find ID");
    return 0;
  }
  if ( !(pos = check(password, 'P', pos)) ){
    puts("Password does not check!");
    return 0;
  }
  
  account logged;
  strcpy(logged.id, id);
  logged.balance = pos;
  
  puts("Logged in!");
  session(logged);
  return 0;
}

int session(account user){
  char opt;
  printf("Welcome, %s!\n", user.id);
  while(true){
    puts("What will your action be?");
    puts("B: Check balance | I: Insert funds into balance | E: logout");
    if( ((opt = getchar()) == 'B') || (opt == 'I') || (opt == 'E') ){
      fflush(stdin);
      if(opt == 'B'){
	balance(user.balance);
      }
      if(opt == 'I'){
	puts("In development");
	continue;
      }
      if(opt == 'E'){
	puts("Exiting...\n");
	return 0;
	
      }
    }
    else{
      puts("Insert a valid character!");
      continue;
    }
  }  
}

int balance(int pos){
  FILE* fptr;
  char hold[MAXSIZE];
  char data[MAXSIZE];
  int i;
  int offset = 9;

  if ( !(fptr = fopen("data.txt", "r") ) ){
    puts("Failed to open file!");
    return 0;
  }
  fseek(fptr, pos, SEEK_CUR);
  if( (fgets(data, MAXSIZE, fptr))){
    if(data[0] != 'B'){
      return 0;
    }
    for(i = 0; data[offset] != '\n'; i++){
      hold[i] = data[offset];
      offset++;
    }
  }
  hold[i] = '\0';
  
  printf("Your balance: %s\n\n", hold);
  return 1;
}


int check(char search[], char type, int pos){

  FILE* fptr;
  char data[MAXSIZE];
  int temp, offset, correct, i;
  
  switch (type){
  case 'I':
    temp = ID_OFFSET;
    break;
  case 'P':
    temp = PASS_OFFSET;
    break;
  default:
    return 0;
  }

  if( !(fptr = fopen("data.txt", "r")) ){
    puts("Unable to open file");
    return 0;
  }
  fseek(fptr, pos, SEEK_CUR);
  
  while( (fgets(data, 50, fptr)) > 0 ){
    //    printf("%c", data[0]);
    if(data[0] == '\n'){
      puts("stopped here");
      return 0;
    }
    if(data[0] == type){
      offset = temp;
      correct = 0;
      for(i = 0; data[offset] != '\n'; i++){
	//printf("%c %c\n", data[offset], search[i]);
	if(data[offset] == search[i]){
	  correct++;
	  offset++;
	  continue;
	}
	break;
      }
      if( correct == strlen(search) - 1 && correct == i){
	int ret = ftell(fptr);
	fclose(fptr);
	return ret;
      }
    }
  }
  return 0;
}
