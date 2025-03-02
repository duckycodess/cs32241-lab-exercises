#include <stdio.h>
#include "tabulate.h"  // Include the provided header file

int main() {
    // Define headers
    char *headers[] = {"n", "fib(n)", "factorial(n)"};

    // Define data as an array of int64 pointers
    int64 row0[] = {0, 0, 1};
    int64 row1[] = {1, 1, 1};
    int64 row2[] = {2, 1, 2};
    int64 row3[] = {3, 2, 6};
    int64 row4[] = {4, 3, 24};
    int64 row5[] = {5, 5, 120};
    int64 row6[] = {6, 8, 720};
    int64 row7[] = {7, 13, 5040};
    int64 row8[] = {8, 21, 40320};
    int64 row9[] = {9, 34, 362880};
    int64 row10[] = {10, 55, 3628800};
    int64 row11[] = {11, 89, 39916800};
    int64 row12[] = {12, 144, 479001600};
    int64 row13[] = {13, 233, 6227020800LL};
    int64 row14[] = {14, 377, 87178291200LL};
    int64 row15[] = {15, 610, 1307674368000LL};

    int64 *data[] = {
        row0, row1, row2, row3, row4, row5, row6, row7, row8,
        row9, row10, row11, row12, row13, row14, row15
    };

    tabulate(16, 3, headers, data);

    // Test the tabulate_sep function with '#' as the separator
    tabulate_sep(16, 3, headers, data, '#');

    return 0;
}
