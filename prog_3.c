/*
Program to demonstrate reverse traversal of a singly linked list.
Uses recursion to print the list in reverse order.
*/

#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Create a new node */
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* Display list in normal order */
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Reverse traversal using recursion */
void reverseTraversal(struct Node* head) {
    if (head == NULL) return;
    reverseTraversal(head->next);
    printf("%d -> ", head->data);
}

/* Main function to demonstrate reverse traversal */
int main() {
    // Manually create nodes
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Normal Traversal:\n");
    display(head);

    printf("\nReverse Traversal:\n");
    reverseTraversal(head);
    printf("NULL\n");

    return 0;
}
