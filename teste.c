#include <stdio.h>
#include <stdlib.h>


int main(){

  int n = 10;
  int m = 20;
  float **matriz_dados = (float**)malloc(m * sizeof(float*));


  for(int i = 0; i < m; i++){
    matriz_dados[i] = (float*) malloc(n * sizeof(float));
    printf("%p %d\n", matriz_dados[i], i);
  }
  
  
  return 0;
}
