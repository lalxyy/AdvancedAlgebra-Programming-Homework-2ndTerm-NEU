//
//  gcd.c
//  test1
//
//  Created by Carl Lee on 5/12/16.
//  Copyright © 2016 mytest. All rights reserved.
//

#include "gcd.h"

long gcd(long x, long y) {
    long tmp;
    while (y != 0) {
        tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}