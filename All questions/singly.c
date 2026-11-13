#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

struct node* createNode(int val){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->next=NULL;
    newNode->val = val;
    return newNode;
}

void insertAtFirst(struct node **head , int val){
    struct node* newNode = createNode(val);
    newNode->next=*head;
    *head = newNode;
}

void insertAtEnd(struct node **head , int val){
    struct node* newNode = createNode(val);
    if(head==NULL){
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next!=NULL){
       temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAtFirst(struct node **head){
    if (head == NULL){
        printf("Empty list");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtLast(struct node **head){
    if (head == NULL){
        printf("Empty list");
        return;
    }
    struct node *temp = *head;

    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        return;
    }

    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}
