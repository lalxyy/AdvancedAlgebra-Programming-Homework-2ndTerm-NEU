//
//  Equation.c
//  test1
//
//  Created by Carl Lee on 5/15/16.
//  Copyright © 2016 mytest. All rights reserved.
//

#include "Equation.h"

Fraction *equation_getTotalEquationValue(Matrix f, Matrix r, long num) {
    Matrix new = Matrix_init(num, num + 1);
    long i, j, k;
    for (i = 0; i < num; ++i) {
        for (j = 0; j < num; ++j) {
            new[i][j] = f[i][j];
        }
        new[i][j] = r[i][0];
    }
    
    for (i = 0; i < num; ++i) {
        for (j = i + 1; j < num; ++j) {
            Fraction temp = fraction_d(f[j][i], f[i][i]);
            for (k = i; k <= num; ++k) {
                f[j][k] = fraction_min(f[j][k], fraction_mul(f[j][k], temp));
                printf("%ld %ld %ld\n", i, j, k);
            }
        }
    }
    
    for (i = num - 1; i >= 0; --i) {
        for (j = i - 1; j >= 0; --j) {
            Fraction temp = fraction_d(f[j][i], f[i][i]);
            for (k = i; k <= num; ++k) {
                f[j][k] = fraction_min(f[j][k], fraction_mul(f[j][k], temp));
                printf("%ld %ld %ld\n", i, j, k);
            }
        }
    }
    
    Fraction *result = (Fraction *)malloc(num * sizeof(Fraction));
    for (i = 0; i < num; ++i) {
        result[i] = fraction_d(f[i][num], f[i][i]);
    }
    return result;
}
