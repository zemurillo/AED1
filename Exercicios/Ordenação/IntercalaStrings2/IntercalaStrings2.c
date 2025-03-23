#include <stdio.h>
#include <stdlib.h>

void IntercalaSubVetores(char v1[], int n1, char v2[], int n2, char aux[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (v1[i] <= v2[j]) {
            aux[k++] = v1[i++];
        } else {
            aux[k++] = v2[j++];
        }
    }

    while (i < n1) {
        aux[k++] = v1[i++];
    }
    while (j < n2) {
        aux[k++] = v2[j++];
    }

    aux[k] = '\0';  // Adicionando terminador de string
}

int main() {
    char s[20001];  // +1 para garantir espaço para '\0'
    int n, m;

    // Lendo a string com limite para evitar estouro de buffer
    if (scanf("%20000s", s) != 1) {
        printf("Erro na leitura da string\n");
        return 1;
    }

    // Lendo N e M e verificando se a leitura foi bem-sucedida
    if (scanf("%d %d", &n, &m) != 2) {
        printf("Erro na leitura de N e M\n");
        return 1;
    }

    // Alocando dinamicamente os vetores
    char *v1 = (char *)malloc((n + 1) * sizeof(char));
    char *v2 = (char *)malloc((m + 1) * sizeof(char));
    char *aux = (char *)malloc((n + m + 1) * sizeof(char));

    if (!v1 || !v2 || !aux) {
        printf("Erro na alocação de memória\n");
        free(v1); free(v2); free(aux);  // Liberação de memória em caso de falha
        return 1;
    }

    // Copiando as substrings manualmente
    for (int i = 0; i < n; i++) {
        v1[i] = s[i];
    }
    v1[n] = '\0';

    for (int j = 0; j < m; j++) {
        v2[j] = s[n + j];
    }
    v2[m] = '\0';

    // Chamando a função para intercalar as substrings
    IntercalaSubVetores(v1, n, v2, m, aux);

    // Imprimindo a string final
    printf("%s\n", aux);

    // Liberando memória alocada
    free(v1);
    free(v2);
    free(aux);

    return 0;
}






































//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//
//void IntercalaSubVetores(char v1[], int n1, char v2[], int n2, char aux[]){
//	
//	int i =0; 
//	int j =0;
//	int k = 0;
//	
//	while(i < n1 && j < n2){
//		if (v1[i]<= v2[j]){
//			
//			aux[k] = v1[i];
//			i++;
//		}
//		else{	
//			aux[k] = v2[j];
//			j++;
//		}
//		
//		k++;	
//	}
//	while(i < n1){
//		aux[k] = v1[i];
//		i++;
//		k++;	
//	}
//	while(j < n2){
//		aux[k] = v2[j];
//		j++;
//		k++;	
//	}
//
//	aux[k] = '\0';
//}
//int main(){
//	
//	char s[20000];
//	int n;
//	int m;
//	
//	
//	scanf("%s",s);
//	scanf("%d",&n);
//	scanf("%d",&m);
//	
//	char v1[n+1];
//	// copiando manualmente os primeiros caracteres
//	for (int i =0; i < n; i++){
//		v1[i] = s[i];	
//	}
//	v1[n] = '\0'; //terminador de string
//	
//	
//	char v2[m+1]; 
//	
//	for(int j = 0; j < m; j++){
//			v2[j] = s[j + n];
//	}
//	v2[m] = '\0'; //terminador de string
//	
//	//printf("v1 %s\n",v1);
//	//printf("v2 %s\n",v2);
//	
//	char aux[n + m + 1];
//	
//	IntercalaSubVetores(v1, n, v2, m,aux);
//	
//	printf("%s\n",aux);
//	
//	return 0;
//}