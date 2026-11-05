#include <stdio.h>
#include <malloc.h>
#include "dynamic_m.h"
int main() {
    FILE *in = fopen("input.txt", "r");
    int n, m;
    do{
        printf("Input n:");
        scanf("%i",&n);
    }while(n < 3 || n > 20);
    do{
        printf("Input m:");
        scanf("%i",&m);
    }while(m < 3 || m > 20);
    float **A ;
    Vvod2(in, &A, n, m);
    int counter = count_no_zero(&A, n, m);
    FILE *out = fopen("output.txt", "w");
    fprintf(out,"%i \n",counter);
    swap_max13(&A, n);
    Vivod2(out, &A, n, m);
    FR2(&A, n);
    fclose(in);
    fclose(out);
    printf("Norm vse vivelos!");
}
