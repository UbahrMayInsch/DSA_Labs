#include "defs.h"



//helper functions

int comparator1(const void *a, const void *b) {
    DataPtr da = (DataPtr) a;
    DataPtr db = (DataPtr) b;
    return (da->a - db->a);//asc
    // return (db->a - da->a);//desc
}

// function to print the list
void printList(DataPtr list, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d, %f, %s\n", list[i].a, list[i].b, list[i].c);
    }
}

void heapify(Data a[],int i,int n)
{
	int w = i*2 + 1; 
	while( w < n ) 
    {
		if ( w+1 < n )
			if ( a[w+1].a > a[w].a ) 
                w++;
		if ( a[i].a >= a[w].a ) 
            return;
		Data temp=a[i];
        a[i]=a[w];
        a[w]=temp;		
		i = w; 
		w =i*2+1; 
	}
}

// Sorting Algorithms

void InsertionSort(Data a[],int n)
{   Data curr;
    int j;
    for(int i=0;i<n;i++){
        curr=*(a+i);
        for(j=i;j>0 && curr.a < a[j-1].a;j--){
            Data temp=*(a+j);
            *(a+j)=*(a+j-1);
            *(a+j-1)=temp;
        }
        *(a+j)=curr;
    }
    return;
}

void BubbleSort(Data a[],int n)
{
    // Your code goes here
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].a > a[j+1].a){
                Data temp=*(a+j);
                *(a+j)=*(a+j+1);
                *(a+j+1)=temp;
            }
        }
    }
    return;
}

void SelectionSort(Data a[],int n)
{
    // Your code goes here
    int sorted=0;
    int min;
    while(sorted < n){
        for(int i=sorted;i<n;i++){
            min=sorted;
            if(a[i].a < a[min].a){
                min=i;
            }
        }
        *(a+min)=*(a+sorted);
        sorted++;
    }
    return;
}


void MergeSort(Data a[],int l,int r)
{
    // Your code goes here
    
    if(r <= l){
        return;
    }

    else{
        int mid=l+ (r-l)/2;
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

void HeapSort(Data a[], int n)
{
    // Your code goes here
    int lastparent=n - 1;
    for(int i=lastparent; i > -1;i/=2){
        heapify(a, i, n);
    }
    return;
}






