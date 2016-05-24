#include <stdio.h>
#include "Matrix.h"

int main() {
    long i, j;
    
    Matrix a = Matrix_init(2, 2);
    a[0][0] = FractionInt(2);
    a[0][1] = FractionInt(1);
    a[1][0] = FractionInt(-1);
    a[1][1] = FractionInt(0);
    
    Matrix b = Matrix_init(2, 2);
    b[0][0] = FractionInt(1);
    b[0][1] = FractionInt(-1);
    b[1][0] = FractionInt(-1);
    b[1][1] = FractionInt(2);
    
    Fraction bValue = fraction_min(fraction_mul(FractionInt(1), FractionInt(2)), fraction_mul(FractionInt(-1), FractionInt(-1)));
    
    Matrix reversed = Matrix_init(2, 2);
    reversed[0][0] = b[1][1];
    reversed[0][1] = b[1][0];
    reversed[1][0] = b[0][1];
    reversed[1][1] = b[0][0];
    
    reversed = matrix_nummul(reversed, 2, 2, bValue);
    
    Matrix result = matrix_mul(a, reversed, 2, 2, 2);
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            Fraction_output(result[i][j]);
            putchar('\t');
        }
        putchar('\n');
    }
    
    return 0;
}
