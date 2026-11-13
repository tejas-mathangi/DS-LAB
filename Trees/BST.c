#include <stdio.h>
#include <stdlib.h>

// Node structure for the BST
struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

// Function to create a new BST node
struct Node* createNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to insert a new key in BST
struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

// Function to search for a key in a BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (root->key < key) {
        return search(root->right, key);
    }
    return search(root->left, key);
}

// Function for In-order traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function for Pre-order traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for Post-order traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// Helper function to find the node with the minimum key value
struct Node* findMinValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}


// Function to delete a key from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMinValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Main function with menu-driven interface
int main() {
    struct Node* root = NULL;
    int choice, key;

    while (1) {
        printf("\n\n----- BINARY SEARCH TREE MENU -----\n");
        printf("1. Insert a key\n");
        printf("2. Delete a key\n");
        printf("3. Search for a key\n");
        printf("4. Display In-order\n");
        printf("5. Display Pre-order\n");
        printf("6. Display Post-order\n");
        printf("7. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                root = insert(root, key);
                printf("Key %d inserted.", key);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                if (search(root, key) == NULL) {
                    printf("Key %d not found in the tree.", key);
                } else {
                    root = deleteNode(root, key);
                    printf("Key %d deleted.", key);
                }
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key) != NULL) {
                    printf("Key %d found in the BST.", key);
                } else {
                    printf("Key %d not found in the BST.", key);
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("Tree is empty.");
                } else {
                    printf("In-order traversal: ");
                    inorder(root);
                }
                break;
            
            case 5:
                if (root == NULL) {
                    printf("Tree is empty.");
                } else {
                    printf("Pre-order traversal: ");
                    preorder(root);
                }
                break;
            
            case 6:
                if (root == NULL) {
                    printf("Tree is empty.");
                } else {
                    printf("Post-order traversal: ");
                    postorder(root);
                }
                break;

            case 7:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice! Please enter a number between 1 and 7.");
        }
    }

    return 0;
}