#include "baggage2.h"
#include <stdio.h>
#include <stdbool.h>

extern const int HANDCARRY;
extern const int CHECK_IN;
extern const int GARBAGE;

int bag(int l, int w, int h, int x, int y){
    long long int a, b, c, d, e;
    a = l;
    b = w;
    c = h;

    d = x;
    e = y;

    if (a+b+c <= d){
        return HANDCARRY;
    }
    else if (a+b+c <= e){
        return CHECK_IN;
    }
    else{
        return GARBAGE;
    }

}