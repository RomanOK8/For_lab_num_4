#include "dynamic_m.h"
#include <stdlib.h>
void Vvod(FILE *in, int x, int y){
    fscanf(in, "%i %i", &x, &y);
    return;
}
void Vvod2(FILE *in, float ***x, int n, int m) {
    for (int i = 0; i < n; i++) {
        (*x)[i] = (float *)malloc(m * sizeof(float));
        for (int j = 0; j < m; j++){
            fscanf(in, "%f", &(*x)[i][j]);
        }
    }
}
void Vivod2(FILE *out, float ***x, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(out, "%3.2f ", (*x)[i][j]);
        }
        fprintf(out, "\n");
    }
    fprintf(out, "\n");
    return;
}

void FR2(float ***x, int n) {
    for (int i = 0; i < n; i++) {
        free((*x)[i]);
    }
    free(*x);
    return;
}

void swap_max13(float ***x, int n) {
    float max1 = (*x)[0][0];
    float max2 = (*x)[0][2];
    int i1 = 0, i2 = 0;

    for (int i = 0; i < n; i++) {
        if ((*x)[i][0] > max1) {
            max1 = (*x)[i][0];
            i1 = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if ((*x)[i][2] > max2) {
            max2 = (*x)[i][2];
            i2 = i;
        }
    }

    float buf = (*x)[i1][0];
    (*x)[i1][0] = (*x)[i2][2];
    (*x)[i2][2] = buf;
    return;
}
