#include "reverse2.h"
#include <stdlib.h>

struct node *reverse(struct node *head) {
    if (head == NULL) return head;

    struct node* current = head;
    struct node* previous = NULL;
    while (current){
        struct node* tmp = current -> next;
        current -> next = previous;
        current -> prev = tmp;
        previous = current;
        current = tmp;
    }
    previous -> prev = NULL;
    head = previous;

    return head;
}