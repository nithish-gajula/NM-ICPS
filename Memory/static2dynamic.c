#include <stdio.h>

int main() {
    int staticArray[5] = {1, 2, 3, 4, 5};

    int *pointerToArray = staticArray;  // Using the array name as a pointer

    // Accessing elements using the pointer
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, pointerToArray[i]);
	printf("Element %d: %d\n", i, *(pointerToArray+i));
    }

    return 0;
}

