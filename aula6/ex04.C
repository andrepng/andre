#include <stdio.h>

struct produto {
    char nome[50];
    float preco;
    int quantidade;
};

int main() {
    int n, i;
    float totalgeral = 0;
    float maiorvalor = 0;
    int indicemaior = 0;

    printf("Digite a quantidade de produtos: ");
    scanf("%d", &n);

    struct produto produtos[n];

    for (i = 0; i < n; i++) {
        printf("\nProduto %d\n", i + 1);

        printf("Nome: ");
        scanf("%s", produtos[i].nome);

        printf("Preco: ");
        scanf("%f", &produtos[i].preco);

        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
    }

    printf("\n%-15s %-10s %-10s %-10s\n", "Produto", "Preco", "Qtd", "Total");
    printf("----------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        float total = produtos[i].preco * produtos[i].quantidade;

        printf("%-15s R$%7.2f %6d R$%8.2f\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidade, total);

        totalgeral += total;

        if (i == 0 || total > maiorvalor) {
            maiorvalor = total;
            indicemaior = i;
        }
    }

    printf("----------------------------------------------------------\n");
    printf("Total geral: R$%.2f\n", totalgeral);
    printf("Maior estoque: %s (R$%.2f)\n", produtos[indicemaior].nome, maiorvalor);

    return 0;
}