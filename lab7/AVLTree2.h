#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int elemType;

typedef struct node{
    elemType val;
    int height;
    struct node* L;
    struct node* R;
}node;

typedef node* Tree;
typedef node* ptrNode;

ptrNode MakeNode(elemType x);
int max(int a, int b);
int height(ptrNode T);
Tree Insert(Tree T, elemType x);
Tree SingleRotateWithRight(Tree T);
Tree SingleRotateWithLeft(Tree T);
Tree DoubleRotateWithRight(Tree T);
Tree DoubleRotateWithLeft(Tree T);
