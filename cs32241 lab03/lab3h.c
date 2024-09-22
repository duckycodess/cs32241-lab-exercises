#include "excitingness_sum.h"
#include <stdlib.h>

#define MOD 1000000000

long long int excitingness(int n, long long int *l, int start);

long long int excitingness(int n, long long int *l, int start) {
    long long int gss = 0;
    long long int lss = 0;
    long long int sum = 0;

    for (int i = 0; i < n; i++){
        sum = (sum + l[i + start]) % MOD;
        if (i > 0 && i < n - 1) {
            if (l[i + start-1] < l[i + start] && l[i + start] > l[i + start+1]) {
                gss++;
            } else if (l[i + start-1] > l[i + start] && l[i + start] < l[i + start+1]) {
                lss++;
            }
        }
        
    }

    return (sum * (gss + lss)) % MOD;
}

long long int excitingness_sum(int n, long long int *l) {
    long long int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            result = (result + excitingness(j - i + 1, l, i)) % MOD;
        }
    }

    return result;
}



long long int excitingness2_sum(int n, long long int *l){
    long long int sum = 0;
    long long int pnv = 0;
    for (int i = 0; i < n; i++) {
        sum += (l[i] * (i + 1) * (n - i));;
    }
    return sum;
}

int main() {
    long long int arr[21] = {1,3,1,3,1,3,4,4,5,4,1,10,15,10,8,7,8,7,8,7,8};
    long long int ans = excitingness_sum(21, arr);

    printf("%lld\n", ans);
}