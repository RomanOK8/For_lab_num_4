#include <stdio.h>
#include <stdlib.h>
#include "dynamic_m.h"
int main() {
    FILE *in = fopen("input.txt", "r");
    int n, m;
    fscanf(in, "%i %i", &n, &m);//вообще лучше в 2 строки считывать, но мне лень было писать
    float **A = (float **)malloc(n * sizeof(float *));
    Vvod2(in, &A, n, m);
    FILE *out = fopen("output.txt", "w");
    swap_max13(&A, n);
    Vivod2(out, &A, n, m);
    FR2(&A, n);
    fclose(in);
    fclose(out);
    printf("Norm vse vivelos!");
}
