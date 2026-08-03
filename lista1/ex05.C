#include <stdio.h>

typedef struct {
    char nome[20];
    float preco;
    int qtd;
    
} produto;

    int main(){
        produto produtos[5];
        int i, i_maiorvalor;
        float valor_total, maior_valor;
        
    for(i = 0; i < 5; i++){
        printf("digite nome do produto: ");
        scanf("%s", &produtos[i].nome);
        
        printf("digite valor do produto: ");
        scanf("%f", &produtos[i].preco);
        
        printf("digite quantidade do produto: ");
        scanf("%d", &produtos[i].qtd);
    
    }
    
    valor_total = 0;
    maior_valor = 0;
    i_maiorvalor = 0;
    
    for(i = 0; i < 5; i++){
        printf("nome: %s", produtos[i].nome);
        printf(" preço: %.2f", produtos[i].preco);
        printf(" quantidade: %d", produtos[i].qtd);
        printf(" total:  %.2f\n", produtos[i].preco * produtos[i].qtd);
    
        valor_total = valor_total + (produtos[i].preco * produtos[i].qtd);
    
        if(produtos[i].preco * produtos[i].qtd >= maior_valor){
            maior_valor = produtos[i].preco * produtos[i].qtd;
            i_maiorvalor = i;
        }
    
    }
    
    printf("valor total geral: %.2f\n", valor_total);
    printf("%s ", produtos[i_maiorvalor].nome);
    printf("maior valor: %.2f", maior_valor);

    return 0;
}