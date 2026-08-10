#include <stdio.h>

int somadigitos(int n);

int main() {
    int num;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Por favor, digite apenas números positivos.\n");
    } else {
        int resultado = somadigitos(num);
        printf("A soma dos dígitos de %d é: %d\n", num, resultado);
    }

    return 0;
}

int somadigitos(int n) {
    if (n == 0) {
        return 0;
    }

    return (n % 10) + somadigitos(n / 10);
}