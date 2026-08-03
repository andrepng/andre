#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int vitorias;
    int empates;
    int derrotas;
    int pontos;
} time;

void lertimes(time times[], int n);
void calcularpontos(time times[], int n);
void imprimirclassificacao(time times[], int n);
int encontrarlider(time times[], int n);

int main() {
    int n;

    printf("Digite a quantidade de times no torneio: ");
    scanf("%d", &n);

    time times[n];

    lertimes(times, n);
    calcularpontos(times, n);
    imprimirclassificacao(times, n);

    int indicelider = encontrarlider(times, n);
    printf("\nO time líder é: %s com %d pontos!\n", times[indicelider].nome, times[indicelider].pontos);

    return 0;
}

void lertimes(time times[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\n--- Time %d ---\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", times[i].nome);
        printf("Vitórias: ");
        scanf("%d", &times[i].vitorias);
        printf("Empates: ");
        scanf("%d", &times[i].empates);
        printf("Derrotas: ");
        scanf("%d", &times[i].derrotas);
        times[i].pontos = 0;
    }
}

void calcularpontos(time times[], int n) {
    for (int i = 0; i < n; i++) {
        times[i].pontos = (times[i].vitorias * 3) + (times[i].empates * 1);
    }
}

void imprimirclassificacao(time times[], int n) {
    printf("\n================ CLASSIFICAÇÃO ================\n");
    printf("%-20s | V | E | D | PTS\n", "Nome");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-20s | %d | %d | %d | %d\n", times[i].nome, times[i].vitorias, times[i].empates, times[i].derrotas, times[i].pontos);
    }
}

int encontrarlider(time times[], int n) {
    int indicemaior = 0;

    for (int i = 1; i < n; i++) {
        if (times[i].pontos > times[indicemaior].pontos) {
            indicemaior = i;
        }
    }

    return indicemaior;
}