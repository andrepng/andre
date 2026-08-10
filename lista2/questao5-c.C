//Opção C — Busca binária recursiva. Implemente int buscaBinariaRec(int v[], int
//ini, int fim, int alvo) em um vetor ordenado, usando recursão em vez do laço while.

#include <stdio.h>

int buscaBinariaRec(int v[], int ini, int fim, int alvo) {
    
int meio;    
    if (ini == fim){
        if (v[ini] == alvo)   {
            return ini;
        }
        else {
            return -1;
        }
    }
    else {
        meio = (fim + ini) / 2;
        if (v[meio] == alvo)   {
            return meio;
        }
        else {
            if (v[meio] < alvo)   {  
                return buscaBinariaRec(v, meio+1, fim, alvo);
            }
            else {  
                return buscaBinariaRec(v, ini, meio-1, alvo);
            }
            
        }
    }
    
}

int main () {
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = 8;
    int alvo;
        printf("Buscar: "); 
            scanf("%d", &alvo);
    int idx = buscaBinariaRec(v, 0, n-1, alvo);
        if(idx >= 0)
            printf("Encontrado na posição %d \n", idx);
        else
            printf("Não encontrado.\n");
    return 0;
}