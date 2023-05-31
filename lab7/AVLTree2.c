#include "AVLTree2.h"


ptrNode MakeNode(elemType x){
    node* new=(node*)malloc(sizeof(node));
    new->val=x;
    new->L=NULL;
    new->R=NULL;
    new->height=0;
    return new;
}

int max(int a, int b){
    return (a > b)? a : b;
}

int height(ptrNode T){
    if(T == NULL){
        return -1;
    }
    else{
        return T->height;
    }
}

Tree Insert(Tree T, elemType x){
    if(T == NULL){
        T=MakeNode(x);
        return T;
    }
    else{
        if(x > T->val){
            T->R=Insert(T->R, x);
            if((height(T->R)-height(T->L)== 2) && (T->R->val < x)){
                T=SingleRotateWithRight(T);
            }
            else if((height(T->R)-height(T->L) == 2) && (T->R->val > x)){
                T=DoubleRotateWithRight(T);
            }
        }
        else if(x < T->val){
            T->L=Insert(T->L, x);
            // T->BF+=1;
            if((height(T->R)-height(T->L) == -2) && (T->L->val > x)){
                T=SingleRotateWithLeft(T);
            }
            else if((height(T->R)-height(T->L) == -2) && (T->L->val < x)){
                T=DoubleRotateWithLeft(T);
                
            }
        }
        T->height=max(height(T->R), height(T->L))+1;
    }
}

//RR Imbalance
Tree SingleRotateWithRight(Tree T){
    ptrNode k1=T;
    ptrNode k2=T->R;
    k1->R=k2->L;
    k2->L=k1;
    return k2;
}

//LL Imbalance
Tree SingleRotateWithLeft(Tree T){
    ptrNode k1=T;
    ptrNode k2=T->L;
    k1->L=k2->R;
    k2->R=k1;
    return k2;
}

//RL Imbalance
Tree DoubleRotateWithRight(Tree T){
    ptrNode k1=T;
    ptrNode k2=T->R;
    SingleRotateWithLeft(k2);
    SingleRotateWithRight(k1);
    return k2;
}

//LR Imbalance
Tree DoubleRotateWithLeft(Tree T){
    ptrNode k1=T;
    ptrNode k2=T->L;
    SingleRotateWithRight(k2);
    SingleRotateWithLeft(k1);
    return k2;
}

void Preorder(Tree T){
    if(T== NULL){
        return;
    }
    else{
        Preorder(T->L);
        Preorder(T->R);
        printf("%d ", T->val);
    }
}

int main(){
    Tree T=NULL;
    int t;
    scanf("%d", &t);
    while(t--){
        int x;
        scanf("%d", &x);
        T=Insert(T, x);
        Preorder(T);
        printf("\n");
    }
}

