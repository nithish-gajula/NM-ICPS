#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 3


typedef struct {
	int data[MAXSIZE];
	int top;
} Stack;

void initialization(Stack* stack){
	stack->top = -1;
}

int isEmpty(Stack* stack){
	if(stack->top == -1){
		return 1;
	} else {
		return 0;
	}
}

int isFull(Stack* stack){
	if(stack->top==MAXSIZE-1){
		return 1;
	} else {
		return 0;
	}
}


void peek(Stack* stack) {
	if(isEmpty(stack)){
		printf("Can't retreive data, Stack is empty\n");
	} else {
		printf("------------------------------\n");
		printf("Top most element is : %d \n",stack->data[stack->top]);
		printf("------------------------------\n");
	}
}


void push(Stack* stack,int value){
	if(isFull(stack)){
		printf("Stack is Full, Can't add items \n");
	} else {
		stack->top += 1;
		stack->data[stack->top] = value;
		printf("------------------------------\n");
		printf("item added: %d \n", stack->data[stack->top]);
		printf("------------------------------\n");
	}
}

void pop(Stack* stack) {
	if(isEmpty(stack)){
		printf("Stack is Empty, Can't delete items \n");
	} else {
		printf("------------------------------\n");
		printf("item removed: %d \n",stack->data[stack->top]);
		printf("------------------------------\n");
		stack->top -= 1;
	}
}

void display(Stack* stack){
	for (int i=0; i<=stack->top;i++){
		printf(" %d ",stack->data[i]);
	}
}

void size(Stack* stack){
	printf("%d",top+1);
}


void main(){

	Stack s1;
	initialization(&s1);

	int choice, value;
	int flag = 1;

	do {
		printf("Stack Operations:\n");
		printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. isEmpty\n6. isFull\n0. Exit\n");
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
        			push(&s1,value);
        			break;
        		case 2:
        			pop(&s1);
        			break;
        		case 3:
        			peek(&s1);
        			break; 
        		case 4:
        			display(&s1);
        			break;
        		case 5:
        			(isEmpty(&s1)) ? printf("Stack is Empty\n") : printf("Stack is not Empty\n");
        			break;
        		case 6:
        			(isFull(&s1)) ? printf("Stack is Full\n") : printf("Stack is not Full\n");
        			break;
        		case 7:
        			size(&s1);
        			break;
        		default:
        			printf("Wrong input\n");
        			break;
        	}
        } while(flag);
}	
