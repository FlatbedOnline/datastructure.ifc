#include <stdio.h>
#include <stdlib.h>
#include "pilhadinamica.h"

node *cria_node(int value){
  node *novo = malloc(sizeof(node));
  novo->num = value;
  novo->next = NULL;

  return novo;
}

void init_stack(stack *s){
  s->top = NULL;
}

void push(stack *s, int value){
  node *novo = cria_node(value);

  novo->next = s->top;
  s->top = novo;
  printf("%d\n", s->top->num);
}



void pop(stack *s){
  
  if(s->top == NULL){
    printf("The stack is empty\n");
    return;
  }

  node *temp = s->top;
  int deleted = temp->num;
  s->top = temp->next;
  printf("%d\n", deleted);
  free(temp);
}


