#include <stdio.h>

typedef struct Data{
    int a;
}Data;

void MergeSort(Data a[],int l,int r)
{
    // Your code goes here
    
    if(r <= l){
        return;
    }

    else{
        int mid=l+(r-l)/2;
        MergeSort(a, l, mid);
        MergeSort(a, mid+1, r);
        int index=0;
        int rmerge=0;
        int lmerge=0;
        while(index < r-l){
            if(rmerge == r-mid){
                *(a+index)=*(a+lmerge);
                index++;
                lmerge++;
            }
            else if(lmerge == mid-l){
                *(a+index)=*(a+rmerge);
                index++;
                lmerge++;
            }
            else{
                if(a[l+lmerge].a <= a[mid+rmerge].a){
                    *(a+index)=*(a+lmerge);
                    index++;
                    lmerge++;
                }
                else if(a[l+lmerge].a > a[mid+rmerge].a){
                        Data temp=*(a+mid+rmerge);
                        int indcopy=index;
                        while(indcopy < mid+rmerge){
                            *(a+indcopy)=*(a+indcopy+1);
                            indcopy++;
                        }
                        *(a+index)=temp;
                        index++;
                        rmerge++;
                }
            }
        }
    }
}

int main(){
    Data a[]={3, 2, 6, 4, 5, 1};
    MergeSort(a, 0, 5);
    for(int i=0;i<6;i++){
        printf("%d ", a[i].a);
    }
}