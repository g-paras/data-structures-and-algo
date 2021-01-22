#include<stdio.h>
#include<stdlib.h>

/*----------------------------- a linked list node -----------------------------*/
struct node {
    int data;
    struct node *next;
};


/*-------------------- function to display linked list -------------------------*/
void display(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d-->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


/*----------------------- get length of the linked list ------------------------*/
int size(struct node *head) {
    int length = 0;
    struct node *ptr = head;
    while (ptr != NULL){
        length++;
        ptr = ptr->next;
    }
    return length;
}


/*----------------- function to insert a new node at the end -------------------*/
void insertAtEnd(struct node **head, int val) {
    struct node *newNode, *ptr = (*head);
    newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;

    if ((*head) == NULL) {
        *head = newNode;
        return;
    }

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = newNode;
}


/*-------- function to insert a new node at the start of linked list -----------*/
void insertAtStart(struct node **head, int val) {
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = (*head);
    (*head) = newNode;
}


/*------------ function to insert a node after a given a node ------------------*/
void inserAfter(struct node **prev, int val) {
    if ((*prev) == NULL) {
        printf("Input node is null");
        return;
    }
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = (*prev)->next;
    (*prev)->next = newNode;
}


/*----- function to delete a node from the likedlist with a specific key -------*/
void deleteNode(struct node **head, int key) {
    struct node *temp = *head;
    struct node *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    
    prev->next = temp->next;
    free(temp);

}


/*------------------------------- main function --------------------------------*/
void main() {
    struct node *head = NULL;
    insertAtEnd(&head, 2);
    insertAtStart(&head, 1);
    insertAtEnd(&head, 3);
    display(head);
    printf("The length of the linked list is %d\n", size(head));
    return;
}