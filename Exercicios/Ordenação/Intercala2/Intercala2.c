#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void LeVetor(int v[], int in, int fn);
void printVetor(int v[], int n);
void Intercala(int q1, int q2, int v1[], int aux[]);

void LeVetor(int v[], int in, int fn) {
    for (int i = in; i < fn; i++){
        scanf("%d", &v[i]);
    }
}

void printVetor(int v[], int n) {
    for (int j = 0; j < n; j++){
            printf("%d\n", v[j]);
        }
    }   


void Intercala(int q1, int q2, int v1[], int aux[]){
		int i=0;
		int j= q1;
		int k = 0;
		
		while(i < q1 && j < q1 + q2){
			if (v1[i] <= v1[j]){
				aux[k] = v1[i];
				i++;
			}
			else{
				aux[k] = v1[j];
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
		while(j<q2 + q1){
			aux[k] = v1[j];
			j++;
			k++;
		}	
}


int main(){
	int q1;
	int q2;
	
	scanf("%d",&q1);
	scanf("%d",&q2);
	
	int v1[q1 + q2];
	int aux[q1+q2];
	
	LeVetor(v1,0,q1);
	LeVetor(v1,q1,q1 + q2);
	
	Intercala(q1, q2, v1,aux);
	
	//printf("Printando vetor:\n");
	
	//printf("%s\n",v1);
	+
	//printf("Printando vetor:\n");
	
	
	printVetor(aux, q1 + q2);
	
	
return 0;	
}