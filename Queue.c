#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;
    node *top=NULL;

void traversal(){
    node *current=top;
    while(current!=NULL){
        printf("%d\t",current->data);
        current=current->next;
    }
    printf("\n");
}
void enqueue(int data){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->next=NULL;
    newnode->data=data;
    if(top==NULL){
        top=newnode;
    }else{
        node *current=top;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newnode;
    }
}
void dequeue(){
    node *deleteNode;
    if(top==NULL){
        printf("Queue is Empty\n");
        return ;
    }else{
        deleteNode=top;
        top=top->next;
        free(deleteNode);
    }
}
int main(){
    int n,x;
    printf("How many data you insert ? ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        enqueue(x);
    }
    traversal();
    int y;
    printf("How many data you delete ? :");
    scanf("%d",&y);
    for(int i=1;i<=y;i++){
        dequeue();
    }
    traversal();
    return 0;
}