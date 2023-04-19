#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define INVALID -5555

typedef char* str;
typedef int len;

typedef struct node{
    str key;
    len n;
    struct node* next;
}node;

typedef node* elemtype;

typedef struct hash_data{
    long long int max_elems;
    elemtype* aIndex;    
}hash_data;

typedef long long int indHT;

typedef hash_data* HashTable;

indHT getkey(str key, len n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(int)str[i];
    }
    sum=sum % 13;
    return sum;
};

HashTable init_hash(long long int capacity){
    HashTable H= (HashTable)malloc(sizeof(hash_data));
    H->max_elems=capacity;
    H->aIndex= (elemtype*)malloc(sizeof(node*)*capacity);
    for(int i=0;i<capacity;i++){
        H->aIndex[i]=(node*)malloc(sizeof(node));
        H->aIndex[i]->key=INVALID;
        H->aIndex[i]->next=NULL;
    }
    return H;
}

elemtype Find(HashTable H, str elem, len n){
    int indHT=getkey(elem, n);
    assert(indHT != -INVALID);
    node* temp=H->aIndex[indHT];

    while((temp != NULL)&&(temp->key != elem)){
        temp=temp->next;
    }
    return temp;
}

elemtype InsertSC(HashTable H, str elem, len n){
    int indHT=getkey(elem, n);
    assert(indHT != -INVALID);
    node* temp=H->aIndex[indHT];

    while((temp->next!= NULL)){
        if(temp->key == elem){
            return NULL;
        }
    }

    node* new=(node*)malloc(sizeof(node));
    temp->next=new;
    new->next=NULL;
    new->key=elem;
    new->len=n;

    return new;
}


int main(){
    HashTable H=init_hash(13);
    str a="asdf";
    InsertSC(H, a, 4);
    printf("%s", Find(H, a ,4)->key);

    return 0;
}