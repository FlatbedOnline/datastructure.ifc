#include <stdio.h>
#include "biblioteca.h"

Livro biblioteca[MAX_LIVROS];
int totalLivros = 0;

void popularBiblioteca(void){

    for(int i = 0; i < MAX_LIVROS; i++){

        biblioteca[i].codigo = i + 1;

        sprintf(biblioteca[i].titulo,
                "Livro %d", i + 1);

        sprintf(biblioteca[i].autor,
                "Autor %d", i + 1);

        biblioteca[i].ano = 1950 + (i % 75);

        biblioteca[i].quantidade = 10;
    }

    totalLivros = MAX_LIVROS;
}
