#include <stdio.h>

int compquicksort = 0;
int compselection = 0;


int particionar(int v[], int inicio, int fim) {
    int pivo = v[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        compquicksort++;
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

    return i + 1;
}

void quicksort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(v, inicio, fim);
        quicksort(v, inicio, p - 1);
        quicksort(v, p + 1, fim);
    }
}


void selectionsort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minidx = i;
        for (int j = i + 1; j < n; j++) {
            compselection++;
            if (v[j] < v[minidx]) {
                minidx = j;
            }
        }
        int temp = v[minidx];
        v[minidx] = v[i];
        v[i] = temp;
    }
}


void imprimirvetor(int v[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}

int main() {
    int n = 10;
    
    int vquicksort[] = {42, 15, 88, 10, 27, 3, 99, 50, 31, 19};
    int vselection[] = {42, 15, 88, 10, 27, 3, 99, 50, 31, 19};

    printf("Vetor inicial: ");
    imprimirvetor(vquicksort, n);
    printf("----------------------------------------\n");

    quicksort(vquicksort, 0, n - 1);
    selectionsort(vselection, n);

    printf("1. QUICKSORT:\n");
    printf("   - Vetor ordenado: ");
    imprimirvetor(vquicksort, n);
    printf("   - Total de comparações: %d\n\n", compquicksort);

    printf("2. SELECTION SORT:\n");
    printf("   - Vetor ordenado: ");
    imprimirvetor(vselection, n);
    printf("   - Total de comparações: %d\n\n", compselection);

    printf("Diferença: O Quicksort precisou de %d comparações a menos!\n", 
           compselection - compquicksort);

    return 0;
}