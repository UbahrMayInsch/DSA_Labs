#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

typedef struct stack_data{
    int num_elems;
    node* top;
}stack_data;

typedef stack_data* Stack;

Stack Init_Stack(){
    Stack S= (Stack) malloc(sizeof(stack_data));
    S->num_elems=0;
    S->top=NULL;
}

int Pop(Stack S){
    node* temp=S->top;
    int ans=temp->val;
    S->top=S->top->next;
    free(temp);
    return ans;
}

void Push(Stack S, int x){
    node* new= (node*) malloc(sizeof(node));
    new->next=S->top;
    new->val=x;
    S->top=new;
    return;
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int nsearr[n];
    Stack S=Init_Stack();
    for(int i=0;i<n;i++){
        if(S->num_elems == 0){
            nsearr[n-1-i]=-1;
        }
        else if{
            
        }
    }


}