#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int info;
    struct Node *left;
    struct Node *right;
}NODE;

NODE *createNode(int data)
{
    NODE *newnode = malloc(sizeof(struct Node));
    newnode -> info = data;
    newnode -> left = NULL;
    newnode -> right = NULL;
    
    return newnode;
}
NODE *insert(NODE *root, int data)
{
    if(root == NULL)
        return createNode(data);
    if(data < root -> info)
        root -> left = insert(root -> left, data);
    else
        root -> right = insert(root -> right, data);
    return root;
}
void traversal(NODE *root){
    if(root == NULL)
        return ;
    traversal(root->left);
    printf("%d ",root->info);
    traversal(root->right);
}
int main(){
    NODE *root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 9);
    traversal(root);
}
