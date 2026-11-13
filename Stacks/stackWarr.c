#include <stdio.h>
#include <stdlib.h>
#define MAX 100   // maximum size of stack

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Initialize stack
void initStack(struct Stack* s) {
    s->top = -1;
}

// Check if stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Push operation
void push(struct Stack* s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", data);
        return;
    }
    s->arr[++s->top] = data;
    printf("%d pushed to stack\n", data);
}

// Pop operation
void pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    printf("%d popped from stack\n", s->arr[s->top--]);
}

// Peek operation
void peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element is: %d\n", s->arr[s->top]);
}

// Display stack elements
void display(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Menu-driven program
int main() {
    struct Stack s;
    initStack(&s);
    int choice, data;

    do {
        printf("\n--- Stack Menu (Array Implementation) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to push: ");
            scanf("%d", &data);
            push(&s, data);
            break;

        case 2:
            pop(&s);
            break;

        case 3:
            peek(&s);
            break;

        case 4:
            display(&s);
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}

// Sample Run:

// --- Stack Menu (Array Implementation) ---
// 1. Push
// 2. Pop
// 3. Peek
// 4. Display
// 0. Exit
// Enter your choice: 1
// Enter data to push: 10
// 10 pushed to stack

// Enter your choice: 1
// Enter data to push: 20
// 20 pushed to stack

// Enter your choice: 4
// Stack elements: 20 10

// Enter your choice: 3
// Top element is: 20

// Enter your choice: 2
// 20 popped from stack
