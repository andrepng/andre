#include <stdio.h>

void regressiva(int n);
void progressiva(int n);

int main() {
    int n = 5;
    
    printf("Digite um Número: ");
    scanf("%d", &n);

    printf("=== Contagem Regressiva ===\n");
    regressiva(n);

    printf("\n=== Contagem Progressiva ===\n");
    progressiva(n);
    printf("\n");

    return 0;
}

void regressiva(int n) {
    if (n <= 0) {
        printf("Vai!\n");
        return;
    }
    
    printf("%d ", n);
    regressiva(n - 1);
}

void progressiva(int n) {
    if (n <= 0) {
        return;
    }
    
    progressiva(n - 1);
    
    printf("%d ", n);
}