#include <stdio.h>
#include <stdlib.h>

typedef int elemtype;

typedef struct hash_data{
    int max_elems;
    elemtype* aIndex;    
}hash_data;

typedef hash_data* HashTable;

int getkey(int n, int mod){
    return n % mod;
};

HashTable init_hash(long long int capacity){
    HashTable H= (HashTable)malloc(sizeof(hash_data));
    H->max_elems=capacity;
    H->aIndex= (elemtype*)malloc(sizeof(elemtype)*capacity);
    for(int i=0;i<capacity;i++){
        H->aIndex[i]=0;
    }
    return H;
}

int countCol(HashTable H, int* rand){
    for(int i=0;i<1000;i++){
        int key=getkey(rand[i], H->max_elems);
        H->aIndex[key]+=1;
    }

    int col=0;
    for(int i=0;i<H->max_elems;i++){
        if(H->aIndex[i]>1){
            col+=H->aIndex[i]-1;
        }
    }
    return col;
}

int main(){
    int colarr[100];
    for(int i=0;i<100;i++){
        colarr[i]=0;
    }
    for(int j=1;j<101;j++){
    HashTable H=init_hash(j);
    int randarr[1000];
        for(int i=0;i<1000;i++){
            randarr[i]=rand()%1000;
            randarr[i]=randarr[i]*randarr[i];
        }
        colarr[j]=countCol(H, randarr);
    }

    for(int i=1;i<101;i++){
        printf("%d \n", colarr[i]);
    }
    return 0;
}
