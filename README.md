Here’s a clean README-ready format with separate C code blocks and clear headings:

# Algorithms in C

## 1. Stack Implementation Using Array

```c
#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = x;
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        top--;
}

void display() {
    if (top == -1)
        printf("Stack is empty\n");
    else {
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}


---

2. Infix to Postfix Conversion

#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    else return stack[top--];
}

int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

int main() {
    char exp[MAX], x;
    printf("Enter infix expression: ");
    scanf("%s", exp);
    printf("Postfix: ");
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i]))
            printf("%c", exp[i]);
        else if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')') {
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i]))
                printf("%c", pop());
            push(exp[i]);
        }
    }
    while (top != -1)
        printf("%c", pop());
    printf("\n");
    return 0;
}


---

3. Linear Search and Binary Search

#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key) return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high)/2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter key to search: ");
    scanf("%d", &key);

    int pos = linearSearch(arr, n, key);
    if (pos != -1)
        printf("Linear Search: Found at position %d\n", pos+1);
    else
        printf("Linear Search: Not found\n");

    pos = binarySearch(arr, n, key);
    if (pos != -1)
        printf("Binary Search: Found at position %d\n", pos+1);
    else
        printf("Binary Search: Not found\n");

    return 0;
}


---

This format separates each algorithm, makes it readable on GitHub, and can be copy-pasted directly into your README.

I can also add input/output examples for each code snippet to make the README more professional. Do you want me to do that?

