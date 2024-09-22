#include "excitingnesses.h"
#include <stdlib.h>

long long int *excitingnesses(int n, long long int *l) {
    long long int gss = 0;
    long long int lss = 0;
    long long int sum = 0;
    long long int* indices = (long long int*)malloc(sizeof(long long int)*n);
    for (int i =0; i < n; i++) {
        indices[i] = 0;
    }
    for (int i = 0; i < n; i++){
        sum += l[i];
        if (i > 0 && i < n - 1) {
            if (l[i-1] < l[i] && l[i] > l[i+1]) {
                indices[i]++;
                gss++;
            }
            else if (l[i-1] > l[i] && l[i] < l[i+1]) {
                indices[i]++;
                lss++;
            }
        }
    }

    long long int *ans = (long long int*)malloc(sizeof(long long int)*n);

    for (int i = 0; i < n; i++){
        long long int total_i = sum - l[i];
        long long int pnv = gss+lss;
        if (i == 0) {
            if (indices[i+1]) ans[i] = total_i * pnv--;
            else ans[i] = total_i * pnv;
        }
        else if (i == n-1){
            if (indices[i-1]) ans[i] = total_i * pnv--;
            else ans[i] = total_i * pnv;
        }
        else if (i > 0 && i < n-1 && (indices[i] || indices[i+1] || indices[i-1])) {
            for (int j = i-1; j <= i+1; j++) {
                if (indices[j]) pnv--;
            }
            if (i < n-2 && ((l[i-1] > l[i+1] && l[i+1] < l[i+2]) || ((l[i-1] < l[i+1]) && (l[i+1] > l[i+2])))) {
                pnv++; 
            }
            if (i > 1 && (l[i-2] > l[i-1] && l[i-1] < l[i+1] || (l[i-2] < l[i-1]) && (l[i-1] > l[i+1]))) {
                pnv++;
            }
    
        }

        ans[i] = total_i * pnv;
        
    }
    return ans;
}


int main() {
    long long int arr[11] = {1,3,4,3,4,2,6,9,2,5,1};
    long long int* ans = excitingnesses(11, arr);
    long long int* ans2 = excitingnessk(11, arr);
    for (int i = 0; i < 11; i++) {
        printf("%lld ", ans[i]);
        
    }
    printf("\n");
    for (int i = 0; i < 11; i++) {
        printf("%lld ", ans2[i]);     
    }
}