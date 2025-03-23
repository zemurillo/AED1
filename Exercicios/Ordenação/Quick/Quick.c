#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void LeVetor(int v[], int n);
void printVetorEspaco(int v[], int n);
void printVetor(int v[], int n);

void quickSort(int v[],int n, int inicio, int fim);
int Particiona(int v[],int n,int inicio, int fim);

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


// Logica --> Particiono o vetor, pego o pivo, chamo o quicksort para os dois lados do vetor, antes e depois do pivo
void quickSort(int v[],int n, int inicio, int fim){

		int p;
		
		if (inicio < fim){
			
			p = Particiona(v,n,inicio,fim);
			
			quickSort(v,n,inicio, p-1);
			quickSort(v,n,p+1,fim);	
		}
}


int Particiona(int v[],int n,int inicio, int fim){
	
	int pm = inicio -1;
	int aux;
	// com o pivot sendo o ultimo
	for (int i = inicio; i < fim; i++){
		
		if (v[i] <= v[fim]){
			pm++;
			aux = v[pm];
			v[pm] = v[i];
			v[i] = aux;
		}
		printVetorEspaco(v,n);
		
	}
	
	// Coloca o pivo no lugar (posicao pm + 1 troca com posicao v[fim]
	aux = v[pm+1];
	v[pm+1] = v[fim];
	v[fim] = aux;

	printVetorEspaco(v,n);
	
	return pm+1;
	
}

int main(){
	
	int n;
	
	scanf("%d",&n);
	
	int v[n];
	
	LeVetor(v,n);
	
	printVetorEspaco(v,n);
	
	quickSort(v,n,0,n-1);
	
	printVetorEspaco(v,n);
	
	
	return 0;
}