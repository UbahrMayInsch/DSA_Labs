#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define STRLEN 20

typedef struct Data {
    int a;
    float b;
    char c[STRLEN];
} Data;
typedef Data * DataPtr;

int comparator1(const void *a, const void *b);
void printList(DataPtr list, int size);
void heapify(Data a[],int i,int n);

//  Sorting algorithms(To be implemented)
void SelectionSort(Data a[],int n);
void InsertionSort(Data a[],int n);
void BubbleSort(Data a[],int n);
void MergeSort(Data a[],int l,int r);
void HeapSort(Data a[], int n);



#endif