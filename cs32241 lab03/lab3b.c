#include "squares.h"
#include <stdlib.h>

int csq(int v);

int csq(int v) {
    if (v < 0) return 0;
    if (v== 0) return 1;
    long long int l = 0;
    long long int r = v;

    while (l <= r) {
        long long int m = (l)+(r-l)/2;
        long long int s = m*m;
        if (s == v) return 1;
        else if (s < v) l = m + 1;
        else if (s > v) r = m-1;
    }
    return 0;
}

int squares(struct node *head, int **res){
    if (!head) return 0;
    struct node* actual = head;
    struct node* current = head;
    long int i = 0;
    
    while (current) {
        int x = csq(current -> val);
        if (x){
            i++;
        }
        current = current -> next;
    }
    if (i >0) *res = (int*)malloc(sizeof(int)*i);
    long int j = 0;
    while (actual) {
        int y = csq(actual -> val);
        if (y){
            (*res)[j] = actual -> val;
            j++;
        }
        actual = actual -> next;
    }
    return i;
}