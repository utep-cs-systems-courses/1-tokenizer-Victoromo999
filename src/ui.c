#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


void main_ui(List *history, char **tokens);
int main()
{
  puts("welcome to the tokenizer!");

  char input[100];
  List *history = init_history();

  while(1){
    printf("\nplease choose one of the following options:\n" );
    printf("1. input 's' to input sentence\n 2.input 'a' followed by a sequende of numbers to view certain history.\n 3.input 'h' to view all histories\n 4.Input 'q' to quit\n");
    printf("$");
    fgets(input, 100, stdin);

    if(input[0] =='q')
      {
	printf("Thank you and Good bye!\n");
	free_history(history);
	return 0;
      }
    else if(input[0] == '!'){
      char *hist = get_history(history, atoi(input +1));
      char **tokens = tokenize(hist);
      printf("The retrieved history: %s\n",hist);
      printf("The retrieved history tokenized:\n");
      print_tokens(tokens);
      free_tokens(tokens);
    }
    else if (input[0] =='h'){
      print_history(history);
    }
    else if (input[0] == 'i'){
      printf ("Input Sentence:\n$");
      fgets(input, 100, stdin);
      char **tokens = tokenize(input);
      print_tokens(tokens);
      add_history(history,input);
      free_tokens(tokens);
      
    }
    else {
      printf("Invalid input please try again!\n");
}
  }
}
 
