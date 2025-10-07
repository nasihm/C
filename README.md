# C
1. Stack Implementation Using Array (User Input)

#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped: %d\n", stack[top--]);
}

void display() {
    if (top == -1)
        printf("Stack Empty\n");
    else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

Sample Output:

1.Push
2.Pop
3.Display
4.Exit
Enter choice: 1
Enter value: 10
Enter choice: 1
Enter value: 20
Enter choice: 3
Stack: 20 10
Enter choice: 2
Popped: 20
Enter choice: 3
Stack: 10


---

2. Infix to Postfix Conversion (User Input)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[50];
int top = -1;

void push(char c) { stack[++top] = c; }
char pop() { return stack[top--]; }
char peek() { return stack[top]; }

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void infixToPostfix(char infix[]) {
    char postfix[50];
    int i = 0, k = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i]))
            postfix[k++] = infix[i];
        else if (infix[i] == '(')
            push(infix[i]);
        else if (infix[i] == ')') {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(peek()) >= precedence(infix[i]))
                postfix[k++] = pop();
            push(infix[i]);
        }
        i++;
    }
    while (top != -1)
        postfix[k++] = pop();
    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[50];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix);
}

Sample Output:

Enter infix expression: A+B*C
Postfix: ABC*+


---

3. Linear and Binary Search (User Input)

#include <stdio.h>

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main() {
    int n, key, arr[100];
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (sorted for binary search): ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    int lin = linearSearch(arr, n, key);
    int bin = binarySearch(arr, n, key);

    if (lin != -1) printf("Linear Search: Found at index %d\n", lin);
    else printf("Linear Search: Not found\n");

    if (bin != -1) printf("Binary Search: Found at index %d\n", bin);
    else printf("Binary Search: Not found\n");
}

Sample Output:

Enter number of elements: 5
Enter 5 elements (sorted for binary search): 10 20 30 40 50
Enter key to search: 30
Linear Search: Found at index 2
Binary Search: Found at index 2

