#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

void print_list(struct node* head) {
    while (head) {
        printf("%d -> ", head->val);
        
        head = head->next;
    }
    printf("NULL\n");
}

struct node* createLinkedList(int arr[], int size) {
    if (size == 0) return NULL;

    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->val = arr[0];
    head->next = NULL;

    struct node* current = head;

    for (int i = 1; i < size; i++) {
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->val = arr[i];
        newnode->next = NULL;
        current->next = newnode;
        current = newnode;
    }

    return head;
}


int main() {
    int arr[] = {3, 1, 2, 2, 5, 6, 1, 4, 5, 5, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    struct node* head = createLinkedList(arr, size);
    printf("Original Linked List: ");
    print_list(head);
    struct node *result;
    int streaks_count = sorted_streaks(head, &result);

    printf("Number of streaks: %d\n", streaks_count);
    for (int i = 0; i < streaks_count; i++) {
        printf("Streak %d: ", i + 1);
        print_list((result));
        
    }

    
    for (int i = 0; i < streaks_count; i++) {
        struct node* current = (result + i);
        while (current) {
            struct node* tmp = current;
            current = current->next;
            free(tmp);
        }
    }
    free(result);
    
    return 0;
}