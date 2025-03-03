#include "splice.h"

struct node *splice(struct node **head, int i, int j) {
    struct node dummy;
    
    struct node* current = &dummy;
    current -> next = *head;
    for (int start = 0; start < i; start++) {
        current = current -> next;
        
    }
    struct node* ith = current -> next;
    struct node* end = current -> next;
    for (int stop = i; stop < j-1; stop++){
        end = end -> next;
    }
    struct node* tmp = end -> next;
    end ->next = 0;
    current -> next = tmp;
    
    *head = dummy.next;
    return ith;
}