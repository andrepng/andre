#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float nota;
    
}   aluno;

int main() {
    int n;
    aluno alunos[n];
    float somanotas = 0.0;

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nDigite o nome do aluno %d: ", i + 1);
        scanf(" %49s", alunos[i].nome); 

        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);

        somanotas += alunos[i].nota;
    }

    float media = 6.0;

    int acimadamedia = 0;

    printf("\n--- TABELA DE NOTAS ---\n");
    printf("%-20s | %s\n", "Nome", "Nota");
    printf("-----------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-20s | %.2f\n", alunos[i].nome, alunos[i].nota);

        if (alunos[i].nota > media) {
            acimadamedia++;
        }
    }
    printf("-----------------------------\n");

    printf("Media da turma: %.2f\n", somanotas / n);
    printf("Alunos acima da media: %d\n", acimadamedia);

    return 0;
}