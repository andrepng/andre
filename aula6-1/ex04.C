#include <stdio.h>
#include <string.h>

struct aluno {
    char nome[50];
    float nota;
};

int main() {
    int n, i;

    printf("Quantidade de alunos: ");
    scanf("%d", &n);

    struct aluno alunos[n];

    float soma = 0, media;
    int maior = 0, menor = 0;
    int acimamedia = 0;

    for (i = 0; i < n; i++) {
        printf("\nAluno %d\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", alunos[i].nome);

        printf("Nota: ");
        scanf("%f", &alunos[i].nota);

        soma += alunos[i].nota;

        if (alunos[i].nota > alunos[maior].nota)
            maior = i;

        if (alunos[i].nota < alunos[menor].nota)
            menor = i;
    }

    media = soma / n;

    for (i = 0; i < n; i++) {
        if (alunos[i].nota >= 6.0)
            acimamedia++;
    }

    printf("\n===== BOLETIM =====\n");
    printf("%-20s %s\n", "Nome", "Nota");

    for (i = 0; i < n; i++) {
        printf("%-20s %.2f\n", alunos[i].nome, alunos[i].nota);
    }

    printf("\nMedia da turma: %.2f\n", media);

    printf("Maior nota: %s (%.2f)\n",
           alunos[maior].nome, alunos[maior].nota);

    printf("Menor nota: %s (%.2f)\n",
           alunos[menor].nome, alunos[menor].nota);

    printf("Alunos com nota maior ou igual a 6.0: %d\n", acimamedia);

    char busca[50];
    int encontrou = 0;

    printf("\nDigite o nome do aluno que deseja buscar: ");
    scanf(" %49[^\n]", busca);

    for (i = 0; i < n; i++) {
        if (strcmp(alunos[i].nome, busca) == 0) {
            printf("\nAluno encontrado!\n");
            printf("Nome: %s\n", alunos[i].nome);
            printf("Nota: %.2f\n", alunos[i].nota);
            encontrou = 1;
            break;
        }
    }

    if (encontrou == 0) {
        printf("\nAluno não encontrado.\n");
    }

    return 0;
}