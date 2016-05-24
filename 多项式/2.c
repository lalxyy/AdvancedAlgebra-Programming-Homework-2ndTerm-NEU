#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct nv {
    int a;
    struct nv *nxt;
};
typedef struct nv numvec;

int getVal(int x) {
    return (int)pow(x, 3) - 6 * (int)pow(x, 2) + 15 * x - 14;
}

numvec *getFactors(int num) {
    int i, r;
    numvec *res = NULL;
    numvec *hd = NULL;
    for (i = 1; i <= num; ++i) {
        r = num % i;
        if (r == 0) {
            if (!res) {
                hd = (numvec *)malloc(sizeof(numvec));
                res = hd;
            } else {
                res->nxt = (numvec *)malloc(sizeof(numvec));
                res = res->nxt;
            }
            res->a = i;
        }
    }
    res->nxt = NULL;
    return hd;
}

int main() {
    numvec *r = getFactors(14);
    while (r) {
        if (getVal(r->a) == 0) {
            printf("%d\n", r->a);
        }
        r = r->nxt;
    }
    return 0;
}
