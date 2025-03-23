#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void LeVetor(int v[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
}

// Função para imprimir o vetor com espaço entre os elementos
void printVetorEspaco(int v[], int n) {
    for (int j = 0; j < n; j++) {
        if (j != n - 1) {
            printf("%d ", v[j]);
        } else {
            printf("%d\n", v[j]);
        }
    }
}

void printVetor(int v[], int n) {
    for (int j = 0; j < n; j++){
            printf("%d\n", v[j]);
        }
}   


int Particiona(int v[], int n, int p){
	int pm = -1;
	
	// troca o pivot com o ultimo elemento do vetor
	int aux = v[n-1];
	v[n-1]  = v[p];
	v[p] = aux;
	
	// Faco a logica de partionamento
	for (int i = 0; i < n-1; i++){
		if (v[i] <= v[n-1]){
			pm++;
			aux = v[pm];
			v[pm] = v[i];
			v[i] = aux;
		}
		
		// colo o pivo no lugar
	}	
	aux = v[pm + 1];
	v[pm + 1] = v[n-1];
	v[n-1] = aux;
		
	return pm+1;
	
}

int main(){
	
	int q;
	int p;
	
	scanf("%d",&q);
	scanf("%d",&p);
	
	int v[q];
	
	LeVetor(v,q);
	
	Particiona(v,q,p);
	
	
	printVetor(v,q);
	
	return 0;
}