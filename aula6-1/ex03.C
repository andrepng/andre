#include <stdio.h>

struct Jogador {
    char nome[50];
    int pontos;
    int vitorias;
};

int main() {
    int n, i;

    printf("Quantidade de jogadores: ");
    scanf("%d", &n);

    struct Jogador jogadores[n];

    int maisPontos = 0, maisVitorias = 0;
    int somaVitorias = 0, acimaMedia = 0;
    float mediaVitorias;

    for (i = 0; i < n; i++) {
        printf("\nJogador %d\n", i + 1);

        printf("Nome: ");
        scanf(" %49[^\n]", jogadores[i].nome);

        printf("Pontos: ");
        scanf("%d", &jogadores[i].pontos);

        printf("Vitorias: ");
        scanf("%d", &jogadores[i].vitorias);

        somaVitorias += jogadores[i].vitorias;

        if (jogadores[i].pontos > jogadores[maisPontos].pontos)
            maisPontos = i;

        if (jogadores[i].vitorias > jogadores[maisVitorias].vitorias)
            maisVitorias = i;
    }

    mediaVitorias = (float)somaVitorias / n;

    for (i = 0; i < n; i++) {
        if (jogadores[i].vitorias > mediaVitorias)
            acimaMedia++;
    }

    printf("\n========= RANKING =========\n");
    printf("%-20s %-10s %-10s\n", "Nome", "Pontos", "Vitorias");

    for (i = 0; i < n; i++) {
        printf("%-20s %-10d %-10d\n", jogadores[i].nome, jogadores[i].pontos, jogadores[i].vitorias);
    }

    printf("\nJogador com mais pontos: %s (%d pontos)\n",
           jogadores[maisPontos].nome, jogadores[maisPontos].pontos);

    printf("Jogador com mais vitorias: %s (%d vitorias)\n",
           jogadores[maisVitorias].nome, jogadores[maisVitorias].vitorias);

    printf("Media de vitorias: %.2f\n", mediaVitorias);

    printf("Jogadores com mais vitorias que a media: %d\n", acimaMedia);

    return 0;
}