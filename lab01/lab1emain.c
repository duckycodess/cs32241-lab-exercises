#include "baggage5.h"
#include <assert.h>

int main() {
    suitcase_t suitcases[6] = {
        {3, 1, 4},
        {1, 5, 9},
        {2, 6, 5},
        {3, 5, 8},
        {9, 7, 9},
        {3, 2, 3},
    };

    int *res;
    int suitable_ct = suitable_suitcases(13, suitcases, 6, &res);

    assert(suitable_ct == 3);
    assert(res[0] == 1);
    assert(res[1] == 3);
    assert(res[2] == 6);
}
