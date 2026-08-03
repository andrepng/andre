#include <stdio.h>

int somavetordivconq(int v[], int inicio, int fim);
int somavetoriterativa(int v[], int n);

int main() {
    int n = 5;
    int vetor[5];

    printf("Digite %d números inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    int somarecursiva = somavetordivconq(vetor, 0, n - 1);

    int somaiterativa = somavetoriterativa(vetor, n);

    printf("\n=== Resultados ===\n");
    printf("Soma (Dividir para Conquistar): %d\n", somarecursiva);
    printf("Soma (Laço FOR iterativo)     : %d\n", somaiterativa);

    if (somarecursiva == somaiterativa) {
        printf("\n Os dois métodos retornaram o mesmo resultado!\n");
    } else {
        printf("\n Houve uma divergência nos cálculos.\n");
    }

    return 0;
}

int somavetordivconq(int v[], int inicio, int fim) {
    if (inicio > fim) {
        return 0;
    }
    
    if (inicio == fim) {
        return v[inicio];
    }

    int meio = (inicio + fim) / 2;

    int somaesquerda = somavetordivconq(v, inicio, meio);
    int somadireita  = somavetordivconq(v, meio + 1, fim);

    return somaesquerda + somadireita;
}

int somavetoriterativa(int v[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma;
}