#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_LIVROS 10000

typedef struct {
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidade;
} Livro;

extern Livro biblioteca[MAX_LIVROS];
extern int totalLivros;

void popularBiblioteca(void);

#endif
