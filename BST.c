// ->15,10,20,25,8,12.17,19
// BST(Binary Search Tree)
// BST:->                15
//                     /    \
//                    10     20
//                   / \     /  \
//                  8   12  17   25
//                           \
//                            29

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}node;

node *createNode(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
node *insertNode(node *root,int data){
    if(root==NULL){
        return createNode(data);
    }else if(data<root->data){
        root->left=insertNode(root->left,data);
    }else if(data>root->data){
        root->right=insertNode(root->right,data);
    }
    return root;
}
void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void preorder(node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }

}
void postorder(node *root){
    if(root!=NULL){
        postorder(root->left);
        printf("%d\t",root->data);
        postorder(root->right);
    }
}
int main(){
    node *root=NULL;
    root=insertNode(root,15);
    root=insertNode(root,10);   
    root=insertNode(root,20);   
    root=insertNode(root,25);   
    root=insertNode(root,8);   
    root=insertNode(root,12);   
    root=insertNode(root,17);
    root=insertNode(root,19);

    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}
