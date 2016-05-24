#include <stdio.h>
#include <math.h>
#include "Fraction.h"

Fraction getDotProduct(Fraction *a, Fraction *b, long len) {
    Fraction result = FractionZero;
    long i;
    for (i = 0; i < len; ++i) {
        result = fraction_a(result, fraction_mul(a[i], b[i]));
    }
    return result;
}

int main() {
    
    long i;
    
    Fraction a1[4];
    Fraction a2[4];
    Fraction a3[4];
    Fraction a4[4];
    
    Fraction b1[4];
    Fraction b2[4];
    Fraction b3[4];
    Fraction b4[4];
    
    a1[0] = FractionInt(1);
    a1[1] = FractionInt(1);
    a1[2] = FractionInt(0);
    a1[3] = FractionInt(0);
    
    a2[0] = FractionInt(-1);
    a2[1] = FractionInt(0);
    a2[2] = FractionInt(0);
    a2[3] = FractionInt(1);
    
    a3[0] = FractionInt(1);
    a3[1] = FractionInt(0);
    a3[2] = FractionInt(1);
    a3[3] = FractionInt(0);
    
    a4[0] = FractionInt(1);
    a4[1] = FractionInt(-1);
    a4[2] = FractionInt(-1);
    a4[3] = FractionInt(1);
    
    for (i = 0; i < 4; ++i) {
        b1[i] = a1[i];
    }
    for (i = 0; i < 4; ++i) {
        b2[i] = fraction_min(a2[i], fraction_mul(fraction_d(getDotProduct(a2, b1, 4), getDotProduct(b1, b1, 4)), b1[i]));
    }
    for (i = 0; i < 4; ++i) {
        b3[i] = fraction_min(fraction_min(a3[i], fraction_mul(fraction_d(getDotProduct(a3, b1, 4), getDotProduct(b1, b1, 4)), b1[i])), fraction_mul(fraction_d(getDotProduct(a3, b2, 4), getDotProduct(b2, b2, 4)), b2[i]));
    }
    for (i = 0; i < 4; ++i) {
        b4[i] = fraction_min(fraction_min(fraction_min(a4[i], fraction_mul(fraction_d(getDotProduct(a4, b1, 4), getDotProduct(b1, b1, 4)), b1[i])), fraction_mul(fraction_d(getDotProduct(a4, b2, 4), getDotProduct(b2, b2, 4)), b2[i])), fraction_mul(fraction_d(getDotProduct(a4, b3, 4), getDotProduct(b3, b3, 4)), b3[i]));
    }
    
    for (i = 0; i < 4; ++i) {
        Fraction_output(b1[i]);
        putchar('\n');
    }
    putchar('\n');
    for (i = 0; i < 4; ++i) {
        Fraction_output(b2[i]);
        putchar('\n');
    }
    putchar('\n');
    for (i = 0; i < 4; ++i) {
        Fraction_output(b3[i]);
        putchar('\n');
    }
    putchar('\n');
    for (i = 0; i < 4; ++i) {
        Fraction_output(b4[i]);
        putchar('\n');
    }
    putchar('\n');
    
    return 0;
}
