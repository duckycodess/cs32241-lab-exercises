#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "eye.h"

#define MAX_N 200000
// fenwick tree initialization
int64 fenwick[MAX_N + 1];

void fenwick_update(int index, int64 value, int max_val) {
    while (index <= max_val) {
        fenwick[index] += value;
        index += (index & -index);
    }
}

int64 fenwick_query(int index) {
    int64 sum = 0;
    while (index > 0) {
        sum += fenwick[index];
        index -= (index & -index);
    }
    return sum;
}

int compare(const void *a, const void *b) {
    int64 diff = (*(int64 *)a - *(int64 *)b);
    return (diff > 0) - (diff < 0);
}

int64 eye_count(int64 *s, int n) {
    int64 *s_copy = malloc(n * sizeof(int64)); //ranks kumbaga nung elements
    int64 *ranked_index = malloc(n * sizeof(int64)); //
    int64 *occurences = calloc(n + 1, sizeof(int64));
    int64 *last_ftc_count = calloc(n + 1, sizeof(int64));
    int64 *value_of_first_occurrence = calloc(n + 1, sizeof(int64));
    int64 *previous_count = calloc(n + 1, sizeof(int64));

    memcpy(s_copy, s, n * sizeof(int64));
    qsort(s_copy, n, sizeof(int64), compare);

    int unique_count = 1;
    for (int i = 1; i < n; i++) {
        if (s_copy[i] != s_copy[i - 1]) {
            s_copy[unique_count++] = s_copy[i];
        }
    }

    for (int i = 0; i < n; i++) {
        int left = 0, right = unique_count - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (s_copy[mid] == s[i]) {
                ranked_index[i] = mid + 1; 
                break;
            } else if (s_copy[mid] < s[i]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    free(s_copy);

    int64 result = 0;
    int64 max_so_far = 0;

    memset(fenwick, 0, (unique_count + 1) * sizeof(int64));

    for (int i = 0; i < n; i++) {
        int64 current_element = ranked_index[i];
        if (current_element > max_so_far) max_so_far = current_element;

        if (occurences[current_element] > 0) {
            int64 first_to_current_count = fenwick_query(max_so_far) - fenwick_query(current_element) - value_of_first_occurrence[current_element];

            int64 overall_value = (previous_count[current_element]) + ((first_to_current_count - last_ftc_count[current_element]) * occurences[current_element]);

            result += overall_value;

            last_ftc_count[current_element] = first_to_current_count;
            previous_count[current_element] = overall_value;
        } else {
            value_of_first_occurrence[current_element] = fenwick_query(max_so_far) - fenwick_query(current_element);
        }

        fenwick_update(current_element, 1, unique_count);
        occurences[current_element] += 1;
    }

    free(ranked_index);
    free(occurences);
    free(last_ftc_count);
    free(value_of_first_occurrence);
    free(previous_count);

    return result;
}