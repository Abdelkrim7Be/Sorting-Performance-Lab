#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "sorting_algorithms.h"

#define NUM_ALGORITHMS 3
#define NUM_SAMPLES 10
#define STEP 1000

double CalculTemps(void (*trier)(int T[], int n), int taille, FillMode mode);
void Interpolation(double Mat[NUM_ALGORITHMS][NUM_SAMPLES]);

#endif
