#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long compselection = 0;
long long compquicksort = 0;

void selectionsort(int v[], int n) {
    compselection = 0;
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

int main() {
    int n = 1000;
    int vetororiginal[1000];
    int vetorselection[1000];
    int vetorquicksort[1000];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        vetororiginal[i] = rand() % 10000;
    }

    for (int i = 0; i < n; i++) {
        vetorselection[i] = vetororiginal[i];
        vetorquicksort[i] = vetororiginal[i];
    }

    selectionsort(vetorselection, n);

    compquicksort = 0;
    quicksort(vetorquicksort, 0, n - 1);

    printf("====================================================\n");
    printf("     COMPARATIVO DE DESEMPENHO (1.000 ELEMENTOS)    \n");
    printf("====================================================\n\n");

    printf("%-20s | %-25s\n", "Algoritmo", "Número de Comparações");
    printf("----------------------------------------------------\n");
    printf("%-20s | %-25lld\n", "Selection Sort", compselection);
    printf("%-20s | %-25lld\n", "Quicksort", compquicksort);
    printf("----------------------------------------------------\n\n");

    double reducao = ((double)(compselection - compquicksort) / compselection) * 100.0;
    printf(" O Quicksort foi aproximadamente %.1fx mais rápido em comparações!\n", 
           (double)compselection / compquicksort);
    printf(" Redução de %.2f%% no número total de operações.\n", reducao);

    return 0;
}