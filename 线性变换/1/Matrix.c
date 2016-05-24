//
//  Matrix.c
//  test1
//
//  Created by Carl Lee on 5/15/16.
//  Copyright © 2016 mytest. All rights reserved.
//

#include "Matrix.h"

Fraction **Matrix_init(long x, long y) {
    Fraction **result = (Fraction **)malloc(x * sizeof(Fraction *));
    long i, j;
    for (i = 0; i < x; ++i) {
        result[i] = (Fraction *)malloc(y * sizeof(Fraction));
        for (j = 0; j < y; ++j) {
            result[i][j] = FractionZero;
        }
    }
    return result;
}

Fraction **matrix_a(Fraction **a, Fraction **b, long x, long y) {
    Fraction **result = (Fraction **)malloc(x * sizeof(Fraction *));
    long i, j;
    for (i = 0; i < x; ++i) {
        result[i] = (Fraction *)malloc(y * sizeof(Fraction));
    }
    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            result[i][j] = fraction_a(a[i][j], b[i][j]);
        }
    }
    return result;
}

Fraction **matrix_min(Fraction **a, Fraction **b, long x, long y) {
    Fraction **result = (Fraction **)malloc(x * sizeof(Fraction *));
    long i, j;
    for (i = 0; i < x; ++i) {
        result[i] = (Fraction *)malloc(y * sizeof(Fraction));
    }
    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            result[i][j] = fraction_min(a[i][j], b[i][j]);
        }
    }
    return result;
}

Fraction **matrix_mul(Fraction **a, Fraction **b, long a_x, long a_y_b_x, long b_y) {
    Fraction **result = Matrix_init(a_x, b_y);
    long i, j, k;
    for (i = 0; i < a_x; ++i) {
        for (j = 0; j < b_y; ++j) {
            for (k = 0; k < a_y_b_x; ++k) {
                result[i][j] = fraction_a(result[i][j], fraction_mul(a[i][k], b[k][j]));
            }
        }
    }
    return result;
}

Fraction **matrix_nummul(Fraction **a, long x, long y, Fraction num) {
    long i, j;
    for (i = 0; i < x; ++i) {
        for (j = 0; j < y; ++j) {
            a[i][j] = fraction_mul(a[i][j], num);
        }
    }
    return a;
}
