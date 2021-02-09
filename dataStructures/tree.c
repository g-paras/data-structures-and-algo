#include<stdio.h>
#include<stdlib.h>

/*---------------------- structure of tree ----------------------*/
struct Node {
    int item;
    struct Node *left;    
    struct Node *right;    
};

/*------------------ function to create a node ------------------*/
struct Node *createNode(int val) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->item = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/*----- function to insert a new node at the left of node ------*/
struct Node *insertLeft(struct Node *root, int val) {
    root->left = createNode(val);

    return root->left;
}

/*----- function to insert a new node at the right of node -----*/
struct Node *insertRight(struct Node *root, int val) {
    root->right = createNode(val);

    return root->right;
}

/*----------- function to perform inorder traversal ------------*/
void inorderTraversal (struct Node *root) {
    if (root == NULL) 
        return;
    inorderTraversal(root->left);
    printf("%d -> ", root->item);
    inorderTraversal(root->right);
}

/*------------- function to insert an item in bst --------------*/
void insert(struct Node **root, int data) {
    if ((*root) == NULL) {
        struct Node *newNode = malloc(sizeof(struct Node));
        newNode->item = data;
        newNode->left = newNode->right = NULL;
        (*root) = newNode;
        return;
    }
    if ((*root)->item > data) {
        insert(&(*root)->left, data);
    }
    else {
        insert(&(*root)->right, data);
    }
}

/*---------- function to perform preorder traversal ------------*/
void preorderTraversal(struct Node *root) {
    if (root == NULL)
        return;
    printf("%d -> ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

/*--------- function to perform postorder traversal ------------*/
void postorderTraversal(struct Node *root){
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->item);
}

int main() {
    return;
}