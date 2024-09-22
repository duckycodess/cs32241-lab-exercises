#include "distance.h"

int distance(struct node *a, struct node *b) {
    int length = 0;
    if (a == b){
        return 0;
    }
    struct node* currenta = a;
    struct node* currentb = b;
    
    while (currenta && currentb){
        currenta = currenta -> next;
        currentb = currentb -> next;
    }

    if (currenta){
        while (a != b){
            a = a -> next;
            length++;
        }
    }
    else {
        while (a != b){
            b = b -> next;
            length++;
        }
    }

    return length;

}