# Q4: Doubly Linked List (Insert/Delete After a Node)

## 1. Overview
This program demonstrates a **doubly linked list** in C.  
It includes functions to:

- Create nodes
- Insert a new node **after a given node**
- Delete a node **after a given node**

The list is displayed in the **forward direction** to show the changes clearly.

---

## 2. Data Structures Used: Doubly Linked List
```c
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
```
- data = stores the value of the node
- prev = points to the previous node
- next = points to the next node

A doubly linked list allows traversal in both directions and makes insertion/deletion easier at any position.


## 3. Purpose
- To demonstrate node insertion and deletion  after a specific node.
- To maintain proper prev and next links during operations.
- To provide a modular solution with separate functions for creation, insertion, deletion, and display.


## 4. Functions Implemented

### a. struct Node* newNode(int val)
- Creates a new node with the given value
- Initializes prev and next to NULL

### b. struct Node* makeList(int vals[], int size)
- Creates the initial linked list from an array of values
- Links nodes together to form a doubly linked list

### c. void insAfter(struct Node* node, int val)
- Inserts a new node immediately after the given node
- Updates next and prev pointers to maintain list integrity

### d. void delAfter(struct Node* node)
- Deletes the node immediately after the given node
- Updates next and prev pointers to maintain list integrity
- Frees the memory of the deleted node

### e. void showList(struct Node* head)
- Displays the list in the forward direction
- Prints each node's value separated by <->

# 5. Main Method Organization
- Manually defines an array of initial values: 45, 50, 65, 70, 90
- Creates the linked list using makeList()
- Displays the initial list using showList()
- Inserts 60 after the node with value 50
- Deletes the node with value 70
- Displays the list after each operation to demonstrate changes

## 6. Sample Output
```
Initial List:
List: 45 <-> 50 <-> 65 <-> 70 <-> 90 <-> NULL

After inserting 60 after 50:
List: 45 <-> 50 <-> 60 <-> 65 <-> 70 <-> 90 <-> NULL

After deleting 70:
List: 45 <-> 50 <-> 60 <-> 65 <-> 90 <-> NULL
```

