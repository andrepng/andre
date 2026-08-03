#include <stdio.h>

int somadigitos(int n);

int main() {
    int numero;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("Por favor, digite apenas números positivos.\n");
    } else {
        int resultado = somadigitos(numero);
        printf("A soma dos dígitos de %d é: %d\n", numero, resultado);
    }

    return 0;
}

int somadigitos(int n) {
    if (n == 0) {
        return 0;
    }

    return (n % 10) + somadigitos(n / 10);
}
