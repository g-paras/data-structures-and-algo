#include<stdio.h>
#include<stdlib.h>

#define MAX 10

/*--------------------- structure of stack ----------------------*/
struct stack{
    int items[MAX];
    int top;
};

/*------------ function to create an empty stack ----------------*/
void createEmptyStack(struct stack *s){
    s->top = -1;
}

/*------ function to check whether the stack is full or not -----*/
int isFull(struct stack *s) {
    if (s->top == MAX-1)
        return 1;
    else 
        return 0;
}

/*------- function to check if the stack is empty or not --------*/
int isEmpty(struct stack *s) {
    if (s->top == -1) 
        return 1;
    else 
        return 0;
}

/*----------- function to push an item to the stack -------------*/
void push(struct stack *s, int val) {
    if (isFull(s))
        printf("Stack Full\n");
    else {
        s->top++;
        s->items[s->top] = val;
    }
}

/*-------- function to pop the last element of the stack --------*/
int pop(struct stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        return s->items[s->top--];
    }
}

/*------------------ function to display a stack ----------------*/
void display(struct stack *s) {
    if (isEmpty(s))
        printf("Stack is Empty");
    else {
        printf("Stack: ");
        for (int i=0; i<=s->top; i++) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

/*------------------------- main function -----------------------*/
void main() {
    struct stack *st = malloc(sizeof(struct stack));
    createEmptyStack(st);
    push(st, 1);
    push(st, 5);
    push(st, 2);
    display(st);
    pop(st);
    display(st);
    free(st);    
}