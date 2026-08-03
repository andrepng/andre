#include <stdio.h>

void imprimirvetor(int v[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

int particionar(int v[], int inicio, int fim, int n, int *passo) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }

    int temp = v[i + 1];
    v[i + 1] = v[fim];
    v[fim] = temp;

    int pospivo = i + 1;

    (*passo)++;
    printf("Passo %d (Pivô %d na pos %d): ", *passo, pivo, pospivo);
    imprimirvetor(v, n);

    return pospivo;
}

void quicksort(int v[], int inicio, int fim, int n, int *passo) {
    if (inicio < fim) { 
        int p = particionar(v, inicio, fim, n, passo);
        quicksort(v, inicio, p - 1, n, passo);
        quicksort(v, p + 1, fim, n, passo);
    }
}

int main() {
    int v[] = {33, 15, 10, 45, 20, 8, 50};
    int n = 7;
    int passo = 0;

    printf("Antes : ");
    imprimirvetor(v, n);
    printf("----------------------------------------\n");

    quicksort(v, 0, n - 1, n, &passo);

    printf("----------------------------------------\n");
    printf("Depois: ");
    imprimirvetor(v, n);

    return 0;
}