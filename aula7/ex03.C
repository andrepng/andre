#include <stdio.h>

int potencia(int base, int exp) {
    int resultado = 1;
    int i;

    for (i = 0; i < exp; i++) {
        resultado *= base;
    }

    return resultado;
}

int fatorial(int n) {
    int fat = 1;
    int i;

    for (i = 1; i <= n; i++) {
        fat *= i;
    }

    return fat;
}

int ehprimo(int n) {
    int i;

    if (n < 2)
        return 0;

    for (i = 2; i < n; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int main() {
    int numero;

    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);

    printf("\nPotencia ao quadrado: %d\n", potencia(numero, 2));
    printf("Fatorial: %d\n", fatorial(numero));

    if (ehprimo(numero))
        printf("O numero e primo.\n");
    else
        printf("O numero nao e primo.\n");

    return 0;
}