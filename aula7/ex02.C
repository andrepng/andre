#include <stdio.h>

float calcularmedia(float n1, float n2, float n3) {
    return (n1 + n2 + n3) / 3;
}

char definirconceito(float media) {
    if (media >= 9)
        return 'A';
    else if (media >= 7)
        return 'B';
    else if (media >= 5)
        return 'C';
    else
        return 'D';
}

void imprimirsituacao(char nome[], float media, char conceito) {
    printf("%-20s Media: %.2f Conceito: %c\n", nome, media, conceito);
}

int main() {
    int i;
    char nome[50];
    float n1, n2, n3, media;
    char conceito;

    for (i = 0; i < 3; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", nome);

        printf("Nota 1: ");
        scanf("%f", &n1);

        printf("Nota 2: ");
        scanf("%f", &n2);

        printf("Nota 3: ");
        scanf("%f", &n3);

        media = calcularmedia(n1, n2, n3);
        conceito = definirconceito(media);

        imprimirsituacao(nome, media, conceito);
    }

    return 0;
}