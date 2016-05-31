#include <stdio.h>
#include "Matrix.h"
#include "Equation.h"

Matrix origin() {
    Matrix f = Matrix_init(4, 5);
    f[0][0] = FractionInt(1);
    f[0][1] = FractionInt(1);
    f[0][2] = FractionInt(1);
    f[0][3] = FractionInt(1);
    
    f[1][0] = FractionInt(1);
    f[1][1] = FractionInt(1);
    f[1][2] = FractionInt(-1);
    f[1][3] = FractionInt(-1);
    
    f[2][0] = FractionInt(1);
    f[2][1] = FractionInt(-1);
    f[2][2] = FractionInt(1);
    f[2][3] = FractionInt(-1);
    
    f[3][0] = FractionInt(1);
    f[3][1] = FractionInt(-1);
    f[3][2] = FractionInt(-1);
    f[3][3] = FractionInt(1);
    
    return f;
}

Matrix compute(Matrix f) {
    long i, j;
    Matrix result = Matrix_init(4, 1);
    
    for (i = 1; i < 4; ++i) {
        for (j = 0; j < 5; ++j) {
            f[i][j] = fraction_min(f[i][j], f[0][j]);
        }
    }
    for (j = 1; j < 5; ++j) {
        f[3][j] = fraction_min(f[3][j], f[2][j]);
    }
    for (j = 2; j < 5; ++j) {
        f[3][j] = fraction_min(f[3][j], f[1][j]);
    }
    
    for (j = 3; j < 5; ++j) {
        f[0][j] = fraction_min(f[0][j], fraction_mul(f[3][j], Fraction_init(1, 4)));
        f[1][j] = fraction_a(f[1][j], fraction_mul(f[3][j], Fraction_init(1, 2)));
        f[2][j] = fraction_a(f[2][j], fraction_mul(f[3][j], Fraction_init(1, 2)));
    }
    for (j = 2; j < 5; ++j) {
        f[0][j] = fraction_a(f[0][j], fraction_mul(f[1][j], Fraction_init(1, 2)));
    }
    for (j = 1; j < 5; ++j) {
        f[0][j] = fraction_a(f[0][j], fraction_mul(f[2][j], Fraction_init(1, 2)));
    }
    
    result[0][0] = fraction_d(f[0][4], f[0][0]);
    result[2][0] = fraction_d(f[1][4], f[1][2]);
    result[1][0] = fraction_d(f[2][4], f[2][1]);
    result[3][0] = fraction_d(f[3][4], f[3][3]);
    
    return result;
}

int main() {
    
    long i, j, k, l;
    
    Matrix f = Matrix_init(4, 5);
    Matrix result = Matrix_init(4, 5);
    Matrix r;
    
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            result[i][j] = FractionZero;
        }
    }
    
    // Compute manually
    // f
    f = origin();
    
    f[0][4] = FractionInt(1);
    f[1][4] = FractionInt(1);
    f[2][4] = FractionInt(0);
    f[3][4] = FractionInt(1);
    
    r = compute(f);
    for (i = 0; i < 4; ++i) {
        result[i][0] = r[i][0];
    }
    
    // f1
    f = origin();
    
    f[0][4] = FractionInt(2);
    f[1][4] = FractionInt(1);
    f[2][4] = FractionInt(3);
    f[3][4] = FractionInt(1);
    
    r = compute(f);
    for (i = 0; i < 4; ++i) {
        result[i][1] = r[i][0];
    }
    
    // f2
    f = origin();
    
    f[0][4] = FractionInt(1);
    f[1][4] = FractionInt(1);
    f[2][4] = FractionInt(0);
    f[3][4] = FractionInt(0);
    
    r = compute(f);
    for (i = 0; i < 4; ++i) {
        result[i][2] = r[i][0];
    }
    
    // f3
    f = origin();
    
    f[0][4] = FractionInt(0);
    f[1][4] = FractionInt(1);
    f[2][4] = FractionInt(-1);
    f[3][4] = FractionInt(-1);
    
    r = compute(f);
    for (i = 0; i < 4; ++i) {
        result[i][3] = r[i][0];
    }
    
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 4; ++j) {
            Fraction_output(result[i][j]);
            putchar('\t');
        }
        putchar('\n');
    }
    putchar('\n');
    
    // ====
    result[0][4] = FractionInt(1);
    result[1][4] = FractionInt(0);
    result[2][4] = FractionInt(0);
    result[3][4] = FractionInt(-1);
    
    for (k = 1; k < 4; ++k) {
        for (i = k; i < 4; ++i) {
            Fraction tmp = fraction_d(result[i][k - 1], result[k - 1][k - 1]);
            for (j = k - 1; j < 5; ++j) {
                result[i][j] = fraction_min(result[i][j], fraction_mul(result[k - 1][j], tmp));
            }
        }
    }
    
    for (k = 2; k >= 0; --k) {
        for (i = 0; i <= k; ++i) {
            Fraction tmp = fraction_d(result[i][k + 1], result[k + 1][k + 1]);
            for (j = k + 1; j < 5; ++j) {
                result[i][j] = fraction_min(result[i][j], fraction_mul(result[k + 1][j], tmp));
            }
        }
    }
    
    r = Matrix_init(4, 1);
    for (i = 0; i < 4; ++i) {
        r[i][0] = fraction_d(result[i][4], result[i][i]);
    }
    
    for (i = 0; i < 4; ++i) {
        Fraction_output(r[i][0]);
        putchar('\n');
    }
    
    return 0;
}
