# Q3: Reverse Traversal of a Linked List

## 1. Overview
This program demonstrates how to traverse a singly linked list in **reverse order** without modifying the list itself.  
It uses **recursion** to print the elements from the last node to the first.  

The main focus of the program is to:
- Understand **linked list structure**
- Implement **reverse traversal** using recursion
- Demonstrate traversal with a simple list in `main()`




## 2. Data Structure Used
**Singly Linked List Node**

```c
struct Node {
    int data;
    struct Node* next;
};
```
- data: stores the value of the node
- next: pointer to the next node in the list
- This structure allows creation of a dynamic list of arbitrary length.

## 3. Purpose

- To display a linked list in reverse order without altering the list by applying recursion technique.
- To demonstrate modular coding using functions for node creation, display, and traversal.

## 4. Functions Implemented 
a. struct Node* createNode(int value)
- Allocates memory for a new node
- Sets data to value
- Sets next to NULL
- Returns a pointer to the newly created node

b. void display(struct Node* head)
- Traverses the list from the head node to the end
- Prints each node's data in normal order
- Ends with NULL to indicate the end of the list

c. void reverseTraversal(struct Node* head)
- Traverses the list in reverse order using recursion
- Base case: head == NULL → stops recursion
- Recursive step: calls itself with head->next
- After the recursive call returns, prints the current node's data

### Detail explanation of recursion function 
- First call: reverseTraversal(head) → head = 10
- - Calls reverseTraversal(head->next) → head = 20
-  Second call: head = 20
- - Calls reverseTraversal(head->next) → head = 30
- Third call: head = 30
- - Calls reverseTraversal(head->next) → head = 40
- Fourth call: head = 40
- - Calls reverseTraversal(head->next) → head = NULL
- Base case reached, recursion starts returning
- Returning phase:
Print 40 → return to previous call
Print 30 → return
Print 20 → return
Print 10 → return

## 5. Main Method Organization

- Nodes are manually created using createNode()
- The next pointers are linked manually to form the list
- The program demonstrates:
- Normal traversal using display()
- Reverse traversal using reverseTraversal()

## 6. Sample Output 
```
Normal Traversal:
10 -> 20 -> 30 -> 40 -> NULL

Reverse Traversal:
40 -> 30 -> 20 -> 10 -> NULL
```
