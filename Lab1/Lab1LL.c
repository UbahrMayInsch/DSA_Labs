#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int element;
    struct node* next;
}node;

typedef node* List;

// void reverse(List L){
//     node* temp1=(node*)malloc(sizeof(node));
//     node* temp2=(node*)malloc(sizeof(node));
//     temp=List;
//     while(temp != NULL){

//     }

// }

List append(List L, int data){
    node* k=(node*)malloc(sizeof(node));
    node* iterator=(node*)malloc(sizeof(node));
    iterator=L;
    while(iterator->next!=NULL){
        iterator=iterator->next;
    }
    iterator->next=k;
    k->next=NULL;
    k->element=data;
    return L;
}

List add(List L1, List L2){
    //Reverse(L1);
    //Reverse(L2);
    node* ans=(node*)malloc(sizeof(node));
    ans->next=NULL;
    int carry=0;
    int digit=((L1->element)+(L2->element)+carry) % 10;
    ans->element=digit;
    while((carry > 0) || (L1->next!=NULL) && (L2->next != NULL) ){
        digit=(((L1->next)->element)+((L2->next)->element)+carry) % 10;
        append(ans,digit);
        carry=((L1->element)+(L2->element)+carry) / 10;
        L1=L1->next;
        L2=L2->next;
    }
    //Reverse(ans);
    return ans;
}

List SparseAdd(){

}

void printList(List L){
    node* k=(node*)malloc(sizeof(node));
    k=L;
    while(k !=NULL){
        printf("%d ", k->element);
        k=k->next;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int x=0;
    node* L1=(node*)malloc(sizeof(node));
    node* L2=(node*)malloc(sizeof(node));

    L1->next=NULL;
    scanf("%d", &x);
    L1->element=x;
    for(int i=0;i<n-1;i++){
        scanf("%d", &x);
        L1=append(L1, x);
    }

    L2->next=NULL;
    scanf("%d", &x);
    L2->element=x;
    for(int i=0;i<n-1;i++){
        scanf("%d", &x);
        append(L2, x);
    }


    node* ans;
    ans=add(L1,L2);
    printList(ans);
}   