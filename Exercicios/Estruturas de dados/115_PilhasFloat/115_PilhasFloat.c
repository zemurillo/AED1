#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tPilha {
    float *itens;
    int tamanho;
    int topo;
};


void iniciaPilha(struct tPilha *, int n);
int lerItem(void);
void empilha(struct tPilha *, float a);
float desempilha(struct tPilha *);





void iniciaPilha(struct tPilha *pilha, int n) {
    pilha->itens = (float*)malloc(n * sizeof(float));
    pilha->tamanho = n;
    pilha->topo = -1;
}

struct tPilha *criaPilha(int n) {
    struct tPilha * pilha = (struct tPilha*)malloc(sizeof(struct tPilha));
    iniciaPilha(pilha,n);
	return pilha;
}


int lerItem(void) {
    int a;
    scanf("%g", &a);
    return a;
}

bool estaCheia(struct tPilha *pilha) {
    return (pilha->topo == pilha->tamanho - 1);
}

bool estaVazia(struct tPilha *pilha) {
    return (pilha->topo == -1);
}

void empilha(struct tPilha *pilha, float a) {
    if (!estaCheia(pilha)) {
        pilha->topo++;
        pilha->itens[pilha->topo] = a;
    }
}

float desempilha(struct tPilha *pilha) {
    if (!estaVazia(pilha)) {
        int a = pilha->itens[pilha->topo];
        pilha->topo--;
        return a;
    }
    return -1; // Retorna -1 quando a pilha está vazia
}

// Função para liberar memória alocada
void liberarPilha(struct tPilha *pilha) {
    free(pilha->itens);
    free(pilha);
}

void mostraTopo(struct tPilha *pilha) {
    if (!estaVazia(pilha)) {
        printf("%g\n", pilha->itens[pilha->topo]);
    }
}

void imprimirBaseTopo(struct tPilha *pilha) {
    for (int i = 0; i <= pilha->topo; i++) {
        printf("%g%s", pilha->itens[i], i < pilha->topo ? " " : "\n");
    }
}

void imprimirTopoBase(struct tPilha *pilha) {
    for (int i = pilha->topo; i >= 0; i--) {
        printf("%g%s", pilha->itens[i], i > 0 ? " " : "\n");
    }
}



int main() {
    int n;
    char comando;
    float a;

    scanf("%d", &n);
    struct tPilha *pilha = criaPilha(n);



    while (scanf("\n%c", &comando) != EOF) { // Corrigido
        switch (comando) {
            case 'E':
                scanf("%g", &a);
                empilha(pilha, a);
                break;
            case 'D':
                desempilha(pilha);
                break;
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