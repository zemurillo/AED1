#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tLista {
    int *itens;
    int quantidade;
    int tamanho;
};

// Inicializa a lista com um tamanho específico
void iniciaLista(struct tLista* lista, int n) {
    lista->itens = (int*)malloc(n * sizeof(int));
    lista->quantidade = 0;
    lista->tamanho = n;
}

// Cria uma nova lista e a inicializa
struct tLista* criaLista(int n) {
    struct tLista* lista = (struct tLista*)malloc(sizeof(struct tLista));
    iniciaLista(lista, n);
    return lista;
}

// Busca linear retorna o índice do elemento ou -1 se não encontrado
int buscaLinear(struct tLista *lista, int a) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (a == lista->itens[i]) {
            //printf("SIM\n");
			return i; // Retorna imediatamente quando encontra
        }
    }
	//printf("NAO\n");
    return -1;
}

// Desloca elementos para a direita a partir de um índice
void deslocaDir(struct tLista *lista, int ateh) {
    for (int j = lista->quantidade - 1; j >= ateh; j--) {
        lista->itens[j + 1] = lista->itens[j];
    }
}

// Insere um elemento na lista mantendo a ordem crescente
void inserir(struct tLista *lista, int a) {
    int achei = 0;
    int i;

    if (lista->quantidade < lista->tamanho) {
        if (lista->quantidade == 0) {
            lista->itens[0] = a;
            lista->quantidade++;
            return;
        }

        for (i = 0; i < lista->quantidade && achei == 0; i++) {
            if (lista->itens[i] >= a) { // Encontrou a posição de inserção
                achei = 1;
                if (lista->itens[i] == a) { // Elemento já existe
                    //printf("\nChave: %d já existe na lista!\n", a);
                    return;
                } else {
                    deslocaDir(lista, i);
                    lista->itens[i] = a;
                }
            }
        }

        if (achei == 0) { // Insere no final
            lista->itens[lista->quantidade] = a;
        }

        lista->quantidade++;
    } else {
        //printf("\nLista Cheia!\n");
    }
}

// Desloca elementos para a esquerda a partir de um índice
void deslocaEsq(struct tLista *lista, int de) {
    for (int j = de; j < lista->quantidade; j++) {
        lista->itens[j] = lista->itens[j + 1];
    }
}

// Remove um elemento da lista
void remover(struct tLista *lista, int a) {
    if (lista->quantidade > 0) {
        int posicao = buscaLinear(lista, a);
        if (posicao != -1) {
            deslocaEsq(lista, posicao);
            lista->quantidade--;
        } else {
            //printf("\nChave não localizada!\n");
        }
    } else {
        //printf("\nLista Vazia!\n");
    }
}

// Função para exibir a lista
//void exibirLista(struct tLista *lista) {
//    //if (lista->quantidade == 0) {
//    //    printf("\n");
//    //    return;
//    //}
//    for (int i = 0; i < lista->quantidade; i++) {
//        if (i < lista->quantidade - 1) {
//            printf("%d ", lista->itens[i]);
//        } else {
//            printf("%d", lista->itens[i]);
//        }
//    }
//    printf("\n");
//}


void imprimir(struct tLista *les)
{
    for (int i = 0; i < les->quantidade; i++)
        printf("%d%s", les->itens[i], i < les->quantidade - 1 ? " " : "\n");
}

// Função para liberar memória alocada
void liberarLista(struct tLista *lista) {
    free(lista->itens);
    free(lista);
}

// Exemplo de uso
int main() {
    int n;
    char comando;
    int a;

    scanf("%d", &n);
    struct tLista *lista = criaLista(n);

    while (scanf("\n%c", &comando) != EOF) { // Corrigido
        switch (comando) {
            case 'I':
                scanf("%d", &a);
                inserir(lista, a);
                break;
            case 'R':
                scanf("%d", &a);
                remover(lista, a);
                break;
            case 'M':
                //exibirLista(lista);
                imprimir(lista);
				break;
			case 'B':
                scanf("%d", &a);
				if (buscaLinear(lista,a) == -1){
					printf("NAO\n");
				}
				else{
					printf("SIM\n");
				}
                break;
				
				
        }
    }

    liberarLista(lista);
    return 0;
}
