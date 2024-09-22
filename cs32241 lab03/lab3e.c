#include "excitingness.h"
#include <stdlib.h>

long long int excitingness(int n, long long int *l) {
    long long int gss = 0;
    long long int lss = 0;
    long long int sum = 0;

    for (int i = 0; i < n; i++){
        sum += l[i];
        if (i > 0 && i < n - 1) {
            if (l[i-1] < l[i] && l[i] > l[i+1]) gss++;
            else if (l[i-1] > l[i] && l[i] < l[i+1])lss++;
        }
    }

    return (sum)*(gss+lss);
}