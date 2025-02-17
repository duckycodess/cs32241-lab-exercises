#include <stdio.h>
#define MOD 1000000000

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long n, k;
        scanf("%ld", &n);

        long long sum = 0, ans = 0, count = 0, odds = 0, total = 0, odd_count = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%lld", &k);
            
            total = (total + k) % MOD;
            count++;
            
            if (k % 2) {
                odds = (odds + k) % MOD;
                odd_count++;
            }

            ans = (ans + (sum * k) % MOD) % MOD;
            sum = (sum + k) % MOD;
        }

        ans = (ans + (total * (count - 1)) % MOD) % MOD;

        ans = (ans - (odds * (odd_count - 1)) % MOD + MOD) % MOD;
        long long even_contrib = ((count * (count - 1) / 2) % MOD - (odd_count * (odd_count - 1) / 2) % MOD + MOD) % MOD;
        ans = (ans + even_contrib) % MOD;

        printf("%lld\n", ans % MOD);
    }

    return 0;
}