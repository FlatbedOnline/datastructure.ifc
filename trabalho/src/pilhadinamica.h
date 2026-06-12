#ifndef PILHADINAMICA_H
#define PILHADINAMICA_H

// Definição do node
struct Node {
  int num;
  struct Node *next;
};

typedef struct Node node;

node *cria_node(int value);


//Definição de stack
struct Stack {
  node *top;
};

typedef struct Stack stack;

void init_stack(stack *s);

void push(stack *s, int value);
void pop(stack *s);




#endif // !PILHA_H
