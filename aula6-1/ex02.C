#include <stdio.h>

struct produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    int n, i;

    printf("Quantidade de produtos: ");
    scanf("%d", &n);

    struct produto produtos[n];

    int maiorvalor = 0, menorpreco = 0;
    float valortotalestoque = 0;

    for (i = 0; i < n; i++) {
        printf("\nProduto %d\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", produtos[i].nome);

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);

        float valor = produtos[i].preco * produtos[i].quantidade;
        valortotalestoque += valor;

        if (valor > produtos[maiorvalor].preco * produtos[maiorvalor].quantidade)
            maiorvalor = i;

        if (produtos[i].preco < produtos[menorpreco].preco)
            menorpreco = i;
    }

    printf("\n========== ESTOQUE ==========\n");
    printf("%-20s %-10s %-12s %-15s\n", "Nome", "Preco", "Quantidade", "Valor Estoque");

    for (i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-12d %-15.2f\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade, produtos[i].preco * produtos[i].quantidade);
    }

    printf("\nProduto com maior valor em estoque: %s (R$ %.2f)\n",
           produtos[maiorvalor].nome, produtos[maiorvalor].preco * produtos[maiorvalor].quantidade);

    printf("Produto com menor preco unitario: %s (R$ %.2f)\n",
           produtos[menorpreco].nome, produtos[menorpreco].preco);

    printf("Valor total do estoque: R$ %.2f\n", valortotalestoque);

    return 0;
}