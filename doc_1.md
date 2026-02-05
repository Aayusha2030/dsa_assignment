# Q1: Balanced Parentheses Checker (Using Stack)

## 1. Overview
This program checks whether a mathematical expression has balanced parentheses.  
It uses a **stack** to store opening brackets and matches them with closing brackets as it scans the expression.

---

## 2. Data Structures Used
**Stack**

```c
typedef struct Stack {
    int top;
    char elements[MAX];
} Stack;

top: stores the index of the top element in the stack.

elements[MAX]: array to store characters (, [, {.

The stack follows LIFO (Last In, First Out) principle, which is ideal for matching parentheses.

3. Purpose

To determine if each opening bracket in an expression has a corresponding closing bracket in the correct order.

Supports all three types of brackets: (), [], {}.

Provides a modular solution using separate functions for stack operations and matching logic.

4. Functions Implemented
a. push(Stack* s, char ch)

Adds an opening bracket to the stack.

Checks for stack overflow.

Increments top and stores the character.

b. pop(Stack* s)

Removes and returns the top element from the stack.

Checks for stack underflow.

Returns \0 if the stack is empty.

c. isPair(char open, char close)

Checks if the opening and closing brackets form a valid pair.

Returns 1 if matched, otherwise 0.

d. checkBalanced(char* expr)

Core logic to check if the expression is balanced.

Iterates through each character:

Pushes opening brackets onto the stack.

Pops and matches closing brackets.

Returns 0 immediately if a mismatch or unmatched closing bracket is found.

Returns 1 if all brackets match and the stack is empty at the end.

5. Main Method Organization

Defines an array of test expressions.

Loops through each expression and calls checkBalanced().

Prints whether each expression is Balanced or Unbalanced.

Demonstrates the correctness of the stack-based approach.

6. Sample Output
Parentheses Balance Checker

Expression: a+(b-c)*(d
Result: Unbalanced

Expression: m+[a-b*(c+d*{m)]
Result: Unbalanced

Expression: a+(b-c)
Result: Balanced
