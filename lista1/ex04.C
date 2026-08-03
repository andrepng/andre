#include <stdio.h>

typedef struct {
    char nome[30];
    float nota;
    
} aluno;

int main() {
    aluno alunos[5];
    int i, aprovados;
    float media;
    
    for(i = 0; i < 5; i++){
        printf("digite nome do aluno: ");
        scanf("%s", &alunos[i].nome);
        
        printf("digite a nota do aluno: ");
        scanf("%f", &alunos[i].nota);
    }
    
        aprovados = 0;
        media = 0;
    
    for(i = 0; i < 5; i++){
        if(alunos[i].nota >= 7){
            aprovados = aprovados + 1;
        }
        
        media = media + alunos[i].nota;
        
            printf("nome: %s", alunos[i].nome);
            printf(" nota: %.1f\n", alunos[i].nota);
        
    }
    
            printf("aprovados: %d\n", aprovados);
            printf("nota média: %.1f", media / 5);
    
    return 0;
}