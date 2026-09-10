#include "plot.h"
#include <stdio.h>

static const char *ALGO_NAMES[NUM_ALGORITHMS] = {
    "tri a bulle", "tri par insertion", "tri par selection"
};

void plot(double Mat[NUM_ALGORITHMS][NUM_SAMPLES], const char *output_path) {
    FILE *gp = popen("gnuplot", "w");
    if (gp == NULL) {
        fprintf(stderr, "failed to run gnuplot pipe\n");
        return;
    }

    fprintf(gp, "set term pngcairo size 1000,700\n");
    fprintf(gp, "set output '%s'\n", output_path);
    fprintf(gp, "set title 'Sorting algorithm performance'\n");
    fprintf(gp, "set xlabel 'array size'\n");
    fprintf(gp, "set ylabel 'time (s)'\n");
    fprintf(gp, "set datafile separator ','\n");
    fprintf(gp, "plot ");
    for (int i = 0; i < NUM_ALGORITHMS; i++) {
        fprintf(gp, "'-' using 1:2 title '%s' with lp%s", ALGO_NAMES[i],
                i < NUM_ALGORITHMS - 1 ? ", " : "\n");
    }
    for (int i = 0; i < NUM_ALGORITHMS; i++) {
        for (int j = 0; j < NUM_SAMPLES; j++)
            fprintf(gp, "%d,%f\n", (j + 1) * STEP, Mat[i][j]);
        fprintf(gp, "e\n");
    }

    if (pclose(gp) != 0)
        fprintf(stderr, "gnuplot did not run cleanly; is it installed?\n");
}
