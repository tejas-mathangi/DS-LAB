#include <stdio.h>
#include <stdlib.h>

#define SIZE 5 // Defines the maximum size of the queue

int queue[SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    // Condition for a full queue in a circular array
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Enqueue: Add an element to the rear of the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue Overflow! Cannot add element.\n");
        return;
    }
    // If the queue is initially empty
    if (front == -1) {
        front = 0;
    }
    // Increment rear circularly
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("%d enqueued to queue.\n", value);
}

// Dequeue: Remove an element from the front of the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! Cannot remove element.\n");
        return;
    }
    int dequeuedElement = queue[front];

    // If there is only one element in the queue
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        // Increment front circularly
        front = (front + 1) % SIZE;
    }
    printf("Dequeued element: %d\n", dequeuedElement);
}

// Display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: FRONT -> ");
    int i;
    for (i = front; i != rear; i = (i + 1) % SIZE) {
        printf("%d ", queue[i]);
    }
    // Print the last element
    printf("%d -> REAR\n", queue[i]);
}

// Main menu-driven program
int main() {
    int choice, value;

    do {
        printf("\n--- Queue Using Array Menu ---\n");
        printf("1. Enqueue (Add element)\n");
        printf("2. Dequeue (Remove element)\n");
        printf("3. Display Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 0:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}


// ---

// Sample Run:

// --- Queue Using Array Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 1
// Enter value to enqueue: 10
// 10 enqueued to queue.

// --- Queue Using Array Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 1
// Enter value to enqueue: 20
// 20 enqueued to queue.

// --- Queue Using Array Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 3
// Queue: FRONT -> 10 20 -> REAR

// --- Queue Using Array Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 2
// Dequeued element: 10

// --- Queue Using Array Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 3
// Queue: FRONT -> 20 -> REAR

// --- Queue Using Array Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 0
// Exiting...