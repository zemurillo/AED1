#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

// Pq estava dando erro?

// Tinha que adicionar + 1 no tamanho das strings para colocar o terminador de strings e nao dar erro


void IntercalaStrings(char v1[], int n1, char v2[], int n2, char aux[]){
	
	int i=0;
	int j=0;
	int k = 0;
	
	while (i < n1 && j < n2){
		
		if (v1[i] <= v2[j]){
			aux[k] = v1[i];
			i++;
		}
		else{
			aux[k] = v2[j];
			j++;
		}
		k++;
	}	
	// Se o v1 não acabou, copiar
	while(i < n1){
		aux[k] = v1[i];
		i++;
		k++;
	}
	// Se o v2 não acabar, copiar
	while(j < n2){
		aux[k] = v2[j];
		j++;
		k++;	
	}
	// adiciona o terminador de string
	aux[k] = '\0';
}

int main(){
	int n1;
	int n2;
	
	scanf("%d",&n1);
	char v1[n1+1];
	scanf("%s",v1);
	
	scanf("%d",&n2);
	char v2[n2+1];
	scanf("%s",v2);
	
	char aux[n1 + n2 +1];//char aux[n1 + n2 + 1];
	
	IntercalaStrings(v1, n1, v2, n2,aux);
	
	printf("%s\n",aux);
	

	return 0;	
}


