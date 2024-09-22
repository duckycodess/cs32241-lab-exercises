#include "excitingness_sum.h"
#include <stdlib.h>

#define MOD 1000000000

int peak(int64 *l, int i, int n) {
    return (i > 0 && i < n-1 && l[i] > l[i-1] && l[i] > l[i+1]);
}

int val(int64 *l, int i, int n) {
    return (i > 0 && i < n-1 && l[i] < l[i-1] && l[i] < l[i+1]);
}

int64 excitingness_sum(int n, int64 *l) {
    int64 ans = 0;
    int64 init = 0, rev = 0;

    for (int i = 1; i < n - 1; i++) {
        init = (init + i * l[i-1] % MOD) % MOD;
        int k = n - i - 1;
        if (k > 0 && k < n - 1) {
            rev = (rev + l[k + 1] * (n-k-1) % MOD) % MOD;
        }
        if (peak(l, i, n) || val(l, i, n)) {
            int64 forward_wt = (init * (n-i-1) % MOD + l[i] * (n-i-1) % MOD * i % MOD) % MOD;
            ans = (ans + forward_wt) % MOD;
        }
        if (k > 0 && (peak(l, k, n) || val(l, k, n))) {
            int64 reverse_wt = rev * k % MOD;
            ans = (ans + reverse_wt) % MOD;
        }
    }
    return ans;
}

int main() {
    long long int arr[] = {1,1,1,1,1,1,1,1,2,1,21,2,12,1,21,21,2,12,1,21,2,12,12,1,2,12,12,1,21,2,12,12,1,21,21,2,12,1};
    long long int ans = excitingness_sum((sizeof(arr))/sizeof(long long int), arr);
    printf("%d", (sizeof(arr))/sizeof(long long int));
    printf("%lld\n", ans);
}