#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float altura;
} pessoa;

int main() {
    pessoa p;

        scanf("%s", p.nome);
        scanf("%d", &p.idade);
        scanf("%f", &p.altura);

        printf("nome: %s\n", p.nome);
        printf("idade: %d\n", p.idade);
        printf("altura: %.2f\n", p.altura);
    
    return 0;
}
