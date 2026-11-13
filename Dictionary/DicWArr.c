#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 
#define MAX_KEY_LEN 50
#define MAX_VAL_LEN 256

struct Pair {
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];
};

struct Dictionary {
    struct Pair items[MAX_ITEMS];
    int count;
};

void initializeDictionary(struct Dictionary *dict) {
    dict->count = 0;
}

int findKeyIndex(struct Dictionary *dict, const char* key) {
    for (int i = 0; i < dict->count; i++) {
        if (strcmp(dict->items[i].key, key) == 0) {
            return i; // Key found
        }
    }
    return -1; // Key not found
}

void add(struct Dictionary *dict, const char* key, const char* value) {
    int index = findKeyIndex(dict, key);

    if (index != -1) {
        // Key already exists, update the value
        strcpy(dict->items[index].value, value);
        printf("Key '%s' updated successfully.", key);
    } else {
        // Key does not exist, add a new pair
        if (dict->count >= MAX_ITEMS) {
            printf("Error: Dictionary is full.");
            return;
        }
        strcpy(dict->items[dict->count].key, key);
        strcpy(dict->items[dict->count].value, value);
        dict->count++;
        printf("Pair ('%s', '%s') added successfully.", key, value);
    }
}

void deleteKey(struct Dictionary *dict, const char* key) {
    int index = findKeyIndex(dict, key);

    if (index == -1) {
        printf("Error: Key '%s' not found.", key);
        return;
    }

    // Shift all subsequent items one position to the left
    for (int i = index; i < dict->count - 1; i++) {
        dict->items[i] = dict->items[i + 1];
    }
    
    dict->count--;
    printf("Key '%s' deleted successfully.", key);
}

void getValue(struct Dictionary *dict, const char* key) {
    int index = findKeyIndex(dict, key);

    if (index != -1) {
        printf("Value for key '%s': %s", key, dict->items[index].value);
    } else {
        printf("Error: Key '%s' not found.", key);
    }
}

void display(struct Dictionary *dict) {
    if (dict->count == 0) {
        printf("Dictionary is empty.");
        return;
    }
    printf("----- DICTIONARY CONTENTS -----\n");
    for (int i = 0; i < dict->count; i++) {
        printf("%d: ('%s': '%s')\n", i + 1, dict->items[i].key, dict->items[i].value);
    }
    printf("-----------------------------\n");
}

int main() {
    struct Dictionary dict;
    initializeDictionary(&dict);

    int choice;
    char key[MAX_KEY_LEN];
    char value[MAX_VAL_LEN];

    while(1) {
        printf("\n\n------ DICTIONARY (Array) MENU ------\n");
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
                add(&dict, key, value);
                break;

            case 2:
                printf("Enter key to get value: ");
                scanf("%s", key);
                getValue(&dict, key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%s", key);
                deleteKey(&dict, key);
                break;

            case 4:
                display(&dict);
                break;
            
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter a number between 1 and 5.");
        }
    }

    return 0;
}

