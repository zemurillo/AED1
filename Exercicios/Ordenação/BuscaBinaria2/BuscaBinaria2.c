#include <stdio.h>

// Protótipos das funções
void LeVetor(int v[], int n);
void printVetor(int v[], int in, int f);
int BuscaBinaria(int v[], int n, int x);

void LeVetor(int v[], int n) {
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}

void printVetor(int v[], int in, int f) {
    for (int j = in; j <= f; j++){
        if (j == f){
            printf("%d\n", v[j]);
        }
        else{
            printf("%d ", v[j]);
        }
    }   
}

int BuscaBinaria(int v[], int n, int x) {
    int esq = 0;
    int dir = n - 1;
    int meio;  // Declaração da variável 'meio'
    
    while (esq <= dir) {
        meio = (esq + dir) / 2;
        if (v[meio] == x) {  // Comparar o valor do vetor
            printf("VALOR %d LOCALIZADO NA COLECAO\n", x);
            return meio;
        }
        // Elemento a esquerda, descarto a direita
        else if (v[meio] > x) {
            printVetor(v, meio, dir);
            dir = meio - 1;
        }
        // O elemento está na direita, descarto do meio pra esquerda
        else {
            printVetor(v, esq, meio);
            esq = meio + 1;
        }
    }
    
    printf("VALOR %d NAO LOCALIZADO NA COLECAO\n", x);
    return -1; // não achei
}

int main() {
    int n;
    scanf("%d", &n);
    
    int v[n];
    
    LeVetor(v, n);
    
    // Lê os valores até encontrar EOF
    int x;
    while (scanf("%d", &x) != EOF) {
        // Imprime o valor buscado e realiza a busca binária
        //printf("Numero buscado: %d\n", x);
        BuscaBinaria(v, n, x);
    }
    
    return 0;
}
