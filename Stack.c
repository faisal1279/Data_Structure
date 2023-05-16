#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int data;
    struct Stack *next;
}stack;

stack *top=NULL;

void traversal(){
    stack *ptr=top;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

void push(int data){
    stack *newstack=(stack*)malloc(sizeof(stack));
	newstack->data=data;
	newstack->next=NULL;
	if(top==NULL){
		top=newstack;
	}
	else{
		stack *current=top;
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=newstack;
	}
}

void pop(){
    if(top==NULL){
        printf("Stack is empty\n");
        return; 
    }else{
        stack *current=top;
        stack *delete=current->next;
        while(delete->next!=NULL){
            current=current->next;
            delete=delete->next;
        }
        current->next=delete->next;
        free(delete);
    }
}

int main(){
    int n,x;
    printf("How many data you insert ? : ");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        push(x);
    }
    traversal();
    printf("How many data you delete ? = ");
    int y;
    scanf("%d",&y);
    for(int i=1;i<=y;i++){
        pop();
    }
    traversal();
    return 0;
}