#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STR 104  // Definir o tamanho máximo das strings

struct tPilha {
    char *itens;
    int tamanho;
    int topo;
};

// Funções da pilha
void iniciaPilha(struct tPilha *, int n);
void empilha(struct tPilha *, char c);
char desempilha(struct tPilha *);
bool estaCheia(struct tPilha *);
bool estaVazia(struct tPilha *);
void liberarPilha(struct tPilha *);
bool verificarBalanceamentoChaves(int N, char linhas[N][104]);

// Funções da pilha
void iniciaPilha(struct tPilha *pilha, int n) {
    pilha->itens = (char*)malloc(n * sizeof(char));  // Aloca espaço para os itens da pilha
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

void empilha(struct tPilha *pilha, char c) {
    if (!estaCheia(pilha)) {
        pilha->topo++;
        pilha->itens[pilha->topo] = c;  // Empilha o caractere
    }
}

char desempilha(struct tPilha *pilha) {
    if (!estaVazia(pilha)) {
        char c = pilha->itens[pilha->topo];
        pilha->topo--;
        return c;  // Retorna o caractere desempilhado
    }
    return '\0';  // Retorna '\0' se a pilha estiver vazia
}

void liberarPilha(struct tPilha *pilha) {
    free(pilha->itens);  // Libera o espaço alocado para os itens
    free(pilha);  // Libera a pilha
}

// Função para verificar o balanceamento de chaves
bool verificarBalanceamentoChaves(int N, char linhas[N][104]) {
    struct tPilha *pilha = criaPilha(N*104); // Pois em cada linha pode ter mais de um "{" para empilhar

    // Processar cada linha do código
    for (int i = 0; i < N; i++) {
        for (int j = 0; linhas[i][j] != '\0'; j++) {
            if (linhas[i][j] == '{') {
                empilha(pilha, '{');  // Empilha chave de abertura
            } else if (linhas[i][j] == '}') {
                if (estaVazia(pilha)) {
                    // Se a pilha estiver vazia, significa que a chave de fechamento não tem correspondente
                    liberarPilha(pilha);
                    return false;  // Retorna falso para indicar erro no balanceamento
                }
                desempilha(pilha);  // Desempilha chave de abertura correspondente
            }
        }
    }

    // Se a pilha estiver vazia no final, as chaves estão balanceadas
    bool resultado = estaVazia(pilha);
    liberarPilha(pilha);
    return resultado;
}

int main() {
    int N;
    scanf("%d", &N);  // Lê o número de linhas

    char linhas[N][104];  // Declara o array para armazenar as linhas. É uma matriz

    // Lê as linhas do código
    getchar();  // Consome o '\n' deixado pelo scanf
    for (int i = 0; i < N; i++) {
        fgets(linhas[i], sizeof(linhas[i]), stdin);  // Lê a linha
    }

    // Verifica o balanceamento das chaves	
	printf("%s",verificarBalanceamentoChaves(N,linhas)?"S\n":"N\n");

    return 0;
}
