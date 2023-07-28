#include <stdio.h>
#include <time.h>

void bubbleSort(int *vetor, int tamanho) {
    int i, j, aux;
    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main() {
    int vetor[] = {5, 3, 2, 4, 7, 1, 0, 6};
    int tamanho = sizeof(vetor) / sizeof(int);
    int i;
    clock_t start;
    bubbleSort(vetor, tamanho);
    clock_t end;
    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\nTempo de execução bubble sort: %li", (end - start)/(CLOCKS_PER_SEC));
    return 0;
}