//
//  Fraction.c
//  test1
//
//  Created by Carl Lee on 5/12/16.
//  Copyright © 2016 mytest. All rights reserved.
//

#include "Fraction.h"

Fraction Fraction_init(long u, long d) {
    Fraction f;
    f.u = u;
    f.d = d;
    return f;
}

Fraction fraction_a(Fraction x, Fraction y) {
    long newd = x.d * y.d;
    x.u *= y.d;
    y.u *= x.d;
    return fraction_reduce(Fraction_init(x.u + y.u, newd));
}

Fraction fraction_min(Fraction x, Fraction y) {
    return fraction_a(x, Fraction_init(-y.u, y.d));
}

Fraction fraction_mul(Fraction x, Fraction y) {
    return fraction_reduce(Fraction_init(x.u * y.u, x.d * y.d));
}

Fraction fraction_d(Fraction x, Fraction y) {
    return fraction_reduce(Fraction_init(x.u * y.d, x.d * y.u));
}

Fraction fraction_reduce(Fraction a) {
    long aGCD = gcd(a.u, a.d);
    if (a.u == 0) {
        return FractionZero;
    }
    return Fraction_init(a.u / aGCD, a.d / aGCD);
}

void Fraction_output(Fraction a) {
    if (a.d == 1) {
        printf("%ld", a.u);
    } else {
        printf("%ld/%ld", a.u, a.d);
    }
}
