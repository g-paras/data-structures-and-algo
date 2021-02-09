#include<stdio.h>
#include<stdlib.h>

/* create node for the queue */
struct Node {
    int data;
    struct Node *next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Node *newNode(int k) {
    struct Node *temp = malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}