#include <stdio.h>

int soma(int n);

int main() {
    int n;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Por favor, digite um número maior ou igual a zero.\n");
    } else {
        int resultado = soma(n);
        printf("A soma de 1 até %d é: %d\n", n, resultado);
    }

    return 0;
}

int soma(int n) {
    if (n == 0) {
        return 0;
    }
    
    return n + soma(n - 1);
}