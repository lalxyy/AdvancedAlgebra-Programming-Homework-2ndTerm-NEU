#include <stdio.h>
#include "Matrix.h"

int main() {
    Matrix a1 = Matrix_init(2, 2);
    Matrix A = Matrix_init(2, 2);
    Matrix a = Matrix_init(2, 2);
    Matrix result;
    long i, j;
    
    a1[0][0] = FractionInt(2);
    a1[0][1] = FractionInt(1);
    a1[1][0] = FractionInt(1);
    a1[1][1] = FractionInt(1);
    
    A[0][0] = FractionInt(2);
    A[0][1] = FractionInt(1);
    A[1][0] = FractionInt(-1);
    A[1][1] = FractionInt(0);
    
    a[0][0] = FractionInt(1);
    a[0][1] = FractionInt(-1);
    a[1][0] = FractionInt(-1);
    a[1][1] = FractionInt(2);
    
    result = matrix_mul(matrix_mul(a1, A, 2, 2, 2), a, 2, 2, 2);
    
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            Fraction_output(result[i][j]);
            putchar('\t');
        }
        putchar('\n');
    }
}