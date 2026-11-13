#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next; // Pointer to the next node
    struct Node* prev; // Pointer to the previous node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // New node's next points to the current head
    newNode->next = *head_ref;
    // Current head's prev points to the new node
    (*head_ref)->prev = newNode;
    // The head pointer is updated to the new node
    *head_ref = newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head_ref, int data) {
    struct Node* newNode = createNode(data);

    // If the list is empty, the new node becomes the head
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    // Traverse to the last node
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Link the last node to the new node
    last->next = newNode;
    // Link the new node back to the last node
    newNode->prev = last;
}

void insertAtPosition(struct Node** head_ref, int data, int position) {
    if (position < 0) {
        printf("Invalid position!\n");
        return;
    }
    
    if (position == 0) {
        insertAtBeginning(head_ref, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = *head_ref;

    // Traverse to the node just before the desired position
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    // If the position is beyond the current list length
    if (current == NULL) {
        printf("Position out of bounds. Inserting at the end.\n");
        insertAtEnd(head_ref, data);
        return;
    }

    // Adjust the pointers to insert the new node
    newNode->next = current->next;
    newNode->prev = current;

    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}
// Function to delete a node with a given key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;

    // Find the node with the given key
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If the key is not found
    if (temp == NULL) {
        printf("Node with key %d not found.\n", key);
        return;
    }

    // If the node to be deleted is the head
    if (*head_ref == temp) {
        *head_ref = temp->next;
    }

    // Change next only if the node to be deleted is NOT the last node
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // Change prev only if the node to be deleted is NOT the first node
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Free the memory of the deleted node
    free(temp);
    printf("Node with key %d deleted.\n", key);
}

// Function to display the list from beginning to end
void displayList(struct Node* head_ref){
    struct Node* temp = head_ref;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to free the entire list to prevent memory leaks
void freeList(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

// Main function to demonstrate the operations
int main() {
    struct Node* head = NULL; // Start with an empty list

    // Insert nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 30);

    printf("Initial list:\n");
    displayList(head);
    printf("\n");

    // Delete a node
    printf("Deleting node 20:\n");
    deleteNode(&head, 20);
    displayList(head);
    printf("\n");
    
    // Delete head node
    printf("Deleting node 5 (head):\n");
    deleteNode(&head, 5);
    displayList(head);
    printf("\n");

    // Free the list memory before exiting
    freeList(&head);
    printf("List freed.\n");

    return 0;
}

// Output :

// Initial list:
// 5 10 20 30 
// Deleting node 20:
// Node with key 20 deleted.
// 5 10 30 
// Deleting node 5 (head):
// Node with key 5 deleted.
// 10 30 