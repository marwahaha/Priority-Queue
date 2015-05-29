//  priorityTest.c
//  VF, 05/28/15
//  Created by Jeffrey

#include "heapFunctions.c"
#include "priorityFunctions.c"

int main() {
    
    // Defines the example arrays to sort
    int testSort[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int testSortRep[20] = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5, 5, 6, 4, 7, 3, 8, 2, 9, 1, 10};
    int testSortOdd[7] = {7, 9, 1, 5, 2, 3, 8};
    int testSortSingle[1] = {1};
    int testSortNone[5] = {};
    
    // Defines what the arrays should look like when sorted
    int sorted[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sortedRep[20] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10};
    int sortedOdd[7] = {1, 2, 3, 5, 7, 8, 9};
    int sortedSingle[1] = {1};
    int sortedNone[5] = {};
    
    Heap *toSort;
    
    // Creates an array of all the unsorted arrays
    int *arraysToSort[5] = {testSort, testSortRep, testSortOdd, testSortSingle, testSortNone};
    // Creates an array of all the sorted arrays
    int *arraysToMatch[5] = {sorted, sortedRep, sortedOdd, sortedSingle, sortedNone};
    // Stores the size of each array
    int sizeToSort[5] = {10, 20, 7, 1, 5};
    
    // For each array to sort, see that the function 'heap_sort' sorts it correctly
    for (int i=0; i<5; i++) {
        
        int size = sizeToSort[i];
        
        //initialize the heap
  		toSort = malloc(sizeof(Heap) + size*sizeof(int));
  		toSort->size = size;
   		toSort->length = size;
  		toSort->arr = (int*)malloc(sizeof(int) * size);
   		
   		//add the keys to the heap
   		for (int j = 0; j < size; j++) {
            toSort->arr[j] = arraysToSort[i][j];
        }
        
        heap_sort(toSort);
        assert(compareArrays(toSort->arr, arraysToMatch[i], sizeToSort[i]) == TRUE);
        free(toSort);
        
    }

	int size = 10;
    
    //initialize the heap
	toSort = malloc(sizeof(Heap) + size*sizeof(int));
	toSort->size = size;
	toSort->length = size;
	toSort->arr = (int*)malloc(sizeof(int) * size);
	toSort->buffer = 0;
	
	//add elements to the heap
	populate_data(toSort); 
	
	//add keys to the heap
	for (int k = 0; k < size; k++) {
		toSort->arr[k] = testSort[k];
	}
	
	Tuple result;

	//see that the max is 10
	result = heap_maximum(toSort);
	assert(10 == result.key);
	
	//see that the max is indeed 10 and was removed from the heap
	result = heap_extract_max(toSort);
	assert(10 == result.key);
	int noMax[9] = {9, 8, 6, 7, 2, 5, 4, 3, 1};
	assert(compareArrays(toSort->arr, noMax, size-1) == TRUE);
    
    //see that 10 is correctly re-added to the heap
    max_heap_insert(toSort, 10);
    int insert[10] = {10, 9, 8, 7, 6, 5, 4, 3, 1, 2};
    assert(compareArrays(toSort->arr, insert, size-1) == TRUE);
    
    //see that the priority of 1 is changed correctly
    heap_increase_key(toSort, 8, 11);
    int priority[10] = {11, 10, 9, 7, 8, 5, 4, 3, 6, 2};
    assert(compareArrays(toSort->arr, priority, size-1) == TRUE);
    
    //see that the priority of 8 is changed correctly
    heap_increase_key(toSort, 4, 10);
    int priority2[10] = {11, 10, 10, 7, 9, 5, 4, 3, 6, 2};
    assert(compareArrays(toSort->arr, priority2, size-1) == TRUE);

    free(toSort);
    
    // If no tests fail and abort the program, then all tests have passed
    printf("All tests passed.\n");
    
    return 0;
}
