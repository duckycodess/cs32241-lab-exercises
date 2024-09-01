#include "baggage4.h"
#include <stdio.h>
#include <stdbool.h>

long long int max_vol_suitcase(long long int b, suitcase_t *s, int n){
    int i;
    long long int max_prod = 0;
    for (i = 0; i < n; i++){
        long long int x, y, z;
        x = s[i].l;
        y = s[i].w;
        z = s[i].h;

        if (x+y+z <= b){
            if(x*y*z > max_prod){
                max_prod = x*y*z;
            }
        }
    }
    return max_prod;
}