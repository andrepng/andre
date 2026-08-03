#include <stdio.h>

int buscalinear(int v[], int n, int chave, int *comparacoes);
int buscabinaria(int v[], int n, int chave, int *comparacoes);

int main() {
    int TAM = 30;
    int vetor[30];

    for (int i = 0; i < TAM; i++) {
        vetor[i] = (i + 1) * 2;
    }

    int chave = vetor[TAM - 1]; 

    int complinear = 0;
    int compbinaria = 0;

    int poslinear = buscalinear(vetor, TAM, chave, &complinear);
    int posbinaria = buscabinaria(vetor, TAM, chave, &compbinaria);

    printf("Vetor: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n\n");

    printf("=== Elemento Procurado: %d ===\n\n", chave);

    printf("1. BUSCA LINEAR:\n");
    printf("   - Posição encontrada: %d\n", poslinear);
    printf("   - Número de comparações: %d\n\n", complinear);

    printf("2. BUSCA BINÁRIA:\n");
    printf("   - Posição encontrada: %d\n", posbinaria);
    printf("   - Número de comparações: %d\n\n", compbinaria);

    printf("Diferença: A busca binária precisou de %d comparações a menos!\n", 
           complinear - compbinaria);

    return 0;
}

int buscalinear(int v[], int n, int chave, int *comparacoes) {
    *comparacoes = 0;
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (v[i] == chave) {
            return i;
        }
    }
    return -1;
}

int buscabinaria(int v[], int n, int chave, int *comparacoes) {
    int inicio = 0;
    int fim = n - 1;
    *comparacoes = 0;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*comparacoes)++;

        if (v[meio] == chave) {
            return meio;
        }
        
        if (v[meio] < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}