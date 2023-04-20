#include <stdio.h>
#include <stdlib.h>


typedef struct stack_data{
    int num_elems;
    struct node* Top;
}stack_data;

typedef stack_data* stack;

typedef struct node{
    int data;
    struct node* next;
}node;

void push(stack S, int num){
    node* list=(node*)malloc(sizeof(node));
    list->data=num;
    list->next=S->Top;
    S->Top=list;
    S->num_elems++;
    return;
}

int pop(stack S){
    node* temp=S->Top;
    int num=S->Top->data;
    S->Top=S->Top->next;
    free(temp);
    return num;
}

node* peek(stack S){
    node* temp=S->Top;
    return temp;
}

stack init_stack(){
    stack S=(stack)malloc(sizeof(stack_data));
    S->Top=NULL;
    S->num_elems=0;
    return S;
}

int main()
{   
    int n;
    scanf("%d", &n);
    int arr[n];
    stack S=init_stack();
    
    for(int i=0;i<n;i++){
        int num;
        scanf("%d", &arr[i]);
    }
    
    int nsnarr[n];
    for(int i=0;i<n;i++){
        if(S->num_elems == 0){
            nsnarr[i]=-1;
        }

        else{
            while((arr[i] < S->Top->data) && (S->num_elems != 0)){
                pop(S);
            }

            if(S->num_elems == 0){
                nsnarr[i]=-1;
            }
            else if(S->num_elems != 0){
                nsnarr[i]=S->Top->data;
            }
        }
        
        push(S, arr[i]);
    }

    for(int i=0;i<n;i++){
        printf("%d ", nsnarr[i]);
    }

    return 0;
}
