#include "benchmark.h"
#include "plot.h"
#include <signal.h>
#include <stdio.h>

static FillMode ask_fill_mode(void) {
    int choix;
    int ok;
    do {
        printf("Choisissez le type de remplissage du tableau :\n");
        printf("1 - Trie\n");
        printf("2 - Trie a l'envers\n");
        printf("3 - Valeur positive apres valeur negative\n");
        printf("=> ");

        ok = scanf("%d", &choix);
        if (ok != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            choix = 0;
        }
    } while (choix < 1 || choix > 3);

    return (FillMode)choix;
}

int main(void) {
    signal(SIGPIPE, SIG_IGN);

    printf("***********************************************\n");
    printf("*   Tests de la performance des tris en C   *\n");
    printf("***********************************************\n");

    FillMode mode = ask_fill_mode();

    double Mat[NUM_ALGORITHMS][NUM_SAMPLES];
    for (int i = 0; i < NUM_SAMPLES; i++) {
        int taille = STEP * (i + 1);
        Mat[0][i] = CalculTemps(tri_bulles, taille, mode);
        Mat[1][i] = CalculTemps(tri_insertion, taille, mode);
        Mat[2][i] = CalculTemps(tri_selection, taille, mode);
    }

    Interpolation(Mat);

    for (int i = 0; i < NUM_ALGORITHMS; i++) {
        for (int j = 0; j < NUM_SAMPLES; j++)
            printf("%f ", Mat[i][j]);
        printf("\n");
    }

    plot(Mat, "results.png");

    return 0;
}
