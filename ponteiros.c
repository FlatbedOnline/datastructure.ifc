#include <stdio.h>
#include <stdlib.h>

void main(){

  int num = 10;
  int *number = &num;

  printf("%d <-- *number\n", *number);
  printf("%p <-- &number\n", &number);
  printf("%p <-- number\n", number);
}
