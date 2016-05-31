#include <stdio.h>
#include <math.h>

double getDotProduct(double *a, double *b, long len) {
    long i;
    double result = 0;
    for (i = 0; i < len; ++i) {
        result += a[i] * b[i];
    }
    return result;
}

double getLen(double *a, long len) {
    long i;
    double result = 0;
    for (i = 0; i < len; ++i) {
        result += a[i] * a[i];
    }
    return sqrt(result);
}

int main() {
    double a1[] = {1, 1, 0, 0};
    double a2[] = {-1, 0, 0, 1};
    double a3[] = {1, 0, 1, 0};
    double a4[] = {1, -1, -1, 1};
    
    double b1[4];
    double b2[4];
    double b3[4];
    double b4[4];
    
    int i;
    
    for (i = 0; i < 4; ++i) {
        b1[i] = a1[i];
    }
    for (i = 0; i < 4; ++i) {
        b2[i] = a2[i] - (getDotProduct(a2, b1, 4) / getDotProduct(b1, b1, 4)) * b1[i];
    }
    for (i = 0; i < 4; ++i) {
        b3[i] = a3[i] - (getDotProduct(a3, b1, 4) / getDotProduct(b1, b1, 4)) * b1[i] - (getDotProduct(a3, b2, 4) / getDotProduct(b2, b2, 4)) * b2[i];
    }
    for (i = 0; i < 4; ++i) {
        b4[i] = a4[i] - (getDotProduct(a4, b1, 4) / getDotProduct(b1, b1, 4)) * b1[i] - (getDotProduct(a4, b2, 4) / getDotProduct(b2, b2, 4)) * b2[i] - (getDotProduct(a4, b3, 4) / getDotProduct(b3, b3, 4)) * b3[i];
    }
    
    {
        double len = getLen(b1, 4);
        for (i = 0; i < 4; ++i) {
            b1[i] /= len;
        }
    }
    {
        double len1 = getLen(b2, 4);
        for (i = 0; i < 4; ++i) {
            b2[i] /= len1;
        }
    }
    {
        double len2 = getLen(b3, 4);
        for (i = 0; i < 4; ++i) {
            b3[i] /= len2;
        }
    }
    {
        double len3 = getLen(b4, 4);
        for (i = 0; i < 4; ++i) {
            b4[i] /= len3;
        }
    }
    
    for (i = 0; i < 4; ++i) {
        printf("%lf\n", b1[i]);
    }
    putchar('\n');
    for (i = 0; i < 4; ++i) {
        printf("%lf\n", b2[i]);
    }
    putchar('\n');
    for (i = 0; i < 4; ++i) {
        printf("%lf\n", b3[i]);
    }
    putchar('\n');
    for (i = 0; i < 4; ++i) {
        printf("%lf\n", b4[i]);
    }
    putchar('\n');
    
    return 0;
}