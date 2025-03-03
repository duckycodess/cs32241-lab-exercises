#include "sorted_streaks.h"
#include <stdlib.h>

int sorted_streaks(struct node *head, struct node **result) {
    int i = 0;
    struct node* current = head;
    *result = (struct node*)malloc(200000 * sizeof(struct node));
    while (current) {
        struct node* new_head = current;
        int length = 1;
        while (current -> next && current -> val <= current -> next -> val) {
            current = current -> next;
            length++;
        }
        struct node* tmp = current -> next;
        
        current -> next = NULL;
        print_list(new_head);
        
        *(result) = NULL;
        *(result++) = new_head;

        current = tmp;
        i++;
        
    }
    return i;
}

