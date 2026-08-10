#include <stdio.h>
#include <string.h>

void inverter(char s[], int ini, int fim);
int ehPalindromo(char s[], int ini, int fim);

void main() {
    char str[100];
    
    printf("Digite uma palavra: ");
    scanf(" %[^\n]", str);
    
    if (ehPalindromo(str,0,0) == 1){
    printf("é palindromo");
    }
    else {
        printf("não é palindromo");
    }
}

int ehPalindromo(char s[], int ini, int fim){
char invertida[100];    
    
    strcpy(invertida,s);

    int tamanho = strlen(invertida);

    inverter(invertida, 0, tamanho - 1);
    
    if (strcmp(invertida, s) == 0) {
        return 1;
    }
    else {
        return 0;
    }
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