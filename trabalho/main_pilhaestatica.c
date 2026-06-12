#include <stdio.h>
#include <stdlib.h>
#include "src/pilhaestatica.h"
#include "benchmark/benchmark.h"

#define MAX_LIVROS 100

typedef struct{
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidade;
}Livro;

Livro biblioteca[MAX_LIVROS];
int totalLivros = 0;

void inserirLivro(){

    Livro l;

    printf("Codigo: ");
    scanf("%d", &l.codigo);

    getchar();

    printf("Titulo: ");
    fgets(l.titulo, sizeof(l.titulo), stdin);

    printf("Autor: ");
    fgets(l.autor, sizeof(l.autor), stdin);

    printf("Ano: ");
    scanf("%d", &l.ano);

    printf("Quantidade: ");
    scanf("%d", &l.quantidade);

    biblioteca[totalLivros++] = l;

    printf("Livro cadastrado!\n");
}

void removerLivro(){

    int codigo;

    printf("Codigo do livro: ");
    scanf("%d", &codigo);

    for(int i=0;i<totalLivros;i++){

        if(biblioteca[i].codigo == codigo){

            for(int j=i;j<totalLivros-1;j++){
                biblioteca[j] = biblioteca[j+1];
            }

            totalLivros--;

            printf("Livro removido!\n");
            return;
        }
    }

    printf("Livro nao encontrado!\n");
}

void listarLivros(){

    printf("\n=== LIVROS ===\n");

    for(int i=0;i<totalLivros;i++){

        printf("\nCodigo: %d\n", biblioteca[i].codigo);
        printf("Titulo: %s", biblioteca[i].titulo);
        printf("Autor: %s", biblioteca[i].autor);
        printf("Ano: %d\n", biblioteca[i].ano);
        printf("Quantidade: %d\n", biblioteca[i].quantidade);
    }
}

void emprestarLivro(Stack *historico){

    int codigo;

    printf("Codigo do livro: ");
    scanf("%d", &codigo);

    for(int i=0;i<totalLivros;i++){

        if(biblioteca[i].codigo == codigo){

            if(biblioteca[i].quantidade <= 0){
                printf("Sem exemplares disponiveis.\n");
                return;
            }

            biblioteca[i].quantidade--;

            push(historico, codigo);

            printf("Emprestimo realizado.\n");
            return;
        }
    }

    printf("Livro nao encontrado.\n");
}

void mostrarHistorico(Stack *historico){

    if(is_empty(historico)){
        printf("Nenhum emprestimo registrado.\n");
        return;
    }

    printf("\n=== HISTORICO ===\n");

    for(int i=historico->topo;i>=0;i--){
        printf("Livro codigo %d\n", historico->dados[i]);
    }
}

int main(){

    Stack historico;

    init_stack(&historico);

    int op;

    do{

        printf("\n1 - Inserir livro\n");
        printf("2 - Remover livro\n");
        printf("3 - Listar livros\n");
        printf("4 - Emprestar livro\n");
        printf("5 - Ver historico\n");
        printf("0 - Sair\n");

        scanf("%d",&op);

        switch(op){

            case 1:
                inserirLivro();
                break;

            case 2:
                removerLivro();
                break;

            case 3:
                listarLivros();
                break;

            case 4:
                emprestarLivro(&historico);
                break;

            case 5:
                mostrarHistorico(&historico);
                break;
        }

    }while(op != 0);

    return 0;
}
