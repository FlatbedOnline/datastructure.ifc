#include <stdio.h>

void quick_sort(int vet[], int inicio, int fim) {
    int i = inicio;
    int j = fim;

    int pivo = vet[(inicio + fim) / 2];

    while (i <= j) {

        while (vet[i] < pivo)
            i++;

        while (vet[j] > pivo)
            j--;

        if (i <= j) {
            int aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;

            i++;
            j--;
        }
    }

    if (inicio < j)
        quick_sort(vet, inicio, j);

    if (i < fim)
        quick_sort(vet, i, fim);
}

int main() {
    int vet[] = {8, 3, 1, 7, 0, 10, 2};
    int n = sizeof(vet) / sizeof(vet[0]);

    quick_sort(vet, 0, n - 1);

    printf("Vetor ordenado:\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}
