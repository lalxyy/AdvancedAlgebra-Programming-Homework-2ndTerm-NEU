//
//  Matrix.h
//  test1
//
//  Created by Carl Lee on 5/15/16.
//  Copyright © 2016 mytest. All rights reserved.
//

#ifndef Matrix_h
#define Matrix_h

#include <stdio.h>
#include <stdlib.h>

#include "Fraction.h"

typedef Fraction** Matrix;

Fraction **Matrix_init(long x, long y);
Fraction **matrix_a(Fraction **a, Fraction **b, long x, long y);
Fraction **matrix_min(Fraction **a, Fraction **b, long x, long y);
Fraction **matrix_mul(Fraction **a, Fraction **b, long a_x, long a_y_b_x, long b_y);
Fraction **matrix_nummul(Fraction **a, long x, long y, Fraction num);

#endif /* Matrix_h */
