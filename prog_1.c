/* 
Program to check if a mathematical expression has balanced parentheses.
Uses a stack to keep track of opening brackets and matches them with closing brackets.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // maximum size of stack

// Define stack structure
typedef struct Stack {
    int top;
    char elements[MAX];
} Stack;

// Function to add a character to the stack
void push(Stack* s, char ch) {
    if (s->top == MAX - 1) {
        // Stack is full, cannot push more
        return;
    }
    s->elements[++(s->top)] = ch;  // increase top, then store the character
}

// Function to remove a character from the stack
char pop(Stack* s) {
    if (s->top == -1) {
        // Stack is empty
        return '\0'; // return null character
    }
    return s->elements[(s->top)--]; // return top element, then decrease top
}

// Function to check if opening and closing brackets match
int isPair(char open, char close) {
    if (open == '(' && close == ')') return 1;
    if (open == '[' && close == ']') return 1;
    if (open == '{' && close == '}') return 1;
    return 0;
}

// Function to check if expression has balanced brackets
int checkBalanced(char* expr) {
    Stack stack;
    stack.top = -1;  // initialize empty stack
    int length = strlen(expr);

    for (int i = 0; i < length; i++) {
        char ch = expr[i];

        // If it is an opening bracket, push to stack
        if (ch == '(' || ch == '[' || ch == '{') {
            push(&stack, ch);
        }

        // If it is a closing bracket
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.top == -1) {
                // Stack empty but found a closing bracket → unbalanced
                return 0;
            }

            if (!isPair(pop(&stack), ch)) {
                // Top of stack does not match closing bracket → unbalanced
                return 0;
            }
        }
    }

    // Expression is balanced only if stack is empty at the end
    return (stack.top == -1);
}

int main() {
    // Test expressions
    char* expressions[] = {
        "a+(b-c)*(d",       // missing closing bracket
        "m+[a-b*(c+d*{m)]", // mismatched brackets
        "a+(b-c)"           // balanced
    };

    printf("Parentheses Balance Checker\n\n");

    for (int i = 0; i < 3; i++) {
        printf("Expression: %s\n", expressions[i]);
        if (checkBalanced(expressions[i])) {
            printf("Result: Balanced\n\n");
        } else {
            printf("Result: Unbalanced\n\n");
        }
    }

    return 0;
}
