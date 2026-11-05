#include "dynamic_m.h"
#include <stdbool.h>
#include <stdlib.h>
void Vvod2(FILE *in, float ***x, int n, int m) {
    *x = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        (*x)[i] = (float *)malloc(m * sizeof(float));
        for (int j = 0; j < m; j++){
            fscanf(in, "%f", &(*x)[i][j]);
        }
    }
    return;
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
int find_max(float ***x, int n, int m) {
    int index = 0;
    float mx = (*x)[0][m];
    for (int i = 1; i < n; i++) {
        if (mx < (*x)[i][m]) {
            mx = (*x)[i][m];
            index = i;
        }
    }
    return index;
}
void swap_max13(float ***x, int n) {
    int i1 = find_max(x, n, 0);
    int i2 = find_max(x, n, 2);

    float buf = (*x)[i1][0];
    (*x)[i1][0] = (*x)[i2][2];
    (*x)[i2][2] = buf;
    return;
}
int count_no_zero(float ***x, int n, int m) {
    int count = 0;
    for(int i = 0; i< n; i++) {
        int j = 0;
        bool fl = true;
        while (j < m && fl) {
            if ((*x)[i][j] == 0) {
                fl = false;
            } else {
                j++;
            }
        }
        if (fl) {
            count++;
        }
    }
    return count;
}

