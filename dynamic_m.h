#ifndef DYNAMIC_M_H
#define DYNAMIC_M_H
#include <stdio.h>
void Vvod2(FILE *in, float ***x, int n, int m);
void Vivod2(FILE *out, float ***x, int n, int m);
void FR2(float ***x, int n);
int  find_max(float ***x, int n, int col);
void swap_max13(float ***x, int n);
int count_no_zero(float ***x, int n, int m);
#endif
