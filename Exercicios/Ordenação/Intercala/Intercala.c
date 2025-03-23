#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LeVetor(int v[], int n);
void printVetor(int v[], int n);
void Intercala(int q1, int q2, int v1[], int v2[], int aux[]);

void LeVetor(int v[], int n) {
    for (int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
}

void printVetor(int v[], int n) {
    for (int j = 0; j < n; j++){
            printf("%d\n", v[j]);
        }
    }   


void Intercala(int q1, int q2, int v1[], int v2[], int aux[]){
		int i=0;
		int j=0;
		int k = 0;
		
		while(i < q1 && j < q2){
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
		
		// Copia um dos vetores que acabou
		while(i < q1){
			aux[k] = v1[i];
			i++;
			k++;
	
		}
		while(j<q2){
			aux[k] = v2[j];
			j++;
			k++;
		}	
}


int main(){
	int q1;
	int q2;
	
	scanf("%d",&q1);
	scanf("%d",&q2);
	
	int v1[q1];
	int v2[q2];
	int aux[q1+q2];
	
	LeVetor(v1,q1);
	LeVetor(v2,q2);
	
	Intercala(q1, q2, v1, v2, aux);
	
	printVetor(aux, q1 + q2);
	
	
return 0;	
}




