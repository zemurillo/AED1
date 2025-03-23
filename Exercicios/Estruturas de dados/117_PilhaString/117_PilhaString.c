#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_STR 100  // Definir o tamanho máximo das strings

struct tPilha {
    char **itens;
    int tamanho;
    int topo;
};

// Funções da pilha
void iniciaPilha(struct tPilha *, int n);
void empilha(struct tPilha *, char *str);
char* desempilha(struct tPilha *);
bool estaCheia(struct tPilha *);
bool estaVazia(struct tPilha *);
void mostraTopo(struct tPilha *);
void imprimirBaseTopo(struct tPilha *);
void imprimirTopoBase(struct tPilha *);
void liberarPilha(struct tPilha *);

void iniciaPilha(struct tPilha *pilha, int n) {
    pilha->itens = (char**)malloc(n * sizeof(char*));  // Aloca espaço para os ponteiros das strings
    pilha->tamanho = n;
    pilha->topo = -1;
}

struct tPilha *criaPilha(int n) {
    struct tPilha * pilha = (struct tPilha*)malloc(sizeof(struct tPilha));
    iniciaPilha(pilha, n);
    return pilha;
}

bool estaCheia(struct tPilha *pilha) {
    return (pilha->topo == pilha->tamanho - 1);
}

bool estaVazia(struct tPilha *pilha) {
    return (pilha->topo == -1);
}

void empilha(struct tPilha *pilha, char *str) {
    if (!estaCheia(pilha)) {
        pilha->topo++;
        pilha->itens[pilha->topo] = strdup(str);  // Copia a string para evitar problemas com ponteiros
    }
}

char* desempilha(struct tPilha *pilha) {
    if (!estaVazia(pilha)) {
        char *str = pilha->itens[pilha->topo];
        pilha->topo--;
        return str;  // Retorna a string desempilhada
    }
    return NULL;  // Retorna NULL se a pilha estiver vazia
}

void mostraTopo(struct tPilha *pilha) {
    if (!estaVazia(pilha)) {
        printf("%s\n", pilha->itens[pilha->topo]);
    }
}

void imprimirBaseTopo(struct tPilha *pilha) {
    for (int i = 0; i <= pilha->topo; i++) {
        printf("%s%s", pilha->itens[i], i < pilha->topo ? " " : "\n");
    }
}

void imprimirTopoBase(struct tPilha *pilha) {
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%s%s", pilha->itens[i], i > 0 ? " " : "\n");
    }
}

void liberarPilha(struct tPilha *pilha) {
    for (int i = 0; i <= pilha->topo; i++) {
        free(pilha->itens[i]);  // Libera cada string alocada
    }
    free(pilha->itens);
    free(pilha);
}

int main() {
    int n;
    char comando;
    char buffer[MAX_STR];  // Buffer para armazenar strings lidas

    scanf("%d", &n);
    struct tPilha *pilha = criaPilha(n);

    while (scanf(" %c", &comando) != EOF) {
        switch (comando) {
            case 'E':  // Empilhar string
                scanf("%s", buffer);
                empilha(pilha, buffer);
                break;
            case 'D': { // Desempilhar string
                char *desempilhado = desempilha(pilha);
                if (desempilhado) {
                    free(desempilhado);
                }
                break;
            }
            case 'T':
                mostraTopo(pilha);
                break;
            case 'X':
                imprimirTopoBase(pilha);
                break;
            case 'B':
                imprimirBaseTopo(pilha);
                break;
        }
    }

    liberarPilha(pilha);
    return 0;
}

// MAIN LENDO DE UM ARQUIVO
//int main() {
//    int n;
//    char comando;
//    char buffer[MAX_STR];
//    
//    // Abrir arquivo para leitura
//    FILE *entrada = fopen("entrada.txt", "r");
//    if (entrada == NULL) {
//        printf("Erro ao abrir o arquivo de entrada.\n");
//        return 1;
//    }
//    
//    fscanf(entrada, "%d", &n);
//    struct tPilha pilha;
//    iniciaPilha(&pilha, n);
//
//    // Ler o arquivo até o final
//    while (fscanf(entrada, " %c", &comando) != EOF) { // Corrigido para aceitar espaços
//        switch (comando) {
//            case 'E':  // Empilhar string
//                fscanf(entrada, "%s", buffer);
//                empilha(&pilha, buffer);
//                break;
//            case 'D':  // Desempilhar string
//                desempilha(&pilha);
//                break;
//            case 'T':  // Mostrar topo
//                mostraTopo(&pilha);
//                break;
//            case 'X':  // Imprimir topo para base
//                imprimirTopoBase(&pilha);
//                break;
//            case 'B':  // Imprimir base para topo
//                imprimirBaseTopo(&pilha);
//                break;
//        }
//    }
//
//    fclose(entrada); // Fechar arquivo
//
//    return 0;
//}