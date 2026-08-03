#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    float nota;
    
}   aluno;

int main() {
    int n;
    aluno alunos[n];
    int maiornota = -1;
    int menornota = -1;
    float valor_maiornota = 0;
    float valor_menornota = 1000;

        printf("Digite o numero de alunos: ");
        scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nDigite o nome do aluno %d: ", i + 1);
        scanf(" %49s", alunos[i].nome); 

        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota);

    }

    for(int i = 0; i < n; i++) {
        if(alunos[i].nota > valor_maiornota) {
            maiornota = i;
            valor_maiornota = alunos[i].nota;
        }
        
        if(alunos[i].nota < valor_menornota) {
            menornota = i;
            valor_menornota = alunos[i].nota;
            
        }
    }

        printf("\nO aluno com a menor nota é: %s\n", alunos[menornota].nome);
        printf("O aluno com a maior nota é: %s\n", alunos[maiornota].nome);
    
    return 0;
}