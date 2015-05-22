//  priority.c
//  V2, 05/21/15
//  Created by Jeffrey

#include "heapFunctions.h"
#include "priorityFunctions.h"

int main(int argc, char *argv[]) {
	
	Heap *toSort;
    int size = argc - 2;
  	
  	toSort = malloc(sizeof(Heap) + size*sizeof(int));
    toSort->size = size;
    toSort->length = size;
  
    int i;
    
    if (argc <= 2) {
        printf("You are missing arguments.\n");
    }
    
    else {

        for (i = 2; i < argc; i++) {
            toSort->arr[i-2] = atoi(argv[i]);
        }
        
        switch (tolower(argv[1][0])) {
            case 'h':
                heapSort(toSort);
                printArray(toSort);
                break;
            case 'p':
            	build_max_heap(toSort);
                preformPriority(toSort);
                printArray(toSort);
                break;
            default:
                break;
        }
        
    }
    
    printf("\n");
    free(toSort);
    
    return 0;
}
