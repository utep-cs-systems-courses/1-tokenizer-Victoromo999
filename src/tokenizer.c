#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int spaced_char(char x)
{
  if((x == 't' || x == ' ' )&& x != 0){
    return 1;
  }
  return 0;
}

int not_spaced_char(char v)
{
  if ((v == 't'&& v != ' ')&& v != 0){
    return 1;
  }
  return 0;

}

char *word_start(char *str)
{
  int t;
  for (t = 0; *(str+t) != '\0'; t++){
    if( not_spaced_char(*(str+t))){
      return str + t;
    }
  }
 return str + t;
  }


 char *word_terminator(char *root)
{
  int j;
  for (j=0; *(root+j) !='\0'; j++){
    if (spaced_char(*(root+j))){
      return root + j;
    }
  }
  return root +j;
    }

int count_words( char *str)
{
  int countword =0;
  char *d = word_start(str);
  while (*d != '\0'){
    if (not_spaced_char(*d))
      {
	countword += 1;
      }
    d = word_terminator(d);
    d = word_start(d);
}
  return countword;
}

char *copy(char * instr, short length)
{
  char *scopy = malloc((length+1)* sizeof(char));
  int i;
  for (i = 0; i<length; i++){
    scopy[i] =instr[i];
  }
  scopy[i]='\0';
  return scopy;
}

char **tokenization(char*str)
{
  int number = count_words(str);
  char **tokens = malloc((number+1)* sizeof(char *));
  char *d = str;
  int k;
  for(k = 0; k < number; k++ ){
    d = word_start(d);
    int length = word_length(d);
    tokens[k] =copy(d,length);
    d = word_terminator(d);
  }

  tokens[k]=0;
  return tokens;
}
void print_tokens(char ** tokens)
{
  int m;
  for (m = 0; tokens[m] !=0; m++){
    printf("%s\n", tokens[m]);
   }
}
void free_tokens(char **tokens)
{
  int m;
  for(m=0; tokens[m] !=0; m++){
    free(tokens[m]);
  }
  free(tokens);
}

short string_size(char*str)
{
  short size=0;
  int m;
  for(m = 0; *(str+m) !='\0'; m++){
    size += 1;
      }
  return size;
}

int word_size(char *str)
{
  int size = 0;
  int k;
  for (k=0; *(str+k) != '\0'; k++){
    if (not_spaced_char(*(str+k))){
      size+=1;
    }
    else
      {
	break;
      }
  }
  return size;
}
