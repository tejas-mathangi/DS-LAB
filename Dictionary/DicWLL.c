#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 50
#define MAX_VAL_LEN 256

struct Node {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
    struct Node* next;
};

struct Node* createNode(const char* key, const char* value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

struct Node* addOrUpdate(struct Node* head, const char* key, const char* value) {
    struct Node* current = head;

    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            // update the value
            strcpy(current->value, value);
            printf("Key '%s' updated successfully.", key);
            return head; // Head does not change
        }
        current = current->next;
    }

    // create a new node and add it to the front
    struct Node* newNode = createNode(key, value);
    newNode->next = head;
    printf("Pair ('%s', '%s') added successfully.", key, value);
    return newNode; // New node is the new head
}

struct Node* deleteKey(struct Node* head, const char* key) {
    struct Node *temp = head, *prev = NULL;

    // Case 1: The key is at the head node
    if (temp != NULL && strcmp(temp->key, key) == 0) {
        head = temp->next; 
        free(temp);        
        printf("Key '%s' deleted successfully.", key);
        return head;
    }

    // Case 2: The key is somewhere else
    while (temp != NULL && strcmp(temp->key, key) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Error: Key '%s' not found.", key);
        return head;
    }

    prev->next = temp->next;
    free(temp); 
    printf("Key '%s' deleted successfully.", key);
    
    return head;
}
void getValue(struct Node* head, const char* key) {
    struct Node* current = head;
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            printf("Value for key '%s': %s", key, current->value);
            return;
        }
        current = current->next;
    }
    printf("Error: Key '%s' not found.", key);
}

void display(struct Node* head) {
    if (head == NULL) {
        printf("Dictionary is empty.");
        return;
    }
    printf("----- DICTIONARY CONTENTS -----\n");
    struct Node* current = head;
    int i = 1;
    while (current != NULL) {
        printf("%d: ('%s': '%s')\n", i, current->key, current->value);
        current = current->next;
        i++;
    }
    printf("-----------------------------\n");
}

int main() {
    struct Node* head = NULL; 

    int choice;
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];

    while(1) {
        printf("\n\n--- DICTIONARY (Linked List) MENU ---\n");
        printf("1. Add/Update a key-value pair\n");
        printf("2. Get value for a key\n");
        printf("3. Delete a key-value pair\n");
        printf("4. Display all pairs\n");
        printf("5. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%s", value);
                head = addOrUpdate(head, key, value);
                break;

            case 2:
                printf("Enter key to get value: ");
                scanf("%s", key);
                getValue(head, key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%s", key);
                head = deleteKey(head, key);
                break;

            case 4:
                display(head);
                break;
            
            case 5:
                printf("Exiting program. Goodbye!\n");
                // Free all nodes before exiting
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.");
        }
    }

    return 0;
}