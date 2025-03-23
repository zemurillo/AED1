#include <stdio.h>

// Função para ler os elementos do vetor
void LeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

// Função para imprimir o vetor com espaço entre os elementos
void printVetorEspaco(int v[], int n) {
    for (int j = 0; j < n; j++) {
        if (j != n - 1) {
            printf("%d ", v[j]);
        } else {
            printf("%d\n", v[j]);
        }
    }
}

// Função que realiza a intercalação (fusão) dos subvetores
void intercala(int v[], int vaux[], int inicio, int meio, int fim) {
    int i = inicio, j = meio + 1, k = inicio;

    // Intercalação de dois subvetores ordenados
    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            vaux[k++] = v[i++];
        } else {
            vaux[k++] = v[j++];
        }
    }

    // Copiar os elementos restantes da primeira metade, se houver
    while (i <= meio) {
        vaux[k++] = v[i++];
    }

    // Copiar os elementos restantes da segunda metade, se houver
    while (j <= fim) {
        vaux[k++] = v[j++];
    }

    // Copiar os elementos ordenados de volta para o vetor original
    for (int m = inicio; m <= fim; m++) {
        v[m] = vaux[m];
    }
}

// Função que realiza o mergeSort
void mergeSort(int v[], int vaux[], int inicio, int fim, int n) {
    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        // Chamada recursiva para a primeira metade
        mergeSort(v, vaux, inicio, meio, n);
        
        // Chamada recursiva para a segunda metade
        mergeSort(v, vaux, meio + 1, fim, n);
		
		//printVetorEspaco(v, fim + 1); // aqui só imprimo as partes que foram sendo alteradas
		printVetorEspaco(v, n); //--> Aqui imprimo o vetor completo
		
        // Chama a função de intercalação para mesclar os dois subvetores ordenados
        intercala(v, vaux, inicio, meio, fim);

        // Imprime o vetor após cada intercalação
        
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int v[n], vaux[n];

    LeVetor(v, n);

    //printf("Vetor:\n");
    printVetorEspaco(v, n);

    //printf("Iniciando o merge sort\n");

    // Chama o mergeSort
    mergeSort(v, vaux, 0, n - 1,n);

    // Imprime o vetor ordenado
    printVetorEspaco(v, n);

    return 0;
}
