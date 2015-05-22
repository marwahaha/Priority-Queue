//  heapFunctions.h
//  V2, 05/21/15
//  Created by Jeffrey

// Includes the neccessary header files
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

#define TRUE 1
#define FALSE 0

int parent(i) {
	return i/2;
}

int left(i) {
	return 2*i;
}

int right(i) {
	return 2*i+1;
}

typedef struct heap {
  int size;
  int length;
  int arr[];
} Heap;

void swap(int *index1, int *index2) {
    
    int temp;
    
    temp = *index1;
    *index1 = *index2;
    *index2 = temp;
    
}
 
void max_heapify(Heap *my_heap,int i)
{

    int l = left(i);
    
    int r = right(i);
    
    int largest;
    
    if(l<my_heap->size && my_heap->arr[l]>my_heap->arr[i])
        largest = l;
    else
        largest = i;
    if(r<my_heap->size && my_heap->arr[r]>my_heap->arr[largest])
        largest = r;

    if(largest != i)
    {
        swap(&my_heap->arr[i],&my_heap->arr[largest]);
        max_heapify(my_heap,largest);
    }
}
     
void build_max_heap(Heap *my_heap)
{
    my_heap->size = my_heap->length;
    int i;
    for(i = my_heap->length/2;i>=0;i--)
    {
        max_heapify(my_heap, i);
    }
}

void heapSort(Heap *my_heap)
 {
   int i;
   
   build_max_heap(my_heap);
   
    for(i= my_heap->length-1;i>=1;i--)
    {
        swap(&my_heap->arr[0],&my_heap->arr[i]);
        my_heap->size =  my_heap->size - 1;
        max_heapify(my_heap,0);
    }
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

void printArray(Heap *maxHeap) {
    
    for(int i = 0; i < maxHeap->length; i++) {
   	 	printf("%d ", maxHeap->arr[i]);
  	}    
}