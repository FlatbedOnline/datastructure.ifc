#include <stdio.h>

void bubbleSort(int tamanho, int aux, int *v){

  for(int i = 0; i < tamanho - 1; i++){

    for(int j = 0; j < tamanho - i - 1; j++){
      if(v[j] > v[j+1]){
        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
      }
    }
  }

}

void contagem(int *vetor, int tamanho){
  for(int i; i < tamanho; i++){
    printf("%d ",vetor[i]);
  }
  printf("\n");
}

int main(){

  int aux, v[] = {12, 5, 34, 32, 9};
  int tamanho = sizeof(v) / sizeof(v[0]);
  
  contagem(v, tamanho);

  bubbleSort(tamanho, aux, v);


  for(int i = 0; i < tamanho; i++){
    
    printf("%d ",v[i]);


  }

  printf("\n");

  
  

  return 0;
}
