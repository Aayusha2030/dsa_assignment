# Qn 6: Min Heap and Max Heap Builder :

## Overview  
This program builds both a **Min Heap** and a **Max Heap** from an unsorted array entered by the user.
Instead of sorting the entire array, the program reorganizes the elements so that they satisfy the heap property:

- In a **Min Heap**, the smallest element is always at the root.
- In a **Max Heap**, the largest element is always at the root.

The program demonstrates how the heap structure is built using the **heapify algorithm** and how the same input can produce two different heap structures.


## 1 Explanation of Data Structures  

### a. Array Representation of Heap  

The heap is implemented using a simple **array**:

```c
int data[SIZE];
```
Heaps are complete binary trees, but instead of using tree nodes and pointers, they are stored inside an array for efficiency.

For any element at index i:
- Left Child → 2*i + 1
- Right Child → 2*i + 2
- Parent → (i - 1) / 2

This formula allows us to move between parent and child nodes easily without using a tree structure.

### b. Copy Array
```c
int copyArr[SIZE];
```
A second array is created to build the Max Heap separately.
This ensures that the Min Heap construction does not overwrite the original input before building the Max Heap.

## 2. Description of Implemented Functions:
### a.  makeMinHeap(int arr[], int n, int i)
This function maintains the Min Heap property at index i.
How it works:
- Assumes current index is smallest.
- Compares it with left and right children.
- If a child is smaller, swap occurs.
- Recursively calls itself to fix the affected subtree.
-Purpose: Ensures the subtree rooted at index i satisfies Min Heap rules.

### b. buildMyMinHeap(int arr[], int n)
- Builds a complete Min Heap from an unsorted array.
How it works:
- Starts from the last non-leaf node.
- Calls makeMinHeap() for each node moving upward.

### c. makeMaxHeap(int arr[], int n, int i)
 This function maintains the Max Heap property at index i.
 How it works:
- Assumes current index is largest.
- Compares with left and right children.
- Swaps if a child is larger.
- Recursively fixes the affected subtree.
- Purpose: Ensures the subtree satisfies Max Heap rules.

### d. buildMyMaxHeap(int arr[], int n)
- Builds a complete Max Heap from the array.
How it works:
- Starts from last non-leaf node.
- Calls makeMaxHeap() upward to the root.
-Purpose: Converts the array into a valid Max Heap efficiently.

### e.showArray(int arr[], int n)
- Prints the array elements.
Purpose: Displays the resulting Min Heap and Max Heap structures

## 3. Organization of the main() method :
The main() function follows a simple and clear structure:
- User enters the number of elements.
- User inputs the array elements.
- A copy of the array is created.
- buildMyMinHeap() is called on the original array.
- The Min Heap is displayed.
- buildMyMaxHeap() is called on the copied array.
- The Max Heap is displayed.


### 4. Sample Output :
```
Enter number of elements: 6
Enter elements:
10 40 20 5 30 15

Min Heap:
5 10 15 40 30 20

Max Heap:
40 30 20 5 10 15
```

