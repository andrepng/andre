#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float nota;
} aluno;

void trocar(aluno *a, aluno *b) {
    aluno temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(aluno v[], int inicio, int fim) {
    float pivo = v[fim].nota;
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j].nota >= pivo) {
            i++;
            trocar(&v[i], &v[j]);
        }
    }

    trocar(&v[i + 1], &v[fim]);

    return i + 1;
}

void quicksortalunos(aluno v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(v, inicio, fim);
        quicksortalunos(v, inicio, p - 1);
        quicksortalunos(v, p + 1, fim);
    }
}

void imprimiralunos(aluno v[], int n) {
    printf("\n%-20s | %s\n", "Nome", "Nota");
    printf("-----------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s | %.2f\n", v[i].nome, v[i].nota);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Quantidade inválida de alunos.\n");
        return 1;
    }

    aluno alunos[n];

    for (int i = 0; i < n; i++) {
        printf("\n--- Cadastrando Aluno %d ---\n", i + 1);
        
        printf("Nome do aluno: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Nota do aluno: ");
        scanf("%f", &alunos[i].nota);
    }

    quicksortalunos(alunos, 0, n - 1);

    printf("\n=================================");
    printf("\n=== RANKING FINAL (DECRESCENTE) ===");
    printf("\n=================================");
    imprimiralunos(alunos, n);

    return 0;
}