#include <stdio.h>
#include "pilhaestatica.h"

void init_stack(Stack *s){
    s->topo = -1;
}

int is_empty(Stack *s){
    return s->topo == -1;
}

int is_full(Stack *s){
    return s->topo == MAX - 1;
}

void push(Stack *s, int valor){

    if(is_full(s)){
        printf("Erro: pilha cheia!\n");
        return;
    }

    s->dados[++s->topo] = valor;
}

int pop(Stack *s){

    if(is_empty(s)){
        printf("Erro: pilha vazia!\n");
        return -1;
    }

    return s->dados[s->topo--];
}

int peek(Stack *s){

    if(is_empty(s)){
        printf("Erro: pilha vazia!\n");
        return -1;
    }

    return s->dados[s->topo];
}
