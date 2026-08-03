#include <stdio.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
    float totalestoque;
};

void lerprodutos(struct Produto est[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        printf("\nProduto %d\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", est[i].nome);

        printf("Preco: ");
        scanf("%f", &est[i].preco);

        printf("Quantidade: ");
        scanf("%d", &est[i].quantidade);
    }
}

void calcularestoque(struct Produto est[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        est[i].totalestoque = est[i].preco * est[i].quantidade;
    }
}

void imprimirestoque(struct Produto est[], int n) {
    int i;
    float totalGeral = 0;

    printf("\n========= ESTOQUE =========\n");
    printf("%-20s %-10s %-12s %-15s\n",
           "Nome", "Preco", "Quantidade", "Total");

    for (i = 0; i < n; i++) {
        printf("%-20s %-10.2f %-12d %-15.2f\n", est[i].nome, est[i].preco, est[i].quantidade, est[i].totalestoque);

        totalGeral += est[i].totalestoque;
    }

    printf("\nValor total do estoque: %.2f\n", totalGeral);
}

int encontrarmaiorestoque(struct Produto est[], int n) {
    int i, maior = 0;

    for (i = 1; i < n; i++) {
        if (est[i].totalestoque > est[maior].totalestoque)
            maior = i;
    }

    return maior;
}

int encontrarmenorpreco(struct Produto est[], int n) {
    int i, menor = 0;

    for (i = 1; i < n; i++) {
        if (est[i].preco < est[menor].preco)
            menor = i;
    }

    return menor;
}

int main() {
    int n;

    printf("Quantidade de produtos: ");
    scanf("%d", &n);

    struct Produto est[n];

    lerprodutos(est, n);
    calcularestoque(est, n);
    imprimirestoque(est, n);

    int maior = encontrarmaiorestoque(est, n);
    int menor = encontrarmenorpreco(est, n);

    printf("\nProduto com maior valor em estoque: %s (%.2f)\n", est[maior].nome, est[maior].totalestoque);

    printf("Produto com menor preco: %s (%.2f)\n", est[menor].nome, est[menor].preco);

    return 0;
}