#include "baggage.h"
#include <stdio.h>
#include <stdbool.h>

bool within_limit(int l, int w, int h, long long int b){
    long double v;
    long double x = l;
    long double y = w;
    long double z = h;
    v = x*y*z;
    if (v < b){
        return true;
    }
    else{
        return false;
    }
}