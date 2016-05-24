#include <stdio.h>
#include "Matrix.h"

Matrix transA(Matrix X) {
    Matrix left = Matrix_init(2, 2);
    left[0][0] = FractionInt(1);
    left[0][1] = FractionInt(2);
    left[1][0] = FractionInt(3);
    left[1][1] = FractionInt(4);
    
    Matrix right = Matrix_init(2, 2);
    right[0][0] = FractionInt(1);
    right[0][1] = FractionInt(2);
    right[1][0] = FractionInt(3);
    right[1][1] = FractionInt(4);
    
    Matrix firstresult = matrix_mul(left, X, 2, 2, 2);
    Matrix secondresult = matrix_mul(firstresult, right, 2, 2, 2);
    return secondresult;
}

void outputRes(Matrix r1, Matrix r2, Matrix r3, Matrix r4) {
    long i, j;
    for (i = 0; i < 2; ++i) {
        for (j = 0; j < 2; ++j) {
            Fraction_output(r1[i][j]);
            putchar('\t');
            Fraction_output(r2[i][j]);
            putchar('\t');
            Fraction_output(r3[i][j]);
            putchar('\t');
            Fraction_output(r4[i][j]);
            putchar('\n');
        }
    }
    putchar('\n');
    putchar('\n');
}

int main() {
    Matrix a = Matrix_init(2, 2), _a;
    Matrix b = Matrix_init(2, 2), _b;
    Matrix c = Matrix_init(2, 2), _c;
    Matrix d = Matrix_init(2, 2), _d;
    
    a[0][0] = FractionInt(1);
    b[0][1] = FractionInt(1);
    c[1][0] = FractionInt(1);
    d[1][1] = FractionInt(1);
    
    _a = transA(a);
    _b = transA(b);
    _c = transA(c);
    _d = transA(d);
    
    outputRes(_a, _b, _c, _d);
    
    return 0;
}
