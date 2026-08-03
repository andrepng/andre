#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float n1, n2, n3;
    float media;
    char conceito;
} aluno;

void lerturma(aluno turma[], int n);
void calcularmediasturma(aluno turma[], int n);
void ordenarpormedia(aluno turma[], int n);
void imprimirturma(aluno turma[], int n);
int encontrardestaque(aluno turma[], int n);
aluno calcularmedia(aluno a);
aluno definirconceito(aluno a);

int main() {
    int n;
    printf("Quantos alunos? ");
    scanf("%d", &n);

    aluno turma[n];

    lerturma(turma, n);
    calcularmediasturma(turma, n);
    
    ordenarpormedia(turma, n);

    imprimirturma(turma, n);

    int dest = encontrardestaque(turma, n);
    printf("\nDestaque: %s (%.1f)\n", turma[dest].nome, turma[dest].media);

    return 0;
}


void lerturma(aluno turma[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Aluno %d ---\n", i + 1);
        printf("Nome: "); 
        scanf(" %49s", turma[i].nome);
        printf("N1: "); 
        scanf("%f", &turma[i].n1);
        printf("N2: "); 
        scanf("%f", &turma[i].n2);
        printf("N3: "); 
        scanf("%f", &turma[i].n3);
    }
}

aluno calcularmedia(aluno a) {
    a.media = (a.n1 + a.n2 + a.n3) / 3.0f;
    return a;
}

aluno definirconceito(aluno a) {
    if (a.media >= 9.0) 
        a.conceito = 'A';
    else if (a.media >= 7.0) 
        a.conceito = 'B';
    else if (a.media >= 5.0) 
        a.conceito = 'C';
    else 
        a.conceito = 'D';
    
    return a;
}

void calcularmediasturma(aluno turma[], int n) {
    for (int i = 0; i < n; i++) {
        turma[i] = calcularmedia(turma[i]);
        turma[i] = definirconceito(turma[i]);
    }
}

void ordenarpormedia(aluno turma[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int imaior = i;
        for (int j = i + 1; j < n; j++) {
            if (turma[j].media > turma[imaior].media) {
                imaior = j;
            }
        }

        aluno temp = turma[i];
        turma[i] = turma[imaior];
        turma[imaior] = temp;
    }
}

void imprimirturma(aluno turma[], int n) {
    printf("\n%-20s %5s %10s %10s\n", "NOME", "MEDIA", "CONCEITO", "SITUACAO");
    printf("---------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        char *sit = (turma[i].conceito == 'D') ? "Reprovado" : "Aprovado";
        printf("%-20s %5.1f %8c %11s\n", turma[i].nome, turma[i].media, turma[i].conceito, sit);
    }
    
    printf("---------------------------------------------------\n");
}

int encontrardestaque(aluno turma[], int n) {
    int imaior = 0;
    for (int i = 1; i < n; i++) {
        if (turma[i].media > turma[imaior].media) {
            imaior = i;
        }
    }
    return imaior;
}