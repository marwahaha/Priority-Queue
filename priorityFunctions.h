//  priorityFunctions.h
//  V2, 05/21/15
//  Created by Jeffrey

// Includes the neccessary header files
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>

int heap_maximum(Heap *my_heap) {
	return my_heap->arr[0];
}
int heap_extract_max(Heap *my_heap) {
	if (my_heap->size < 1)
		exit(0);
	int max = my_heap->arr[0];
	my_heap->size = my_heap->size - 1;
	my_heap->length = my_heap->length - 1;
	my_heap->arr[0] = my_heap->arr[my_heap->length];
	max_heapify(my_heap, 0);
	return max;
}

void heap_increase_key(Heap *my_heap, int i, int key) {	
	if (key < my_heap->arr[i])
		exit(0);
	my_heap->arr[i] = key;
	while (i > 0 && my_heap->arr[parent(i)] < my_heap->arr[i]) {
		swap(&my_heap->arr[i], &my_heap->arr[parent(i)]);
		i = parent(i);
	}
}

void max_heap_insert(Heap *my_heap, int key) {
	my_heap->size = my_heap->size + 1;
	my_heap = realloc(my_heap, my_heap->size*sizeof(int));
	my_heap->arr[my_heap->size-1] = -INT_MAX;
	heap_increase_key(my_heap, my_heap->size, key);
}

void preformPriority(Heap *my_heap) {
	int loc, key;
	char answer = 0;                   
	printf("Priority queue function:");
  	scanf("%c", &answer);
  	switch (answer) {
            case 'm':
            	printf("Max: %d\n", heap_maximum(my_heap));
            	break;
            case 'e':
            	printf("Max: %d\n", heap_extract_max(my_heap));
            	break;
            case '+':
            	printf("Enter location:");
  				scanf("%d", &loc);
  				printf("Enter key:");
  				scanf("%d", &key);
            	heap_increase_key(my_heap, loc, key);
            	break;
            case 'i':
            	printf("Enter key:");
  				scanf("%d", &key);
            	max_heap_insert(my_heap, key);
            default:
            	break;
    }
}