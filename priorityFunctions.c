//  priorityFunctions.h
//  VF, 05/28/15
//  Created by Jeffrey

// Includes the neccessary header files
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>


// Creates a structure so both a key and its element can be returned
typedef struct tuple{
	int key;
	char element;
}Tuple;

// Creates the data of random characters to go along with the heap
// Takes only the heap
void populate_data(Heap *my_heap) {
	
	srand (time(NULL));
	
  	my_heap->data = (char*)malloc(sizeof(char) * my_heap->size);

	char randomletter;
	
	for (int i=0; i < my_heap->size; i++) {
		randomletter = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
		my_heap->data[i] = randomletter;
	}
		
}

// Checks if the heap's size exceeds the buffer and will reallocate memory if necessary 
// Only takes the heap
void resize(Heap *my_heap) {
	if(my_heap->size+1 > my_heap->buffer) {
		my_heap->arr = (int*)realloc(my_heap->arr, 100 * sizeof(int));
		my_heap->data = (char*)realloc(my_heap->data, 100 * sizeof(char));
		my_heap->buffer += 100;
	}
}

// Swaps two values within a character array
// Takes the index of the first value and the index of the second
void char_swap(char *index1, char *index2) {
    char temp;
    temp = *index1;
    *index1 = *index2;
    *index2 = temp;
}

// Returns a key and element at a given index
// Takes the heap and the index of the key and element to retrive
Tuple get(Heap *my_heap, int i) {
	Tuple contents = {my_heap->arr[i], my_heap->data[i]};
	return contents;
}

// Assigns a key and element to a given index
// Takes the heap, the index of the key and element, and the index of where they should be assigned
void set(Heap *my_heap, int i1, int i2) {
	my_heap->arr[i1] = my_heap->arr[i2];
	my_heap->data[i1] = my_heap->data[i2];
}

// Swaps both keys and elements
// Takes the heap and the indicies to swap on
void swap(Heap *my_heap, int i1, int i2) {
	int_swap(&my_heap->arr[i1],&my_heap->arr[i2]);
    char_swap(&my_heap->data[i1],&my_heap->data[i2]);
}

// Returns the maximum key and its element
// Only requires the heap as any maximums should be at index 0
Tuple heap_maximum(Heap *my_heap) {
	Tuple max = get(my_heap, 0);
	return max;
}

// Ensures the maximum heap property is kept
// Swaps not only the keys but the data as well
// Takes the heap and the index to check against
void max_heapify_priority(Heap *my_heap,int i)
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
    	swap(my_heap, i, largest);
        max_heapify_priority(my_heap,largest);
    }
}

// Removes and returns the maximum key and its element
// Only requires the heap as any maximums should be at index 0
Tuple heap_extract_max(Heap *my_heap) {
	
	if (my_heap->size < 1){
		printf("There is nothing to extract. \n");
		Tuple empty = {0, 'O'};
		return empty;
	}
	
	Tuple max = get(my_heap, 0);
	my_heap->size = my_heap->size - 1;
	my_heap->length = my_heap->length - 1;
	
	set(my_heap, 0, my_heap->length);
	max_heapify_priority(my_heap, 0);
	
	return max;
}

// Increases the priority of a key 
// Takes the heap, the index of the key to change, and the key's new priority 
void heap_increase_key(Heap *my_heap, int i, int key) {	

	if (key < my_heap->arr[i] || i >= my_heap->size) {
		printf("Key could not be increased, check your input. \n");
		return;
	}
	
	my_heap->arr[i] = key;
	while (i > 0 && my_heap->arr[parent(i)] < my_heap->arr[i]) {
		swap(my_heap, i, parent(i));
		i = parent(i);
	}
	
}


// Inserts a new key into the heap
// Takes the heap and the key to insert
void max_heap_insert(Heap *my_heap, int key) {
	
	my_heap->size = my_heap->size + 1;
	my_heap->length = my_heap->length + 1;
	my_heap->arr[my_heap->length-1] = -INT_MAX;
	my_heap->data[my_heap->length-1] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[rand() % 26];
	heap_increase_key(my_heap, my_heap->size-1, key);
	
}



// Helper function to 'pretty print' the priority queue
// Only takes the heap
void print_priority(Heap *my_heap) {
	
	printf("Key\t|");
	for(int i = 0; i < my_heap->size; i++) {
   	 	printf("%3d|", my_heap->arr[i]);
  	}  
  	printf("\nElement\t|");
	for(int i = 0; i < my_heap->size; i++) {
   	 	printf("%3c|", my_heap->data[i]);
  	}
  	printf("\n");  
  	
}

// Allows the user to interact with the priority queue
// Takes only the heap
void preform_priority(Heap *my_heap) {
	
	int indx, key, input;  
	my_heap->buffer = 0; 
	populate_data(my_heap); 
	Tuple result;
	
	printf("Welcome to the priority que.\n1 - View Maximum\n2 - Extract Maximum\n3 - Increase Key\n4 - Insert Key\n5 - View Que\n6 - Exit Que\n");
	
  	do {
  		  printf("Enter command:");
  		  scanf ("%d", &input);
  	  
  		switch (input) {
            case 1:
            	result = heap_maximum(my_heap);
            	printf("Key\t%d\n", result.key);
            	printf("Element\t%c\n", result.element);
            	break;
            case 2:
            	result = heap_extract_max(my_heap);
            	printf("Key\t%d\n", result.key);
            	printf("Element\t%c\n", result.element);
            	break;
            case 3:
            	printf("Enter index:");
  				scanf("%d", &indx);
  				printf("Enter key:");
  				scanf("%d", &key);
            	heap_increase_key(my_heap, indx, key);
            	print_priority(my_heap);
            	break;
            case 4:
            	printf("Enter key:");
  				scanf("%d", &key);
  				resize(my_heap);
            	max_heap_insert(my_heap, key);
            	print_priority(my_heap);
            	break;
            case 5:
            	print_priority(my_heap);
            	break;
            case 6:
            	printf("Queue closed.\n");
            	break;
            default:
            	break;
  	  }

  	} while (input < 6);    
  	
  	free(my_heap);  	
}