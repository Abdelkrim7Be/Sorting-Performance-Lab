#include "benchmark.h"
#include <stdlib.h>
#include <time.h>

double CalculTemps(void (*trier)(int T[], int n), int taille, FillMode mode) {
    int *T = malloc((size_t)taille * sizeof(int));
    if (T == NULL)
        return -1.0;

    remplissage(T, taille, mode);
    clock_t start = clock();
    trier(T, taille);
    clock_t end = clock();

    free(T);
    return (double)(end - start) / CLOCKS_PER_SEC;
}

void Interpolation(double Mat[NUM_ALGORITHMS][NUM_SAMPLES]) {
    for (int i = 0; i < NUM_ALGORITHMS; i++) {
        double prev = Mat[i][0];
        for (int j = 1; j < NUM_SAMPLES - 1; j++) {
            double current = Mat[i][j];
            Mat[i][j] = (prev + Mat[i][j] + Mat[i][j + 1]) / 3;
            prev = current;
        }
    }
}
