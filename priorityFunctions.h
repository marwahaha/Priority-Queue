//  priorityFunctions.h
//  V1, 05/14/15
//  Created by Jeffrey

// Includes the neccessary header files
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

struct heap
{
    int size;
    int arr[];
    
};

int parent(i)
{
    return i/2;
}
int left(i)
{
    return (2*i)+1;
}
int right(i)
{
    return (2*i)+2;
}

void swap(int *index1, int *index2) {
    
    int temp;
    
    temp = *index1;
    *index1 = *index2;
    *index2 = temp;
    
}

void maxHeapify(struct heap* maxHeap, int i)
{
    
    int l = left(i);
    int r = right(i);
    int largest = i;
    
    if (l <= maxHeap->size && maxHeap->arr[l] > maxHeap->arr[largest])
    {
        largest = l;
    }
    if (r <= maxHeap->size && maxHeap->arr[r] > maxHeap->arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(&maxHeap->arr[largest], &maxHeap->arr[i]);
        maxHeapify(maxHeap, largest);
    }
    
}

struct heap* buildMaxHeap(int arr[], int size)
{
    struct heap* maxHeap =(struct heap*) malloc(sizeof(struct heap));
    
    for (int i = (maxHeap->size - 2) / 2; i >= 0; --i)
    {
        maxHeapify(maxHeap, i);
    }
    
    return maxHeap;
    
}

void heapSort(int arr[], int size)
{
    struct heap* maxHeap = buildMaxHeap(arr, size);
    while (maxHeap->size > 1)
    {
        swap(&maxHeap->arr[0], &maxHeap->arr[maxHeap->size - 1]);
        --maxHeap->size;
        maxHeapify(maxHeap, 0);
    }
}

int heapMaximum(int arr[], int size)
{
    struct heap* maxHeap = buildMaxHeap(arr, size);
    return maxHeap->arr[0];
}

int heapExtractMax(int arr[], int size)
{
    struct heap* maxHeap = buildMaxHeap(arr, size);
    
    if (maxHeap->size < 1)
    {
        exit(1);
    }
    
    int max = maxHeap->arr[0];
    
    maxHeap->arr[0] = arr[maxHeap->size];
    
    maxHeap->size = maxHeap->size - 1;
    
    maxHeapify(maxHeap, 0);
    
    return max;
    
}

void heapIncreaseKey(int arr[], int size, int i, int key)
{
    struct heap* maxHeap = buildMaxHeap(arr, size);
    
    if (key < maxHeap->arr[i])
    {
        exit(1);
    }
    
    maxHeap->arr[i] = key;
    
    while (i > 0 && maxHeap->arr[parent(i)] < maxHeap->arr[i]) {
        swap(&maxHeap->arr[i], &maxHeap->arr[parent(i)]);
        i = parent(i);
    }
    
}

void maxHeapInsert(int arr[], int size, int key)
{
    struct heap* maxHeap = buildMaxHeap(arr, size);
    
    maxHeap->size = maxHeap->size + 1;
    maxHeap->arr[maxHeap->size - 1] = -INT_MAX;
    heapIncreaseKey(maxHeap->arr, maxHeap->size, maxHeap->size, key);
}


int compareArrays(int arr1[], int arr2[], int n) {
    
    int i;
    
    for (i=0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

void printArray(int arr[], int n) {
        
    printf("%d ", heapMaximum(arr, n));
    
}