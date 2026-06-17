#include <stdio.h>

typedef struct {
    char nome[50];
    float nota1; 
    float nota2; 
    float nota3;
} aluno;

float calcularmedia(aluno a){
    return (a.nota1 + a.nota2 + a.nota3) / 3; 
}
char definirconceito(float media){
    if(media < 6){
        return 'F';
    }
    else if(media < 7){
        return 'D';
    }
    else if(media < 8){
        return 'C';
    }
    else if(media < 9){
        return 'B';
    }
    else {
        return 'A';
    }
}
void imprimiraluno(aluno a){
    printf("aluno: %s\n", a.nome);
    printf("nota 1: %.1f ", a.nota1);
    printf("nota 2: %.1f ", a.nota2);
    printf("nota 3: %.1f ", a.nota3);
    printf("Média: %.1f ", calcularmedia(a));
    printf("conceito: %c\n", definirconceito(calcularmedia(a)));
}

int main() {
    aluno alunos[5];
    int i;
    
    for(i = 0; i < 5; i++){
        printf("digite nome do aluno: ");
        scanf("%s", alunos[i].nome);
        
        printf("digite a primeira nota do aluno: ");
        scanf("%f", &alunos[i].nota1);
        
        printf("digite a segunda nota do aluno: ");
        scanf("%f", &alunos[i].nota2);
        
        printf("digite a terceira nota do aluno: ");
        scanf("%f", &alunos[i].nota3);
    }
    for(i = 0; i < 5; i++){
        imprimiraluno(alunos[i]);
    }
    
}