//
//  Fraction.h
//  test1
//
//  Created by Carl Lee on 5/12/16.
//  Copyright © 2016 mytest. All rights reserved.
//

#ifndef Fraction_h
#define Fraction_h

#include <stdio.h>

#include "gcd.h"

struct fraction {
    long u;
    long d;
};
typedef struct fraction Fraction;

Fraction Fraction_init(long u, long d);
Fraction fraction_a(Fraction x, Fraction y);
Fraction fraction_min(Fraction x, Fraction y);
Fraction fraction_mul(Fraction x, Fraction y);
Fraction fraction_d(Fraction x, Fraction y);
Fraction fraction_reduce(Fraction a);
void Fraction_output(Fraction a);

#define FractionZero Fraction_init(0, 1)
#define FractionInt(a) Fraction_init(a, 1)

#endif /* Fraction_h */
