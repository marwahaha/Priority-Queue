//  heapFunctions.h
//  VF, 05/28/15
//  Created by Jeffrey

// Includes the neccessary header files
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

// Defines values for true and false
#define TRUE 1
#define FALSE 0

// Creates a structure for the heap
// Stores ints to track its size, length, and memory usage
// Has integer array for keys and character array for elements
typedef struct heap {
  int size;
  int length;
  int *arr;
  char *data;
  int buffer;
} Heap;


// Takes an index and returns the index of its parent
int parent(i) {
	return i/2;
}

// Takes an index and returns the index of its left child
int left(i) {
	return 2*i;
}

// Takes an index and returns the index of its right child
int right(i) {
	return 2*i+1;
}

// Swaps two values within an integer array
// Takes the index of the first value and the index of the second
void int_swap(int *index1, int *index2) {  
    int temp;
    temp = *index1;
    *index1 = *index2;
    *index2 = temp;
}

// Ensures the maximum heap property is kept
// Takes the heap and the index to check against
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
        int_swap(&my_heap->arr[i],&my_heap->arr[largest]);
        max_heapify(my_heap,largest);
    }
}

// Creates the maximum heap
// Takes only the heap
void build_max_heap(Heap *my_heap)
{
    my_heap->size = my_heap->length;
    int i;
    for(i = my_heap->length/2;i>=0;i--)
    {
        max_heapify(my_heap, i);
    }
}

// Sorts the heap in ascending order
// Takes only the heap
void heap_sort(Heap *my_heap)
 {
   int i;
   
   build_max_heap(my_heap);
   
    for(i= my_heap->length-1;i>=1;i--)
    {
        int_swap(&my_heap->arr[0],&my_heap->arr[i]);
        my_heap->size =  my_heap->size - 1;
        max_heapify(my_heap,0);
    }
 }

// Checks if two arrays are identical
// Takes two arrays and their size
int compareArrays(int arr1[], int arr2[], int n) {
    
    int i;
    
    for (i=0; i < n; i++) {
        if (arr1[i] != arr2[i]) {
            return FALSE;
        }
    }
    return TRUE;
}

// Prints the array for viewing
// Takes only the heap
void print_heap(Heap *maxHeap) {
    
    for(int i = 0; i < maxHeap->length; i++) {
   	 	printf("%d ", maxHeap->arr[i]);
  	}  
  	
  	printf("\n");
  
}