    //         15
    //        /   \
    //      20     25
    //     / \     / \
    //   27  28   19  21
    // InOrder = 27,20,28,15,19,25,21
    // PreOrder = 15,20,27,28,25,19,21
    // PostOrder = 27 20 28 15 19 25 21

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

void add_left_child(node *root,node *child){
    root->left=child;
}
void add_right_child(node *root,node *child){
    root->right=child;
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
    node *fifteen=createNode(15);
    node *tw=createNode(20);   
    node *twSeven=createNode(27);   
    node *twEight=createNode(28);   
    node *twFive=createNode(25);   
    node *nineteen=createNode(19);   
    node *twOne=createNode(21);

    add_left_child(fifteen,tw);
    add_left_child(tw,twSeven);
    add_right_child(tw,twEight);

    add_right_child(fifteen,twFive);
    add_left_child(twFive,nineteen);
    add_right_child(twFive,twOne); 


    inorder(fifteen);
    printf("\n");
    preorder(fifteen);
    printf("\n");
    postorder(fifteen);
    printf("\n");

    return 0;
}