#include "even.h"
#include <stdlib.h>

struct node* createeven() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> val = 2;
    newnode -> next = NULL;
    return newnode;
}

struct node *even(struct node *head) {
    struct node* current = head;
    if (!(current -> next)) {
        current -> next = createeven();
        return head;
    }

    while (current && current -> next) {
        if ((current -> val * current -> next -> val) % 2) {
            struct node* newnode = createeven();
            struct node* tmp = current -> next;
            current -> next = newnode;
            newnode -> next = tmp;
            current = tmp;
        }
        else {
            current = current -> next -> next;
        }
    }
    
    return head;
}