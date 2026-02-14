# Q6: Building Min Heap and Max Heap from an Array
## 1. Overview
- This program demonstrates how to construct both Min Heap and Max Heap from an unsorted array.
- It uses the heapify process to arrange the elements so that they satisfy the heap property.

The main focus of the program is to:
- Understand heap structure
- Build a Min Heap where the parent is smaller than children
- Build a Max Heap where the parent is larger than children
- Demonstrate heap construction with an example array in main()

## 2. Data Structure Used

Array-based Heap Representation

int arr[SIZE];


arr[i]: stores the value of the i-th node

Heap is represented as a complete binary tree in an array:

Left child index = 2*i + 1

Right child index = 2*i + 2

Parent index = (i-1)/2

This array representation allows efficient access and modification of heap elements.