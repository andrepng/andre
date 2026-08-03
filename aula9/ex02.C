#include <stdio.h>
#include <string.h>

void inverter(char s[], int ini, int fim);

int main() {
    char str[100];

    printf("Digite uma palavra ou frase: ");
    scanf(" %[^\n]", str);

    int tamanho = strlen(str);

    inverter(str, 0, tamanho - 1);

    printf("String invertida: %s\n", str);

    return 0;
}

void inverter(char s[], int ini, int fim) {
    if (ini >= fim) {
        return;
    }

    char temp = s[ini];
    s[ini] = s[fim];
    s[fim] = temp;

    inverter(s, ini + 1, fim - 1);
}