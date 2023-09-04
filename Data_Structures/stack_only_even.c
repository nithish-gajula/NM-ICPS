#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to check if a number is even
int isEven(int num) {
    return num % 2 == 0;
}

// Function to push an even number onto the stack
void pushEven(struct Node** stack, int data) {
    if (isEven(data)) {
        struct Node* newNode = createNode(data);
        newNode->next = *stack;
        *stack = newNode;
    }
}

// Function to print the elements of the stack
void printStack(struct Node* stack) {
    printf("---------------------\n");
    printf("Stack: ");
    while (stack != NULL) {
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n---------------------\n");
}


int main() {
    struct Node* stack = NULL;

    int choice, value;
	int flag = 1;
	
	
	

	do {
		printf("Linked_List Operations:\n");
		printf("1. Push\n2. Display\n0. Exit\n");
        	printf("Enter your choice: ");
        	scanf("%d", &choice);
        	
        	switch (choice) {
        	
        		case 0:
        			printf("Exiting the program \n");
        			flag = 0;
        			break;
        		case 1:
        			printf("Enter item to push :");
        			scanf("%d",&value); 
        			pushEven(&stack, value);  // Ignored it value is not even number
        			break;
        		case 2:
        			printStack(stack);
        			break;
        		default:
        			printf("Wrong input\n");
        			break;
        	}
        } while(flag);
        

        return 0;
}
