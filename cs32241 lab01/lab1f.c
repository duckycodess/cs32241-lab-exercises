#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N 200000

long long int fenwick[MAX_N + 1];

void fenwick_update(int index, long long int value, int max_val) {
    while (index <= max_val) {
        fenwick[index] += value;
        index += (index & -index);
    }
}

long long int fenwick_query(int index) {
    long long int sum = 0;
    while (index > 0) {
        sum += fenwick[index];
        index -= (index & -index);
    }
    return sum;
}

int compare(const void *a, const void *b) {
    long long int diff = (*(long long int *)a - *(long long int *)b);
    return (diff > 0) - (diff < 0);
}

long long int eye_count(long long int *s, int n) {
    long long int *coordinates = malloc(n * sizeof(long long int));
    long long int *k = malloc(n * sizeof(long long int));
    long long int *found = calloc(n + 1, sizeof(long long int));
    long long int *value_last = calloc(n + 1, sizeof(long long int));
    long long int *first_occur_value = calloc(n + 1, sizeof(long long int));
    long long int *dp = calloc(n + 1, sizeof(long long int));

    memcpy(coordinates, s, n * sizeof(long long int));
    qsort(coordinates, n, sizeof(long long int), compare);

    int unique_count = 1;
    for (int i = 1; i < n; i++) {
        if (coordinates[i] != coordinates[i - 1]) {
            coordinates[unique_count++] = coordinates[i];
        }
    }

    for (int i = 0; i < n; i++) {
        int left = 0, right = unique_count - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (coordinates[mid] == s[i]) {
                k[i] = mid + 1; 
                break;
            } else if (coordinates[mid] < s[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    long long int result = 0;
    long long int max_so_far = 0;

    memset(fenwick, 0, (unique_count + 1) * sizeof(long long int));

    for (int i = 0; i < n; i++) {
        if (k[i] > max_so_far) max_so_far = k[i];

        if (found[k[i]] > 0) {
            long long int a = fenwick_query(max_so_far) - fenwick_query(k[i]);
            a -= first_occur_value[k[i]];
            long long int abc = (dp[k[i]]) + ((a - value_last[k[i]]) * found[k[i]]);

            result += abc;

            value_last[k[i]] = a;
            dp[k[i]] = abc;
        } else {
            first_occur_value[k[i]] = fenwick_query(max_so_far) - fenwick_query(k[i]);
        }

        fenwick_update(k[i], 1, unique_count);
        found[k[i]] += 1;
    }

    free(coordinates);
    free(k);
    free(found);
    free(value_last);
    free(first_occur_value);
    free(dp);

    return result;
}