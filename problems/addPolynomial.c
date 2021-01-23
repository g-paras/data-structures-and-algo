#include<stdio.h>
#include<stdlib.h>


/*--------------- creating the node structure -----------------*/
struct node{
    int coef;
    int pow;
    struct node *next;
};


/*-------------- function to display the polynomial ------------*/
void display(struct node *poly) {
    while(poly->next != NULL) {
        printf(" %dx^%d ", poly->coef, poly->pow);
        poly = poly->next;
        if (poly->coef >= 0) {
            if (poly->next != NULL) {
                printf("+");
            }
        }
    }
    printf("\n");
}

/*-------- function to create a node for the polynomial --------*/
void createNode(struct node **poly, int coef, int pow) {
    struct node *r, *z;
    z = *poly;
    if (z == NULL) {
        r = malloc(sizeof(struct node));
        r->coef = coef;
        r->pow = pow;
        *poly = r;
        r->next = malloc(sizeof(struct node));
        r = r->next;
        r->next = NULL;
    } else {
        r->coef = coef;
        r->pow = pow;
        r->next = malloc(sizeof(struct node));
        r = r->next;
        r->next = NULL;
    }
}


/*---------------- function to add two polynomials --------------------*/
void polyAdd(struct node *poly1, struct node *poly2, struct node *poly){
    while (poly1->next && poly2->next) {
        if (poly1->pow > poly2->pow) {
            poly->pow = poly1->pow;
            poly->coef = poly1->coef;
            poly1 = poly1->next;
        }
        else if (poly1->pow < poly2->pow) {
            poly->pow = poly2->pow;
            poly->coef = poly2->coef;
            poly2 = poly2->next;
        }
        else {
            poly->pow = poly1->pow;
            poly->coef = poly1->coef + poly2->coef;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        poly->next = malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }

    while(poly1->next || poly2->next) {
        if (poly1->next) {
            poly->coef = poly1->coef;
            poly->pow = poly1->pow;
            poly1 = poly1->next;
        }
        if (poly2->next){
            poly->pow = poly2->pow;
            poly->coef = poly2->coef;
            poly2 = poly2->next;
        }
        poly->next = malloc(sizeof(struct node));
        poly = poly->next;
        poly->next = NULL;
    }

}


/*--------------------- main function --------------------------*/
void main() {
    struct node *poly1 = NULL, *poly2 = NULL, *poly = NULL;

    createNode(&poly1, 5, 2);
    createNode(&poly1, 6, 1);
    createNode(&poly1, 10, 0);
    
    printf("Polynomial 1: ");
    display(poly1);

    createNode(&poly2, -3, 1);
    createNode(&poly2, -7, 0);

    printf("Polynomial 2: ");
    display(poly2);
    
    poly = malloc(sizeof(struct node));
    
    polyAdd(poly1, poly2, poly);
    printf("After addition: ");
    display(poly);

    return;
}