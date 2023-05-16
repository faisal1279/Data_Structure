#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *head;

void traversal(){
    node *p=head;
    while(p!=NULL){
        printf("%d\t",p->data);
    p=p->next;
    }
    printf("\n");
}
// delete at first
void deleteAtFirst(){
    node *data=head;
    head=head->next;
    free(data);
}
// delete at last
void deleteAtlast(){
    node *data=head;
    node *delete=data->next;
    while(delete->next!=NULL){
        data=data->next;
        delete=delete->next;
    }
    data->next=NULL;
    free(delete);

}
// delete any position
void deleteAnyPosition(){
    int n;
    printf("Delete position : ");
    scanf("%d",&n);
    node *data=head;
    if(n==1){
        head=head->next;
        free(data);
    }else{
        node *delete=data->next;
        int i=1;
        while(i<n-1){
            data=data->next;
            delete=delete->next;
            i++;
        }
        data->next=delete->next;
        free(delete);
    }
}
// Data delete
void deleteData(){
    int n;
    printf("Which data you want to Delete ? : ");
    scanf("%d",&n);
    node *current=head;
    if(current->data==n){
        head=head->next;
        free(current);
    }else{
        node *delete=current->next;
        while(delete!=NULL && delete->data!=n){
            current=current->next;
            delete=delete->next;
        }
        if(delete->data==n){
            current->next=delete->next;
            free(delete);
        }else{
            printf("Delete is not found!");
        }
    }
}
int main(){
    node *newnode,*temp;
    head=NULL;
    int n,i=1;
    scanf("%d",&n);
    while(i<=n){
        newnode=(node*)malloc(sizeof(node));
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL){
            head=temp=newnode;
        }else{
            temp->next=newnode;
            temp=newnode;
        }
        i++;
    }
    traversal();
    deleteAtFirst();
    traversal();

    
    deleteAtlast();
    traversal();

    deleteAnyPosition();
    traversal();

    deleteData();
    traversal();

    return 0;
}