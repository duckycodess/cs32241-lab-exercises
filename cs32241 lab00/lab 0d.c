#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        long n, q, watered = 0;
        long long plants[150001] = {0};

        scanf("%ld", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%lld", &plants[i]);
            plants[i] += plants[i - 1];
        }

        scanf("%ld", &q);

        for (int j = 0; j < q; j++) {
            char action[10];
            long a, b;

            scanf("%s", action);

            if (strcmp(action, "total") == 0) {
                scanf("%ld %ld", &a, &b);
                long long result = (plants[b] - plants[a - 1]) + (b - a + 1) * watered * 2;
                printf("%lld\n", result);
            } else if (strcmp(action, "water") == 0) {
                watered++;
            }
        }
    }

    return 0;
}