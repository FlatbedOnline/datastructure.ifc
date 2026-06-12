#include <stdio.h>
#include "src/pilhadinamica.h"
#include "benchmark/benchmark.h"
#include "src/biblioteca.h"

int main(){

    stack historico;
    init_stack(&historico);

    popularBiblioteca();

    start_benchmark();

    for(int i = 0; i < totalLivros; i++){
        push(&historico, biblioteca[i].codigo);
    }

    for(int i = 0; i < totalLivros; i++){
        pop(&historico);
    }

    end_benchmark();

    return 0;
}
