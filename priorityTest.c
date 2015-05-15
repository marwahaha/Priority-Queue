//  priorityTest.c
//  V1, 05/14/15
//  Created by Jeffrey

#include "priorityFunctions.h"

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
    
    // Creates an array of all the unsorted arrays
    int *arraysToSort[5] = {testSort, testSortRep, testSortOdd, testSortSingle, testSortNone};
    // Creates an array of all the sorted arrays
    int *arraysToMatch[5] = {sorted, sortedRep, sortedOdd, sortedSingle, sortedNone};
    // Stores the size of each array
    int sizeToSort[5] = {10, 20, 7, 1, 5};
    
    int i;
    
    // For each array to sort, see that the function 'quicksort' sorts it correctly
    for (i=0; i<5; i++) {
        
        heapSort(arraysToSort[i], sizeToSort[i]);
        assert(compareArrays(arraysToSort[i], arraysToMatch[i], sizeToSort[i]) == TRUE);
        
    }

    
    // If no tests fail and abort the program, then all tests have passed
    printf("All tests passed.\n");
    
    return 0;
}
