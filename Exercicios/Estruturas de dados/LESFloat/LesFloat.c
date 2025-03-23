#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tLista {
    float *itens;
    int quantidade;
    int tamanho;
};

// Inicializa a lista com um tamanho específico
void iniciaLista(struct tLista* lista, int n) {
    lista->itens = (float*)malloc(n * sizeof(float));
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
int buscaLinear(struct tLista *lista, float a) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (a == lista->itens[i]) {
            //printf("SIM\n");
			return i; // Retorna imediatamente quando encontra
        }
    }
	//printf("NAO\n");
    return -1;
}

int buscaLinear2(struct tLista *lista, float a) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (a == lista->itens[i]) {
            printf("SIM\n");
			return i; // Retorna imediatamente quando encontra
        }
    }
	printf("NAO\n");
    return -1;
}

// Desloca elementos para a direita a partir de um índice
void deslocaDir(struct tLista *lista, int ateh) {
    for (int j = lista->quantidade - 1; j >= ateh; j--) {
        lista->itens[j + 1] = lista->itens[j];
    }
}

// Insere um elemento na lista mantendo a ordem crescente
void inserir(struct tLista *lista, float a) {
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
void remover(struct tLista *lista, float a) {
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
void exibirLista(struct tLista *lista) {
    if (lista->quantidade == 0) {
        printf("\n");
        return;
    }
    for (int i = 0; i < lista->quantidade; i++) {
        if (i < lista->quantidade - 1) {
            printf("%f ", lista->itens[i]);
        } else {
            printf("%f", lista->itens[i]);
        }
    }
    printf("\n");
}


void imprimir(struct tLista *les)
{
    for (int i = 0; i < les->quantidade; i++)
        printf("%g%s", les->itens[i], i < les->quantidade - 1 ? " " : "\n");
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
    float a;

    scanf("%d", &n);
    struct tLista *lista = criaLista(n);


	//inserir(lista,50.1);
	//inserir(lista,80.2);
	//inserir(lista,20.3);
	//inserir(lista,30.4);
	//inserir(lista,60.5);
	//inserir(lista,90.6);
	//inserir(lista,50.1);
	//inserir(lista,50.2);
	//inserir(lista,10.7);
	//inserir(lista,40.8);
	//inserir(lista,80.2);
	//inserir(lista,70.0);
	//inserir(lista,100.0);
	//imprimir(lista);
	//
	//
	//buscaLinear2(lista,10.7);
	//buscaLinear2(lista,10.0);
	//buscaLinear2(lista,20.3);
	//buscaLinear2(lista,50.2);
	//buscaLinear2(lista,90.7);
	//buscaLinear2(lista,90.6);
	//remover(lista,50.1);
	//remover(lista,10.7);
	//remover(lista,100.0);
	//imprimir(lista);
	//
	//
	//buscaLinear2(lista,90.6);
	//buscaLinear2(lista,50.1);
	//buscaLinear2(lista,40.3);
	//buscaLinear2(lista,60.4);
	//remover(lista,40.0);
	//remover(lista,60.5);
	//remover(lista,50.2);
	//remover(lista,66.3);
	//imprimir(lista);



    while (scanf("\n%c", &comando) != EOF) { // Corrigido
        switch (comando) {
            case 'I':
                scanf("%f", &a);
                inserir(lista, a);
                break;
            case 'R':
                scanf("%f", &a);
                remover(lista, a);
                break;
            case 'M':
                //exibirLista(lista);
                imprimir(lista);
				break;
			case 'B':
                scanf("%f", &a);
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
