#include <stdio.h>
#include <math.h>

int getVal(int x) {
    return (int)pow(x, 3) - 6 * (int)pow(x, 2) + 15 * x - 14;
}

int main() {
    printf("%d\n", getVal(3));
    return 0;
}