#include <stdio.h>

typedef struct {
    char nome[50];
    float valor;
    int qtd;
} produto;

int main() {
    float valor_estoque;
    produto p;
    
        printf("Digite o nome do produto: ");
        scanf("%49s", p.nome);
        printf("Digite o valor do produto: ");
        scanf("%f", &p.valor);
        printf("Digite a quantidade do produto: ");
        scanf("%d", &p.qtd);
        
    valor_estoque = p.valor * p.qtd;
    
        printf("/----------------------------------------------------------------------/\n");
        printf("Nome do produto: %s\n", p.nome);
        printf("Valor do produto: R$%.2f\n", p.valor);
        printf("Quantidade do produto: %d\n", p.qtd);
        printf("Valor total em estoque: R$%.2f\n", valor_estoque);
        printf("/----------------------------------------------------------------------/\n");
        
    return 0;
}