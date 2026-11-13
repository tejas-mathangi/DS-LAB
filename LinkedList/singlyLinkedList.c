#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
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

// Insert at beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a given position (1-based index)
void insertAtPosition(struct Node** head, int data, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node by value
void deleteNode(struct Node** head, int key) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element not found!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", key);
}

// Search for a value
void searchNode(struct Node* head, int key) {
    int position = 1;
    struct Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d\n", key, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Element %d not found in the list\n", key);
}

// Display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main menu-driven program
int main() {
    struct Node* head = NULL;
    int choice, data, pos;

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Node\n");
        printf("5. Search Node\n");
        printf("6. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;

        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;

        case 3:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(&head, data, pos);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteNode(&head, data);
            break;

        case 5:
            printf("Enter value to search: ");
            scanf("%d", &data);
            searchNode(head, data);
            break;

        case 6:
            displayList(head);
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

// --- Singly Linked List Menu ---
// 1. Insert at Beginning
// 2. Insert at End
// 3. Insert at Position
// 4. Delete Node
// 5. Search Node
// 6. Display List
// 0. Exit
// Enter your choice: 1
// Enter data: 10

// Enter your choice: 2
// Enter data: 20

// Enter your choice: 6
// 10 -> 20 -> NULL

// Enter your choice: 5
// Enter value to search: 20
// Element 20 found at position 2


// ---