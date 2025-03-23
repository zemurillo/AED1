#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(char **vetor, int n) {
    int trocas = 0;
    int i, j;
    char *temp;

    // Exibe o vetor original
    for (i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%s", vetor[i]);
    }
    printf("\n");

    // Bubble Sort com contagem e impressão das trocas
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(vetor[j], vetor[j + 1]) > 0) { // Comparação corrigida
                // Troca os elementos
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                trocas++;

                // Imprime o vetor após cada troca
                for (int k = 0; k < n; k++) {
                    if (k != 0) printf(" ");
                    printf("%s", vetor[k]);
                }
                printf("\n");
            }
        }
    }

    // Exibe o vetor final ordenado
    for (i = 0; i < n; i++) {
        if (i != 0) printf(" ");
        printf("%s", vetor[i]);
    }
    printf("\n");

    // Exibe a quantidade de trocas realizadas
    printf("Trocas: %d\n", trocas);
}

int main() {
    int N, i;

    // Leitura do tamanho do vetor
    scanf("%d", &N);
	
    // Aloca dinamicamente memória para o vetor de ponteiros de strings
    char **vetor = (char **)malloc(N * sizeof(char *));
   
    // Verifica se a alocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    // Lendo as N strings
    for (i = 0; i < N; i++) {
        vetor[i] = (char *)malloc(100 * sizeof(char)); // Aloca espaço para cada string
        if (vetor[i] == NULL) {
            printf("Erro ao alocar memória\n");
            return 1;
        }
        scanf("%s", vetor[i]); // Lê a string
    }

    // Chama a função para ordenar e imprimir as saídas
    bubbleSort(vetor, N);

    // Libera memória alocada
    for (i = 0; i < N; i++) {
        free(vetor[i]);
    }
    free(vetor);

    return 0;
}
