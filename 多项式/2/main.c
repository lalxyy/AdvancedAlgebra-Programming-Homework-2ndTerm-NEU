#include <stdio.h>
#include "Fraction.h"

Fraction aVal(Fraction x) {
    return fraction_min(fraction_a(fraction_min(fraction_pow(x, 3), fraction_mul(FractionInt(6), fraction_pow(x, 2))), fraction_mul(FractionInt(15), x)), FractionInt(14));
}

Fraction bVal(Fraction x) {
    return fraction_a(fraction_a(fraction_min(fraction_a(fraction_min(fraction_pow(x, 5), fraction_mul(Fraction_init(13, 12), fraction_pow(x, 4))), fraction_mul(Fraction_init(217, 36), fraction_pow(x, 3))), fraction_mul(Fraction_init(19, 3), fraction_pow(x, 2))), fraction_mul(Fraction_init(1, 6), x)), FractionInt(1));
}

int main() {
    
    long i, j, k;
    Fraction a[] = {FractionInt(1), FractionInt(2), FractionInt(7), FractionInt(14)};
    Fraction b[] = {FractionInt(1), FractionInt(2), FractionInt(3), FractionInt(4), FractionInt(6), FractionInt(9), FractionInt(12),
        FractionInt(18), FractionInt(36)};
    Fraction bRes[3] = {FractionZero, FractionZero, FractionZero};
    
    for (i = 0; i < 4; ++i) {
        if (fraction_equal(aVal(a[i]), FractionZero)) {
            Fraction_output(a[i]);
            putchar('\n');
        }
        if (fraction_equal(aVal(fraction_rev(a[i])), FractionZero)) {
            Fraction_output(fraction_rev(a[i]));
            putchar('\n');
        }
    }
    putchar('\n');
    
    for (i = 0; i < 9; ++i) {
        for (j = 0; j < 9; ++j) {
            Fraction r = fraction_d(b[i], b[j]);
            if (fraction_equal(bVal(r), FractionZero)) {
                for (k = 0; k < 3; ++k) {
                    if (fraction_equal(bRes[k], FractionZero)) {
                        bRes[k] = r;
                        Fraction_output(r);
                        putchar('\n');
                        break;
                    } else if (fraction_equal(bRes[k], r)) {
                        break;
                    }
                }
            }
            if (fraction_equal(bVal(fraction_rev(r)), FractionZero)) {
                for (k = 0; k < 3; ++k) {
                    if (fraction_equal(bRes[k], FractionZero)) {
                        bRes[k] = fraction_rev(r);
                        Fraction_output(fraction_rev(r));
                        putchar('\n');
                        break;
                    } else if (fraction_equal(bRes[k], fraction_rev(r))) {
                        break;
                    }
                }
            }
        }
    }
    
    return 0;
}
