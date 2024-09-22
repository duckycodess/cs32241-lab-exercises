#include "reverse.h"

struct node *reverse(struct node *head){
    struct node* current = head;
    struct node* prev = 0;
    while (current) {
        struct node* tmp = current -> next;
        current -> next = prev;
        prev = current;
        current = tmp;
    }
    return prev;
    
}