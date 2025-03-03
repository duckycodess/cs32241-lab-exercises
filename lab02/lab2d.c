#include "reverse_circ.h"

void reverse_circ(struct node *x){
    struct node* start = x;
    struct node* current = x;
    struct node* tmp = current -> next;
    current -> next = 0;
    current = tmp;

    struct node* prev = start;

    while (current -> next) {
        struct node* temp = current -> next;
        current -> next = prev;
        prev = current;
        current = temp;
    }
    start -> next = prev;
}