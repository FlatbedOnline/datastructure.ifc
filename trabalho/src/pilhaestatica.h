#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H

#define MAX 10000

typedef struct {
    int dados[MAX];
    int topo;
} Stack;

void init_stack(Stack *s);

void push(Stack *s, int valor);

int pop(Stack *s);

int peek(Stack *s);

int is_empty(Stack *s);

int is_full(Stack *s);

#endif
