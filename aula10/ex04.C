#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jogoUsuarioAdivinha();
void jogoComputadorAdivinha();

int main() {
    int opcao;

    srand(time(NULL));

    do {
        printf("\n================ JOGO DA ADIVINHAÇÃO ================\n");
        printf("1 - Tentar adivinhar o número do computador\n");
        printf("2 - Fazer o computador adivinhar o seu número (Busca Binária)\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                jogoUsuarioAdivinha();
                break;
            case 2:
                jogoComputadorAdivinha();
                break;
            case 0:
                printf("\nSaindo... Até logo!\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

void jogoUsuarioAdivinha() {
    int numeroSecreto = (rand() % 100) + 1;
    int palpite = 0;
    int tentativas = 0;

    printf("\n--- MODO 1: Você Adivinha ---\n");
    printf("Pensei em um número entre 1 e 100. Tente adivinhar!\n");

    while (palpite != numeroSecreto) {
        printf("Seu palpite: ");
        scanf("%d", &palpite);
        tentativas++;

        if (palpite < numeroSecreto) {
            printf("-> O número secreto é MAIOR!\n");
        } else if (palpite > numeroSecreto) {
            printf("-> O número secreto é MENOR!\n");
        } else {
            printf("\n Parabéns! Você acertou o número %d em %d tentativas!\n", numeroSecreto, tentativas);
        }
    }
}

void jogoComputadorAdivinha() {
    int inicio = 1;
    int fim = 100;
    int tentativas = 0;
    char resposta;

    printf("\n--- MODO 2: Computador Adivinha (Busca Binária) ---\n");
    printf("Pense em um número de 1 a 100 e não me conte!\n");
    printf("Responda minhas perguntas com:\n");
    printf("  'm' para MENOR (se o seu número for menor que o meu palpite)\n");
    printf("  'M' para MAIOR (se o seu número for maior que o meu palpite)\n");
    printf("  'c' para CORRETO (se eu acertei)\n\n");

    while (inicio <= fim) {
        int palpite = (inicio + fim) / 2;
        tentativas++;

        printf("Tentativa %d: O seu número é %d? (m/M/c): ", tentativas, palpite);
        scanf(" %c", &resposta);

        if (resposta == 'c' || resposta == 'C') {
            printf("\n Acertei! O seu número é %d!\n", palpite);
            printf("Precisei de apenas %d tentativa(s)!\n", tentativas);
            return;
        } else if (resposta == 'm') {
            fim = palpite - 1;
        } else if (resposta == 'M') {
            inicio = palpite + 1;
        } else {
            printf("Entrada inválida. Digite 'm', 'M' ou 'c'.\n");
            tentativas--;
        }
    }

    printf("\nHum... Parece que houve algum engano nas respostas fornecidas!\n");
}