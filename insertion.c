#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
    struct Node *head;

void traversal(){
    struct Node *ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
}

// Insert At First
void insertAtFirst(int data){
    struct Node *p=(struct Node*)malloc(sizeof(struct Node));
    p->data=data;
    p->next=NULL;
    p->next=head;
    head=p;
}

// Insert At Any position
void insertAnyPosition(int data){
    int x;
    printf("Insert at position");
    scanf("%d",&x);
    int count=1;
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    newnode->next=NULL;
    newnode->data=data;
    if(x==1){
        newnode->next=head;
        head=newnode;
    }else{
        struct Node *current=head;
        while(count<x-1){
            current=current->next;
            count++;
        }
        newnode->next=current->next;
        current->next=newnode;
    }
    
}
// insertAtLast
void insertAtLast(int data){
    struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
    struct Node *p=head;
    newnode->data=data;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=newnode;
    newnode->next=NULL;
}

int main()
{   
    int n,x;
    struct Node *newNode,*temp;
    head=NULL;
    int i=0;
    scanf("%d",&n);
    while(i<n){
    newNode=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter Data :");
    scanf("%d",&newNode->data);
    newNode->next=NULL;

    if(head==NULL){
        head=temp=newNode;
    }else{
        temp->next=newNode;
        temp=newNode;
    }
    i++;
    }

    traversal();

    insertAtFirst(45);
    insertAnyPosition(100);
    insertAtLast(999);
    printf("\n");
    traversal();

    insertAtFirst(45);
    printf("\n");
    traversal();
    return 0;
}