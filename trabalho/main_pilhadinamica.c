#include <stdio.h>
#include <string.h>
#include "src/pilhadinamica.h"
#include "benchmark/benchmark.h"

#define MAX_LIVROS 100

typedef struct{
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    int quantidade;
} Livro;

Livro biblioteca[MAX_LIVROS];
int totalLivros = 0;

void inserirLivro(){

    if(totalLivros >= MAX_LIVROS){
        printf("Biblioteca cheia.\n");
        return;
    }

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

    printf("Livro cadastrado.\n");
}

void removerLivro(){

    int codigo;

    printf("Codigo do livro: ");
    scanf("%d", &codigo);

    for(int i = 0; i < totalLivros; i++){

        if(biblioteca[i].codigo == codigo){

            for(int j = i; j < totalLivros - 1; j++){
                biblioteca[j] = biblioteca[j + 1];
            }

            totalLivros--;

            printf("Livro removido.\n");
            return;
        }
    }

    printf("Livro nao encontrado.\n");
}

void listarLivros(){

    if(totalLivros == 0){
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    for(int i = 0; i < totalLivros; i++){

        printf("\nCodigo: %d\n", biblioteca[i].codigo);
        printf("Titulo: %s", biblioteca[i].titulo);
        printf("Autor: %s", biblioteca[i].autor);
        printf("Ano: %d\n", biblioteca[i].ano);
        printf("Quantidade: %d\n", biblioteca[i].quantidade);
    }
}

void emprestarLivro(stack *historico){

    int codigo;

    printf("Codigo do livro: ");
    scanf("%d", &codigo);

    for(int i = 0; i < totalLivros; i++){

        if(biblioteca[i].codigo == codigo){

            if(biblioteca[i].quantidade <= 0){
                printf("Livro indisponivel.\n");
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

void mostrarHistorico(stack *historico){

    if(historico->top == NULL){
        printf("Nenhum emprestimo registrado.\n");
        return;
    }

    printf("\n=== HISTORICO DE EMPRESTIMOS ===\n");

    node *aux = historico->top;

    while(aux != NULL){
        printf("Livro codigo %d\n", aux->num);
        aux = aux->next;
    }
}

int main(){

    stack historico;
    init_stack(&historico);

    int op;

    do{

        printf("\n===== BIBLIOTECA =====\n");
        printf("1 - Inserir livro\n");
        printf("2 - Remover livro\n");
        printf("3 - Listar livros\n");
        printf("4 - Emprestar livro\n");
        printf("5 - Mostrar historico\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &op);

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

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while(op != 0);

    return 0;
}
