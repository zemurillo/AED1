#include <stdio.h>
#include <string.h>

int main() {
    char entrada[100];      // Buffer para armazenar a linha completa
    char universidade[51];  // Universidade (máx 50 caracteres + '\0')
    int anos;

    // Lê a linha completa usando fgets
    fgets(entrada, sizeof(entrada), stdin);

    // Remove o '\n' no final, se houver
    entrada[strcspn(entrada, "\n")] = 0;

    // Separa o nome da universidade e os anos
    sscanf(entrada, "%50s %d", universidade, &anos);

    // Exibe as mensagens conforme solicitado
    printf("Onde voce estuda:\n");
    printf("Quanto tempo:\n");
    printf("Voce estuda na %s ha %d anos.", universidade, anos);

    return 0;
}
