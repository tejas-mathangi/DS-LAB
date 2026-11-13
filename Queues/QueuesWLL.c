#include <stdio.h>
#include <stdlib.h>

// Node structure for the queue
struct Node {
    int data;
    struct Node* next;
};

// Queue structure containing front and rear pointers
struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    if (!q) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->front = q->rear = NULL;
    return q;
}

// Enqueue: Add an element to the rear of the queue
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);

    // If the queue is empty, the new node is both front and rear
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("%d enqueued to queue.\n", data);
        return;
    }

    // Add the new node to the end of the queue and update rear
    q->rear->next = newNode;
    q->rear = newNode;
    printf("%d enqueued to queue.\n", data);
}

// Dequeue: Remove an element from the front of the queue
void dequeue(struct Queue* q) {
    // Check for queue underflow
    if (q->front == NULL) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    // Store the current front and move front to the next node
    struct Node* temp = q->front;
    int dequeuedData = temp->data;

    q->front = q->front->next;

    // If front becomes NULL, the queue is now empty, so set rear to NULL as well
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    printf("Dequeued element: %d\n", dequeuedData);
}

// Display the elements in the queue
void displayQueue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue: FRONT -> ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("REAR\n");
}

// Main menu-driven program
int main() {
    struct Queue* q = createQueue();
    int choice, data;

    do {
        printf("\n--- Queue Using Linked List Menu ---\n");
        printf("1. Enqueue (Add element)\n");
        printf("2. Dequeue (Remove element)\n");
        printf("3. Display Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(q, data);
            break;

        case 2:
            dequeue(q);
            break;

        case 3:
            displayQueue(q);
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

// --- Queue Using Linked List Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 1
// Enter data to enqueue: 10
// 10 enqueued to queue.

// --- Queue Using Linked List Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 1
// Enter data to enqueue: 20
// 20 enqueued to queue.

// --- Queue Using Linked List Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 3
// Queue: FRONT -> 10 -> 20 -> REAR

// --- Queue Using Linked List Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 2
// Dequeued element: 10

// --- Queue Using Linked List Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 3
// Queue: FRONT -> 20 -> REAR

// --- Queue Using Linked List Menu ---
// 1. Enqueue (Add element)
// 2. Dequeue (Remove element)
// 3. Display Queue
// 0. Exit
// Enter your choice: 0
// Exiting...