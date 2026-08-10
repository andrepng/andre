#include <stdio.h>
#include <string.h>

int contarchar(char s[50], int i, char c);

int main() {
    
    char palavra[50];
    char c;
    int i;
    int f;
        printf("Escreva uma palavra: ");
            scanf("%s", &palavra);
    
        printf("Digite o caractere: ");
            scanf(" %c", &c);
            
        printf("Digite a partir de qual casa: ");
        scanf("%d", &i);
    f= contarchar(palavra,i,c);
    printf("O número de caracteres encotrados é: %d", f);
};

int contarchar(char s[50], int i, char c) {
int num;
int letra;
 letra = 0;

    num = strlen(s);
    
    for(int n = i; n < num; n++) {
        if(s[n] == c) {
            letra++;
        }
        
    }
    return letra;
}