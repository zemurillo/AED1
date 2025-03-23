#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Nomicula (char nome[], char ra[], int tamN, int tamRA, char *aux){
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	while ( (i < tamN) && (j < tamRA)){
	
	aux[k] = nome[i];
	k++;
	aux[k] = ra[j];
	k++;
	
	i++;
	j++;
	}

	// Laço para passar o resto do nome se o RA ja acabou
	while ((i < tamN)){
		aux[k] = nome[i];
		i++;
		k++;	
	}
	// Laço para passar o resto do RA se o nome ja acabou
	while ((j < tamRA)){
		aux[k] = ra[j];
		j++;
		k++;	
	}
	
	 // Adiciona o terminador de string
    aux[k] = '\0';

}	


int main (){
	
	char nome[100];
	char ra[100];
	
	// Lê os valores até encontrar EOF
    int tamN;
	int tamRA;
    
	while (scanf("%s %s", nome, ra) != EOF) {
	
	tamN = strlen(nome);
	tamRA = strlen(ra);
	
	
	char *aux = (char *) malloc((tamN+tamRA + 1) * sizeof(char)); // + a para ter o espaço pro 0

	// Verifique se a alocação foi bem-sucedida
	if (aux == NULL) {
		printf("Erro ao alocar memória.\n");
		return 1;  // Termina o programa caso a alocação falhe
	}
		
	Nomicula(nome, ra, tamN, tamRA, aux);
	
	printf("%s\n",aux);
	
	free(aux);  // Lembre-se de liberar a memória alocada após o uso
	
    }
    

	return 0;
}