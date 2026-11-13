#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *prev , *next;
};

struct node* createNode(int val){
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next = newNode->prev = NULL;
    newNode->val = val;
    return newNode;
}

void insertAtFirst(struct node **head ,int val){
    struct node *newNode = createNode(val);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

void insertAtEnd(struct node **head ,int val){
    struct node *newNode = createNode(val);
    if(*head != NULL){
        
    }
}   