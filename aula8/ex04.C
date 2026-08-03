#include <stdio.h>

int fibonacci(int n);

int main() {
    int inicio;

    printf("Digite o termo inicial da sequência (Número inteiro sem ser negativo): ");
    scanf("%d", &inicio);

    if (inicio < 0) {
        printf("Por favor, digite um número inteiro maior ou igual a zero.\n");
    } else {
        printf("\n=== 10 termos de Fibonacci a partir do termo %d ===\n", inicio);
        
        for (int i = inicio; i < inicio + 10; i++) {
            printf("%d ", fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}