#include <stdio.h>

int potencia(int base, int exp);

int main() {
    int base, exp;

    printf("Digite a base: ");
    scanf("%d", &base);
    
    printf("Digite o expoente (>= 0): ");
    scanf("%d", &exp);

    if (exp < 0) {
        printf("Por favor, digite um expoente maior ou igual a zero.\n");
    } else {
        int resultado = potencia(base, exp);
        printf("%d elevado a %d é: %d\n", base, exp, resultado);
    }

    return 0;
}

int potencia(int base, int exp) {
    if (exp == 0) {
        return 1;
    }
    
    return base * potencia(base, exp - 1);
}