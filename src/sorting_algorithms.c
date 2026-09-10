#include "sorting_algorithms.h"

void remplissage(int T[], int n, FillMode mode) {
    switch (mode) {
        case FILL_ASCENDING:
            for (int i = 0; i < n; i++)
                T[i] = i;
            break;
        case FILL_DESCENDING:
            for (int i = 0; i < n; i++)
                T[n - 1 - i] = i;
            break;
        case FILL_ALTERNATING_SIGN:
            for (int i = 0; i < n; i++)
                T[i] = (i % 2) ? i : -i;
            break;
    }
}

void tri_bulles(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void tri_insertion(int tab[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && tab[j] < tab[j - 1]) {
            int temp = tab[j];
            tab[j] = tab[j - 1];
            tab[j - 1] = temp;
            j--;
        }
    }
}

void tri_selection(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}
