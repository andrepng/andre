#include <stdio.h>

void imprimirmenu() {
    printf("\n=== CALCULADORA ===\n");
    printf("1. Calcular media de 3 notas\n");
    printf("2. Verificar se numero e primo\n");
    printf("3. Calcular potencia\n");
    printf("0. Sair\n");
    printf("Opcao: ");
}

float calcularmedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
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

int potencia(int base, int exp) {
    int resultado = 1;
    int i;

    for (i = 0; i < exp; i++) {
        resultado *= base;
    }

    return resultado;
}

int main() {
    int opcao;

    while (1) {
        imprimirmenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                float n1, n2, n3;

                printf("Digite as tres notas: ");
                scanf("%f %f %f", &n1, &n2, &n3);

                printf("Media: %.2f\n", calcularmedia(n1, n2, n3));
                break;
            }

            case 2: {
                int numero;

                printf("Digite um numero: ");
                scanf("%d", &numero);

                if (ehprimo(numero))
                    printf("O numero e primo.\n");
                else
                    printf("O numero nao e primo.\n");

                break;
            }

            case 3: {
                int base, expoente;

                printf("Digite a base: ");
                scanf("%d", &base);

                printf("Digite o expoente: ");
                scanf("%d", &expoente);

                printf("Resultado: %d\n", potencia(base, expoente));
                break;
            }

            case 0:
                printf("Programa encerrado.\n");
                return 0;

            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}