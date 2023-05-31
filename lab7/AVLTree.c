#include "AVLTree.h"


ptrNode MakeNode(elemType x){
    node* new=(node*)malloc(sizeof(node));
    new->val=x;
    new->L=NULL;
    new->R=NULL;
    new->BF=0;

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
        return 1 + max(height(T->L), height(T->R));
    }
}

Tree Insert(Tree T, elemType x){
    if(T == NULL){
        T=MakeNode(x);
        T->BF=0;
        return T;
    }
    else{
        if(x > T->val){
            T=Insert(T->R, x);
            // T->BF-=1;
            if((T->BF == -2) && (T->L->val > x)){
                SingleRotateWithRight(T);
            }
            else if((T->BF == -2) && (T->L->val < x)){
                DoubleRotateWithRight(T);
            }
        }
        else if(x < T->val){
            T=Insert(T->L, x);
            // T->BF+=1;
            if((T->BF == 2) && (T->L->val > x)){
                SingleRotateWithLeft(T);
            }
            else if((T->BF == 2) && (T->L->val < x)){
                DoubleRotateWithLeft(T);
                
            }
        }
        T->BF=height(T->R)-height(T->L);
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

int main(){
    Tree T=NULL;
    Insert(T, 1);

}

