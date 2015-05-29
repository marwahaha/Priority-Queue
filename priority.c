//  priority.c
//  VF, 05/28/15
//  Created by Jeffrey

#include "heapFunctions.c"
#include "priorityFunctions.c"

int main(int argc, char *argv[]) {
	
    int size = argc - 2;
  	
  	// Initializes the heap
  	Heap *toSort;
  	toSort = malloc(sizeof(Heap) + size*sizeof(int));
  	toSort->size = size;
    toSort->length = size;
  	toSort->arr = (int*)malloc(sizeof(int) * size);
  	
    if (argc <= 2) {
        printf("You are missing arguments.\n");
    }
    
    else {
    	
    	// Adds keys to the heap
        for (int i = 2; i < argc; i++) {
            toSort->arr[i-2] = atoi(argv[i]);
        }
                
        // Sorts the heap or creates a priority queue
        switch (tolower(argv[1][0])) {
            case 'h':
                heap_sort(toSort);
                print_heap(toSort);
                free(toSort);
                break;
            case 'p':
            	build_max_heap(toSort);
                preform_priority(toSort);
                break;
            default:
                break;
        }
    }

    return 0;
}
