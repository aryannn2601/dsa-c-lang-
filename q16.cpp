
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insertFront(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *head;
    newNode->prev = NULL;

    if (*head != NULL)
        (*head)->prev = newNode;

    *head = newNode;
}

// Usage example:
int main() {
    struct Node* head = NULL;
    insertFront(&head, 42); // Insert 42 at the front
    // ... other operations or traversal
    return 0;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
}

void deleteLast(struct Node** head) {
    if (*head == NULL)
        return;

    struct Node* last = *head;
    while (last->next != NULL)
        last = last->next;

    if (last->prev != NULL)
        last->prev->next = NULL;

    free(last);
}

void deleteBeforePosition(struct Node** head, int position) {
    if (*head == NULL || position <= 1)
        return;

    struct Node* current = *head;
    for (int i = 1; i < position - 1 && current != NULL; ++i)
        current = current->next;

    if (current == NULL || current->prev == NULL)
        return;

    struct Node* prevNode = current->prev;
    prevNode->next = current->next;
    if (current->next != NULL)
        current->next->prev = prevNode;

    free(current);
}

void traverse(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

