#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Push operation (insert at beginning)
void push(struct Node** top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
    printf("%d pushed to stack\n", data);
}

// Pop operation (delete from beginning)
void pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow! Nothing to pop.\n");
        return;
    }
    struct Node* temp = *top;
    printf("%d popped from stack\n", temp->data);
    *top = temp->next;
    free(temp);
}

// Peek operation
void peek(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Top element is: %d\n", top->data);
}

// Display stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Menu-driven program
int main() {
    struct Node* top = NULL;
    int choice, data;

    do {
        printf("\n--- Stack Menu (Linked List Implementation) ---\n");
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
            push(&top, data);
            break;

        case 2:
            pop(&top);
            break;

        case 3:
            peek(top);
            break;

        case 4:
            display(top);
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


// ---

// Sample Run:

// --- Stack Menu (Linked List Implementation) ---
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

// Enter your choice: 4
// Stack elements: 10


// ---
