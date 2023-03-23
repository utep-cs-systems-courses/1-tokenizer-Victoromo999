#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"



List *init_history()
{
 List *history =(List*)malloc(sizeof(List));
history ->root = malloc(sizeof(Item));
  return history;

}



void add_history(List *list,char *str)

{

  int id = 1;

  Item *temp =list ->root;



  while (temp ->next !=0){

    temp= temp->next;

    id++;

  }



  temp ->next =malloc(sizeof(Item));

  temp->next->str = copy_str(str, string_length(str));

  temp->next->id =id;

}



char *get_history(List *list, int id)

{

  if (id == 1) {

    list->root->str;

  }

  Item *temp = list ->root;

  while (temp!= NULL){

    if(temp->id ==id){

      return temp->str;

    }

    temp = temp->next;

  }

  printf("id not in bounds");

  return NULL;

}

void print_history(List *list){

  Item *temp = list ->root->next;

  while (temp !=0){

    printf("%d. %s", temp->id, temp->str);

    temp = temp -> next;

  }

}



void free_history(List *list)

{

  Item *temp = list ->root;

  Item *tempnext;

  while(temp != NULL){
    tempnext = temp ->next;
    free(temp);
    temp = tempnext;
  }
}
