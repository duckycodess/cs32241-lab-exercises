#include <stdio.h>
#include <stdlib.h>

struct planet {
    int planet_id;
    struct planet *portal;
};

struct planet *planet_k(struct planet *x, long long int k) {
    struct planet* current = x;
    if (k == 0){
        return x;
    }

    for (int i = 0; i < k; i++){
        current = current -> portal;
    }

    return current;
    
}



struct planet* createplanet(int planet_idue) {
    struct planet* newplanet = (struct planet*)malloc(sizeof(struct planet));
    newplanet -> planet_id = planet_idue;
    newplanet -> portal = NULL;
    return newplanet;
}

struct planet* buildLinkedList(){
    struct planet* head = (struct planet*)malloc(sizeof(struct planet));
    struct planet* current = head;
    for (int i = 1; i < 11; i++) {
        current -> portal = createplanet(i);
        current = current -> portal;
    }
    current -> portal = head -> portal;
    return head -> portal;
}

void printLinkedList(struct planet* head) {
    for (int current = 1; current < 11; current++) {
        printf("%d ", head -> planet_id);
        
        head = head -> portal;
    }
    printf("\n");
}

void printHead(struct planet* head) {
    printf("%d\n", head -> planet_id);
}

int main() {
    struct planet* linkedlist = buildLinkedList();
    printLinkedList(linkedlist);
    struct planet* k = planet_k(linkedlist, 12);
    printLinkedList(k);
    printHead(k);

}