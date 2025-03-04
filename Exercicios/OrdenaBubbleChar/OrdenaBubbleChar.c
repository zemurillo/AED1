#include <stdio.h>

void bubbleSort(char vetor[], int n) {
    int trocas = 0;
    int i, j, temp;

    // Exibe o vetor original
    for (i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%c", vetor[i]);
    }
    printf("\n");

    // Bubble Sort com contagem e impressão das trocas
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocas++;

                // Imprime o vetor após cada troca
                for (int k = 0; k < n; k++) {
                    if (k != 0) printf(" ");
                    printf("%c", vetor[k]);
                }
                printf("\n");
            }
        }
    }

    // Exibe o vetor final ordenado
    for (i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%c",vetor[i]);
    }
    printf("\n");

    // Exibe a quantidade de trocas realizadas
    printf("Trocas: %d\n", trocas);
    printf("\n");
}

int main() {
    int N;

    // Leitura do tamanho do vetor
    scanf("%d", &N);

    char vetor[N];

    // Leitura dos elementos do vetor
    for (int i = 0; i < N; i++) {
        scanf(" %c", &vetor[i]);
    }

    // Chama a função para ordenar e imprimir as saídas
    bubbleSort(vetor, N);

    return 0;
}
