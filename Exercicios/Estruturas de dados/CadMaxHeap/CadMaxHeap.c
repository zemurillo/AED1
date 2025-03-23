#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para ler o vetor de inteiros
void LeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

struct tHeap {
    int TAMANHO;
    int quantidade;
    int *itens;  // Agora a variável 'itens' é um ponteiro dinâmico
};

// Função para imprimir o heap formatado corretamente
void imprimir_heap(struct tHeap *heap) {
    for (int i = 0; i < heap->quantidade; i++) {
        printf("%d", heap->itens[i]);
        if (i < heap->quantidade - 1){
			printf(" ");
		}
    }
    printf("\n");
}

int imprimir_heap2(struct tHeap *heap)
{
    for (int i = 0 ; i < heap->quantidade; i++)
        printf("%d%s",heap->itens[i],i<heap->quantidade-1?" ":"\n");
}

// Protótipo da função
void iniciaHeap(struct tHeap *h, int n);

struct tHeap * criaHeap(int n) { 
    // Alocando memória para a struct tHeap
    struct tHeap *heap = (struct tHeap *)malloc(sizeof(struct tHeap));
    if (heap != NULL) {
        // Alocando memória para o vetor de itens
        heap->itens = (int *)malloc(n * sizeof(int));
        if (heap->itens == NULL) {
            printf("\nErro na alocacao do vetor de itens!\n");
            free(heap);
            exit(1);
        }
        iniciaHeap(heap, n);
    } else {
        printf("\nErro na alocacao do heap!\n");
        exit(1);
    }
    return heap;
}

void iniciaHeap(struct tHeap *h, int n) {
    h->quantidade = 0;
    h->TAMANHO = n;
}

// Função para ler um item do usuário
int lerItem(void) {
    int item;
    scanf("%d", &item);
    return item;
}

// Funções de apoio para manipulação do heap
int filhoEsq(int pai) {
    return 2 * pai + 1;
}

int filhoDir(int pai) {
    return 2 * pai + 2;
}

int pai(int filho) {
    return (int)(filho - 1) / 2;
}

int ultimoPai(struct tHeap h) {
    return (h.quantidade / 2) - 1;
}

void peneirar(struct tHeap *heap, int pai) {
    int fEsq = filhoEsq(pai);
    int fDir = filhoDir(pai);
    int maior = pai;
    int aux;

	if (fDir < heap->quantidade && heap->itens[fDir] > heap->itens[maior]) {
        maior = fDir;
    }
	if (fEsq < heap->quantidade && heap->itens[fEsq] > heap->itens[maior]) {
        maior = fEsq;
    }

    if (maior != pai) {
        aux = heap->itens[pai];
        heap->itens[pai] = heap->itens[maior];
        heap->itens[maior] = aux;
        peneirar(heap, maior);
    }
}

void construirHeap(struct tHeap *heap) {
    for (int i = ultimoPai(*heap); i >= 0; i--) {
        peneirar(heap, i);
    }
}

void inserirHeap(struct tHeap *heap) {
    int novo;
    int novoInd = heap->quantidade;
    
    if (heap->quantidade < heap->TAMANHO) {
        novo = lerItem();
        heap->itens[novoInd] = novo;
        heap->quantidade++;
        if (heap->quantidade != 1) {
            if (heap->itens[pai(novoInd)] < heap->itens[novoInd]) {
                construirHeap(heap);
            }
        }
    } else {
        //printf("\nHeap Cheio!\n");
    }
}

void removerMaxHeap(struct tHeap *heap) {
    int aux;
    if (heap->quantidade > 0) {
        printf("%d\n",heap->itens[0]);
		aux = heap->itens[0];
        heap->itens[0] = heap->itens[heap->quantidade - 1];
        heap->itens[heap->quantidade - 1] = aux;
        heap->quantidade--;
        construirHeap(heap);
    } else {
        //printf("\nHeap Vazio!!!\n");
    }
}

int main() {
    int n;
    char comando;
    
    scanf("%d", &n);
    
    struct tHeap *heap = criaHeap(n);
    
    //scanf("%c", &comando); // Para capturar o '\n' deixado pelo scanf anterior
    
    while (scanf("%c", &comando) != EOF) {
        switch (comando) {
            case 'I':
                inserirHeap(heap);
                break;
            case 'R':
                removerMaxHeap(heap);
                break;
            case 'M':
                imprimir_heap2(heap);
                break;
        }
    }
    
    free(heap->itens); // Liberando a memória do vetor de itens
    free(heap); // Liberando a memória do heap
    
    return 0;
}
