#include <stdio.h>
#include <stdlib.h>
#include "src/pilhadinamica.h"
#include "benchmark/benchmark.h"

int main(void){
  
  stack firstStack;
  init_stack(&firstStack);
  
  printf("inseridos:\n");
  push(&firstStack, 10);  
  push(&firstStack, 30);  
  push(&firstStack, 20);  
  push(&firstStack, 40);  
  push(&firstStack, 50);  
  
  printf("deletados:\n");
  pop(&firstStack);
  pop(&firstStack);
  pop(&firstStack);
  pop(&firstStack);
  pop(&firstStack);
   
  
  return 0;
}
