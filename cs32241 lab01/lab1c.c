#include "baggage3.h"
#include <stdio.h>
#include <stdbool.h>

suitcase_t better_suitcase(suitcase_t s1, suitcase_t s2){
    long long int a, b, c, d, e, f;
    a = s1.l;
    b = s1.w;
    c = s1.h;
    d = s2.l;
    e = s2.w;
    f = s2.h;

    if (a*b*c >= d*e*f){
        return s1;
    }
    else{
        return s2;
    }
}