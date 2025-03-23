#include <stdio.h>
#include <stdlib.h>

void fillUpVector(long int *v, long int N){
    for (int i = 0; i < N; i++) {
        scanf("%ld", &v[i]);
    }
}

void printVector(long int *v, long int q){
    for(int i = 0; i < q; i++){
        printf("%ld", v[i]);
        if(i != q-1) printf(" ");
        if(i == q-1) printf("\n");
    }
}

long int particiona(long int *v, long int e, long int d, long int N){
    
    int pm = e-1, i, aux;
    
    for(i = e; i < d; i++){
        
        if(v[i] <= v[d]){
            
            pm++;
            aux = v[pm];
            v[pm] = v[i];
            v[i] = aux;
        }
        
        printVector(v, N);
        
    }   
    
    aux = v[d];
    v[d] = v[pm + 1];
    v[pm + 1] = aux;
    
    printVector(v,N);
    
    return pm+1;
}

void quickSort(long int *v, long int e, long int d, long int N){
    
    long int p;
    
    if(e < d){
        p = particiona(v, e, d, N);
        quickSort(v, e, p-1, N);
        quickSort(v, p+1, d, N);
    }
}

int main()
{
    
    long int N;
    
    scanf("%ld", &N);
    
    long int *v = malloc(N * sizeof(long int));
    
    fillUpVector(v, N);
    
    printVector(v,N);
    
    quickSort(v, 0, N-1, N);
    
    printVector(v,N);
    
    free(v);
    
    return 0;
    
}