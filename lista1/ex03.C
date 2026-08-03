#include <stdio.h>

typedef struct {
    char nome[50];
    float preco;
    int qtd;
} produto;

int main() {
    float preco_estoque;
    produto p;
    
        printf("digite o nome do produto: ");
        scanf("%49s", p.nome);
        printf("digite o preço do produto: ");
        scanf("%f", &p.preco);
        printf("digite a quantidade do produto: ");
        scanf("%d", &p.qtd);
        
    preco_estoque = p.preco * p.qtd;
    
        printf("/----------------------------------------------------------------------/\n");
        printf("nome do produto: %s\n", p.nome);
        printf("quantidade do produto: %d\n", p.qtd);
        printf("preço do produto: R$%.2f\n", p.preco);
        printf("preço total em estoque: R$%.2f\n", preco_estoque);
        printf("preço total com desconto: R$%.2f\n", preco_estoque * 0.9);
        printf("/----------------------------------------------------------------------/\n");
        
    return 0;
}