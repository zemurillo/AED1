#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tLista {
    char **itens;    // lista de ponteiros para strings
    int quantidade;  // Quantidade de itens na lista
    int tamanho;     // Tamanho máximo da lista
};

// Inicializa a lista com um tamanho específico
void iniciaLista(struct tLista* lista, int n) {
    lista->itens = (char**)malloc(n * sizeof(char*));  // Aloca espaço para ponteiros para strings
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
int buscaLinear(struct tLista *lista, char *a) {
    for (int i = 0; i < lista->quantidade; i++) {
        if (strcmp(a, lista->itens[i]) == 0) {  // Comparação de strings
            return i;  // Retorna o índice quando encontra a string
        }
    }
    return -1;  // Retorna -1 se não encontrar a string
}

// Desloca elementos para a direita a partir de um índice
void deslocaDir(struct tLista *lista, int ateh) {
    for (int j = lista->quantidade - 1; j >= ateh; j--) {
        lista->itens[j + 1] = lista->itens[j];  // Desloca os ponteiros
    }
}

//A função strcmp retorna um valor inteiro que pode ser:

//Menor que 0: Se str1 é lexicograficamente menor que str2.
//Igual a 0: Se as duas strings são idênticas.
//Maior que 0: Se str1 é lexicograficamente maior que str2.

// Insere um elemento na lista mantendo a ordem crescente
void inserir(struct tLista *lista, char *a) {
    int achei = 0;
    int i;

    if (lista->quantidade < lista->tamanho) {
        if (lista->quantidade == 0) {
            lista->itens[0] = (char*)malloc(strlen(a) + 1);  // Aloca memória para a string
            strcpy(lista->itens[0], a);  // Copia a string para a lista
            lista->quantidade++;
            return;
        }

        for (i = 0; i < lista->quantidade && achei == 0; i++) {
            if (strcmp(lista->itens[i], a) >= 0) {  // Comparação de strings
                achei = 1;
                if (strcmp(lista->itens[i], a) == 0) {  // Elemento já existe
                    return;
                } else {
                    deslocaDir(lista, i);
                    lista->itens[i] = (char*)malloc(strlen(a) + 1);  // Aloca memória para a nova string
                    strcpy(lista->itens[i], a);  // Copia a string para a lista
                }
            }
        }

        if (achei == 0) {  // Insere no final
            lista->itens[lista->quantidade] = (char*)malloc(strlen(a) + 1);  // Aloca memória para a string
            strcpy(lista->itens[lista->quantidade], a);  // Copia a string para a lista
        }

        lista->quantidade++;
    }
}

// Desloca elementos para a esquerda a partir de um índice
void deslocaEsq(struct tLista *lista, int de) {
    for (int j = de; j < lista->quantidade; j++) {
        lista->itens[j] = lista->itens[j + 1];  // Desloca os ponteiros
    }
}

// Remove um elemento da lista
void remover(struct tLista *lista, char *a) {
    if (lista->quantidade > 0) {
        int posicao = buscaLinear(lista, a);
        if (posicao != -1) {
            free(lista->itens[posicao]);  // Libera a memória da string
            deslocaEsq(lista, posicao);
            lista->quantidade--;
        }
    }
}

// Função para imprimir a lista
void imprimir(struct tLista *les) {
    for (int i = 0; i < les->quantidade; i++) {
        printf("%s", les->itens[i]);  // Exibe a string
        if (i < les->quantidade - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
}

// Função para liberar memória alocada
void liberarLista(struct tLista *lista) {
    for (int i = 0; i < lista->quantidade; i++) {
        free(lista->itens[i]);  // Libera a memória de cada string
    }
    free(lista->itens);  // Libera a memória do vetor de ponteiros
    free(lista);  // Libera a memória da lista
}

// Exemplo de uso
int main() {
    int n;
    char comando;
    char a[100];  // Buffer para a string de entrada

    scanf("%d", &n);
    struct tLista *lista = criaLista(n);

    while (scanf("\n%c", &comando) != EOF) {  // Lê o comando
        switch (comando) {
            case 'I':  // Inserir
                scanf("%s", a);  // Lê a string
                inserir(lista, a);
                break;
            case 'R':  // Remover
                scanf("%s", a);  // Lê a string
                remover(lista, a);
                break;
            case 'M':  // Imprimir
                imprimir(lista);
                break;
            case 'B':  // Buscar
                scanf("%s", a);  // Lê a string
                if (buscaLinear(lista, a) == -1) {
                    printf("NAO\n");
                } else {
                    printf("SIM\n");
                }
                break;
        }
    }

    liberarLista(lista);
    return 0;
}
