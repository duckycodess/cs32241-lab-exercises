#include <stdio.h>
#include <string.h>

long long safe_mod(long long a, long long b) {
    return ((a % b) + b) % b;
}

long long ulam(long long x, long long y, long long mod) {
    long long result;
    if (x > y && x > -y) {
        result = safe_mod(safe_mod((x * 2 - 1), mod) * safe_mod((x * 2 - 1), mod), mod) + safe_mod(x + y - 1, mod);
    } else if (x <= y && x > -y) {
        result = safe_mod(safe_mod((y * 2), mod) * safe_mod((y * 2), mod), mod) - safe_mod(x + y, mod);
    } else if (x <= y && x <= -y) {
        result = safe_mod(safe_mod((x * 2), mod) * safe_mod((x * 2), mod), mod) - safe_mod(x + y, mod);
    } else {
        result = safe_mod(safe_mod((y * 2 - 1), mod) * safe_mod((y * 2 - 1), mod), mod) + safe_mod(x + y - 1, mod);
    }
    return safe_mod(result, mod);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int test_case = 0; test_case < t; test_case++) {
        char word[100];
        long long i1, j1, i2, j2;
        scanf("%s", word);
        scanf("%lld %lld", &i1, &j1);
        scanf("%lld %lld", &i2, &j2);
        long long word_length = strlen(word);

        for (long long y = i1; y <= i2 ; y++) {
            for (long long x = j1; x <= j2; x++) {
                long long index = ulam(x, y, word_length);
                printf("%c", word[index]);
            }
            printf("\n");
        }
    }
    return 0;
}