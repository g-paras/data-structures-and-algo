#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*--------------- structure of stack data Structure ------------------*/
struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

/*------------------- function to create a Stack ---------------------*/
struct Stack* createStack(unsigned capacity) {
    struct Stack *stack = malloc(sizeof(struct Stack));

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int *) malloc(stack->capacity * sizeof(int));

    return stack;
}

/*-------------- check whether stack is empty or not -----------------*/
char isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

/*------------ pop the last recent from the stack --------------------*/
char pop(struct Stack *stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    else 
        return '$';
}

/*------------- return the recent item from the stack ----------------*/
char peek(struct Stack *stack) {
    return stack->array[stack->top];
}

/*-------------------- push an item to the stack ---------------------*/
void push(struct Stack *stack, char op) {
    stack->array[++stack->top] = op;
}

/*-------- function to return the precedence of the operator ---------*/
int precedence(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
    }
    return -1;
}

/*----------- check whether character is oprand or not ---------------*/
int isOperand (char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

/*---------- function to convert infix to postfix expression ---------*/
int infixToPostfix (char* exp) {
    int i, k;
    struct Stack *stack = createStack(strlen(exp));
    if (!stack)
        return -1;
    for (i=0, k=-1;exp[i]; ++i){
        if (isOperand(exp[i])){
            exp[++k] = exp[i];
        }
        else if (exp[i] == '(') {
            push(stack, exp[i]);
        }
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                exp[++k] = pop(stack);
            }
            if (!isEmpty(stack) && peek(stack) != '(') {
                return -1;
            } else {
                pop(stack);
            }
        }
        else {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack))) {
                exp[++k] = pop(stack);
            }
            push(stack, exp[i]);
        }
    }
    while (!isEmpty(stack)) {
        exp[++k] = pop(stack);
    }
    exp[++k] = '\0';
    printf("%s\n", exp);
}

/*----------------------- main function -----------------------------*/
int main() {
    char exp[] = "a+(b*c-(d/e-f)*g)*h";
    infixToPostfix(exp);
    return ;
}