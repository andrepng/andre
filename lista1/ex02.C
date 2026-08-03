#include <stdio.h>

typedef struct {
    char time1[50];
    char time2[50];
    int gols1, gols2;
    
} placar;
    
int main() {
    placar p;
    
        printf("digite o nome do primeiro time: ");
        scanf("%49s", p.time1);
        printf("digite o nome do segundo time: ");
        scanf("%49s", p.time2);
        printf("digite o placar do jogo: ");
        scanf("%d %d", &p.gols1, &p.gols2);
    
    if(p.gols1==p.gols2){
        printf("empate");
    }
    else if(p.gols1>p.gols2){
        printf("%s ganhou", p.time1);
    }
    else{
        printf("%s ganhou", p.time2);
    }
    
    return 0;
}