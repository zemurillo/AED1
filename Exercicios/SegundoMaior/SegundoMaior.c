#include
void LeVetor(int vetor[], int n) {
for (int i = 0; i < n; i++) {
scanf("%d", &vetor[i]);
}
}

void SegundoMaior(int vetor[], int n) {
int maior = vetor[0];
int p_maior = 0;

// Encontrando o maior elemento
for (int i = 1; i < n; i++) {
if (vetor[i] > maior) {
maior = vetor[i];
p_maior = i;
}
}

int segundo_maior;
int p_segundo_maior;

// Se o maior estiver na posição 0, comparamos o resto a partir da posição 1
if (p_maior == 0) {
p_segundo_maior = 1;
segundo_maior = vetor[1];
} else {
p_segundo_maior = 0;
segundo_maior = vetor[0];
}

// Encontrando o segundo maior elemento
for (int j = 0; j < n; j++) {
if (j != p_maior) { // Não compara com o maior
if (vetor[j] > segundo_maior) {
segundo_maior = vetor[j];
p_segundo_maior = j;
}
}
}

// Imprimindo a posição 0-based e o valor do segundo maior
printf("%d %d\n", p_segundo_maior, segundo_maior); // Posição 0-based
}

int main() {
int n;
scanf("%d", &n);

int vetor[n];
LeVetor(vetor, n);
SegundoMaior(vetor, n);

return 0;
}