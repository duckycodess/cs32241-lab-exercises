#include "baggage5.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int suitable_suitcases(long long int b, suitcase_t *s, int n, int **res){
    int res_index = 0;
    long long int count = 0;
    *res = (int*)malloc(sizeof(int)*100);
    for (int i = 0; i < n; i++){
        long long int x, y, z;
        x = s[i].l;
        y = s[i].w;
        z = s[i].h;
        if (x + y + z <= b){
            *(*res+res_index) = i+1;
            count++;
            res_index++;
        }
    }
    return count;
}