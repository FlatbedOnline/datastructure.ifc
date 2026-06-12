#include <stdio.h>
#include "src/pilhaestatica.h"
#include "benchmark/benchmark.h"
#include "src/biblioteca.h"

int main(){

    Stack historico;
    init_stack(&historico);

    popularBiblioteca();

    start_benchmark();

    /* Empilha todos os livros */
    for(int i = 0; i < totalLivros; i++){
        push(&historico, biblioteca[i].codigo);
    }

    /* Desempilha todos os livros */
    for(int i = 0; i < totalLivros; i++){
        pop(&historico);
    }

    end_benchmark();

    return 0;
}
