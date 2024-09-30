#include <stdio.h>
#include <stdlib.h>

// Define the circular linked list node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize an empty list (both head and tail are NULL)
struct Node* head = NULL;
struct Node* tail = NULL;

// Function to insert a node at the end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head; // Point back to itself
    } else {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

// Function to insert before a specified position
void insertBeforePosition(int value, int position) {
    // Similar to insertion at the end, but find the (position-1)-th node
    // and adjust pointers accordingly
    // ...
}

// Function to delete the first node
void deleteFirstNode() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head == tail) {
        free(head);
        head = tail = NULL;
    } else {
        struct Node* temp = head;
        head = head->next;
        tail->next = head; // Update tail's next pointer
        free(temp);
    }
}

// Function to delete after a specified position
void deleteAfterPosition(int position) {
    // Similar to insertion before a specified position, but adjust pointers
    // to remove the k-th node
    // ...
}

// Function to traverse and print the list
void traverse() {
    struct Node* current = head;
    if (current == NULL) {
        printf("List is empty.\n");
        return;
    }
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    // Example usage
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    traverse(); // Should print: 10 20 30

    // You can call other functions here to test the remaining operations
    // ...

    return 0;
}
