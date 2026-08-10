#include <stdio.h>

int buscaBinaria(int v[], int n, int alvo) {
    
int baixo = 0;
int alto = n - 1;
    while(baixo <= alto) {
        int meio = (baixo + alto) / 2; 
            if(v[meio] == alvo)
    return meio;
        if(v[meio] < alvo)
            baixo = meio + 1;
        else
            alto = meio - 1;
    }
    
    return -1;
}

int main () {
    int v[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = 8;
    int alvo;
        printf("Buscar: "); 
            scanf("%d", &alvo);
    int idx = buscaBinaria(v, n, alvo);
        if(idx >= 0)
            printf("Encontrado na posição %d \n", idx);
        else
            printf("Não encontrado.\n");
    return 0;
}
