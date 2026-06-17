#include <stdio.h>

typedef struct {
    char nome[50];
    int pontos;
    
} jogador;

int main() {
    jogador jogadores[5];
    int i, i_maiorpont, i_menorpont; 
    int maior_pont, menor_pont;
    
    for(i = 0; i < 5; i++){
        printf("digite o nome do jogador: ");
        scanf("%s", &jogadores[i].nome);
        
        printf("digite quantos pontos o jogador fez: ");
        scanf("%d", &jogadores[i].pontos);
    }
        maior_pont = 0;
        menor_pont = 1000;
        i_maiorpont = 0;
        i_menorpont = 0;
    
    for(i = 0; i < 5; i++){
        if(jogadores[i].pontos > maior_pont){
            maior_pont = jogadores[i].pontos;
            i_maiorpont = i;
        }
        if(jogadores[i].pontos < menor_pont){
            menor_pont = jogadores[i].pontos;
            i_menorpont = i;
        }
    }
    
    printf("maior pontuador: %s, pontos: %d\n", jogadores[i_maiorpont].nome, jogadores[i_maiorpont].pontos);
    printf("menor pontuador: %s, pontos: %d\n", jogadores[i_menorpont].nome, jogadores[i_menorpont].pontos);
    
    return 0;
}