# Infix to Postfix Conversion and Evaluation Program
## Overview
This C program converts a **mathematical expression** in **infix notation** (e.g., `3+4*2`) to **postfix notation** (Reverse Polish Notation, e.g., `342*+`) and then **evaluates** the postfix expression to calculate the result.  

The program uses a **stack data structure** to handle operators, parentheses, and operator precedence.


## Features
- Handles operators: `+`, `-`, `*`, `/`, `^` (exponentiation)
- Handles parentheses `(` and `)`
- Evaluates **single-digit operands** (0-9)
- Maintains correct **operator precedence** and **associativity**
- Implements **stack operations**: push, pop, peek, and empty check

## Program Structure
### 1. Stack Implementation
```c
typedef struct {
    int top;
    char items[SIZE];
} CharStack;

void initCharStack(CharStack* st);
void pushChar(CharStack* st, char ch);
char popChar(CharStack* st);
char peekChar(CharStack* st);
