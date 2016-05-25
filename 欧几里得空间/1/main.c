#include <stdio.h>
#include <math.h>

int main() {
    double a[] = {1, 2, 3, 4};
    double b[] = {3, 1, -3, 2};
    double c = 0;
    double ares = 0, bres = 0;
    double result_raw;
    int i;
    
    for (i = 0; i < 4; ++i) {
        c += a[i] * b[i];
        ares += a[i] * a[i];
        bres += b[i] * b[i];
    }
    ares = sqrt(ares);
    bres = sqrt(bres);
    result_raw = c / (ares * bres);
    
    printf("%lf\n", acos(result_raw));
    
    return 0;
}
