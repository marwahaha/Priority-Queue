//  priorityTest.c
//  V1, 05/14/15
//  Created by Jeffrey

#include "priorityFunctions.h"

int main(int argc, char *argv[]) {

    int size = argc - 2;
    
    int toSort[size];
    
    int i;
    
    if (argc <= 2) {
        printf("You are missing arguments.\n");
    }
    
    else {

        for (i = 2; i < argc; i++) {
            toSort[i-2] = atoi(argv[i]);
        }
        
        switch (tolower(argv[1][0])) {
            case 'h':
                heapSort(toSort, size);
                printArray(toSort, size);
                break;
            default:
                break;
        }
    }
    
    return 0;
}
