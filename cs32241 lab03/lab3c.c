#include <stdlib.h>
#include "bucketize.h"

typedef struct node node;

int nasan_yung_max(node *head);

int nasan_yung_max(node *head) {
    int max = 0;
    node *curr = head;
    
    while (curr != NULL) {
        if (curr->key > max) {
            max = curr->key;
        }
        curr = curr->next;
    }
    
    return max;
}

int bucketize(node *head, node ***res) {
    if (head == NULL) {
        *res = NULL;
        return 0;
    }
    
    int max = nasan_yung_max(head);
    
    node **bkts = (node **) malloc((max + 1) * sizeof(node *));
    
    for (int i = 0; i <= max; i++) {
        bkts[i] = NULL;
    }
    node *curr = head;
    while (curr != NULL) {
        int key = curr->key;
        node *nxt = curr->next;
        curr->next = NULL;
        bkts[key]->next = curr;
        
        curr = nxt;
    }
    
    *res = bkts;

    return max + 1;
}
