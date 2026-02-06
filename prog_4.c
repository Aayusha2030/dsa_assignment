/*
Program to demonstrate a doubly linked list in C.
Includes functions to create nodes, insert after a node, and delete after a node.
Initial nodes are created from an array with unique values.
*/

#include <stdio.h>
#include <stdlib.h>

/* Structure for a doubly linked list node */
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

/* Function to create a new node */
struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

/* Function to create a linked list from an array */
struct Node* makeList(int vals[], int size) {
    if (size == 0) return NULL;

    struct Node* head = newNode(vals[0]);
    struct Node* curr = head;

    for (int i = 1; i < size; i++) {
        struct Node* temp = newNode(vals[i]);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }

    return head;
}

/* Function to insert a node after a given node */
void insAfter(struct Node* node, int val) {
    if (node == NULL) {
        printf("Given node cannot be NULL.\n");
        return;
    }

    struct Node* n = newNode(val);
    n->next = node->next;
    n->prev = node;

    if (node->next != NULL) {
        node->next->prev = n;
    }

    node->next = n;
}

/* Function to delete a node after a given node */
void delAfter(struct Node* node) {
    if (node == NULL || node->next == NULL) {
        printf("No node exists after the given node to delete.\n");
        return;
    }

    struct Node* temp = node->next;
    node->next = temp->next;

    if (temp->next != NULL) {
        temp->next->prev = node;
    }

    free(temp);
}

/* Function to display the list in forward direction */
void showList(struct Node* head) {
    struct Node* curr = head;
    printf("List: ");
    while (curr != NULL) {
        printf("%d <-> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

/* Main function to demonstrate list operations */
int main() {
    // Initial values for the linked list
    int vals[] = {45, 50, 65, 70, 90};
    int n = sizeof(vals) / sizeof(vals[0]);

    // To Create the linked list from array
    struct Node* head = makeList(vals, n);

    printf("Initial List:\n");
    showList(head);

    // To Insert 60 after second node (Adding 50)
    insAfter(head->next, 60);
    printf("\nAfter inserting 60 after 50:\n");
    showList(head);

    // To Delete node after fourth node (deleting  70)
    delAfter(head->next->next->next);  // head->next->next->next points to 65 -> 70
    printf("\nAfter deleting 70:\n");
    showList(head);

    return 0;
}
