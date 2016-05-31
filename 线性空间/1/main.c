#include <stdio.h>
#include "Matrix.h"
#include "Equation.h"

int main() {
    
    long i, j;
    
    Matrix f = Matrix_init(4, 5);
    Matrix result = Matrix_init(4, 1);
    
    f[0][0] = FractionInt(1);
    f[0][1] = FractionInt(2);
    f[0][2] = FractionInt(1);
    f[0][3] = FractionInt(0);
    f[0][4] = FractionInt(0);
    
    f[1][0] = FractionInt(1);
    f[1][1] = FractionInt(1);
    f[1][2] = FractionInt(1);
    f[1][3] = FractionInt(1);
    f[1][4] = FractionInt(0);
    
    f[2][0] = FractionInt(0);
    f[2][1] = FractionInt(3);
    f[2][2] = FractionInt(0);
    f[2][3] = FractionInt(-1);
    f[2][4] = FractionInt(0);
    
    f[3][0] = FractionInt(1);
    f[3][1] = FractionInt(1);
    f[3][2] = FractionInt(0);
    f[3][3] = FractionInt(-1);
    f[3][4] = FractionInt(1);
    
    // Compute manually
    for (j = 0; j < 5; ++j) {
        f[1][j] = fraction_min(f[1][j], f[0][j]);
    }
    for (j = 0; j < 5; ++j) {
        f[3][j] = fraction_min(f[3][j], f[0][j]);
    }
    
    for (j = 1; j < 5; ++j) {
        f[2][j] = fraction_a(f[2][j], fraction_mul(FractionInt(3), f[1][j]));
    }
    for (j = 1; j < 5; ++j) {
        f[3][j] = fraction_min(f[3][j], f[1][j]);
    }
    
    f[3][3] = fraction_a(f[3][3], f[2][3]);
    f[1][3] = fraction_min(f[1][3], fraction_mul(f[2][3], Fraction_init(1, 2)));
    f[0][2] = fraction_a(f[0][2], f[3][2]);
    f[0][4] = fraction_a(f[0][4], f[3][4]);
    f[0][1] = fraction_a(f[0][1], fraction_mul(f[1][1], FractionInt(2)));
    
    result[0][0] = fraction_d(f[0][4], f[0][0]);
    result[1][0] = fraction_d(f[1][4], f[1][1]);
    result[3][0] = fraction_d(f[2][4], f[2][3]);
    result[2][0] = fraction_d(f[3][4], f[3][2]);
    
    for (i = 0; i < 4; ++i) {
        Fraction_output(result[i][0]);
        putchar('\n');
    }
    
    return 0;
}
