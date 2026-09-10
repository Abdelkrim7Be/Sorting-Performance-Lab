#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

typedef enum {
    FILL_ASCENDING = 1,
    FILL_DESCENDING = 2,
    FILL_ALTERNATING_SIGN = 3
} FillMode;

void remplissage(int T[], int n, FillMode mode);
void tri_bulles(int array[], int n);
void tri_insertion(int tab[], int n);
void tri_selection(int array[], int n);

#endif
