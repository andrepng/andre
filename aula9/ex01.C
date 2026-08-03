#include <stdio.h>

int maiorelemento(int v[], int n);

int main() {
    int n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Por favor, digite um tamanho maior que zero.\n");
        return 1;
    }

    int vetor[n];

    printf("\nDigite os %d números do vetor:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    int maior = maiorelemento(vetor, n);

    printf("\nVetor digitado: [ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");

    printf("O maior elemento do vetor é: %d\n", maior);

    return 0;
}

int maiorelemento(int v[], int n) {
    if (n == 1) {
        return v[0];
    }

    int maiordoresto = maiorelemento(v + 1, n - 1);

    if (v[0] > maiordoresto) {
        return v[0];
    } else {
        return maiordoresto;
    }
}
