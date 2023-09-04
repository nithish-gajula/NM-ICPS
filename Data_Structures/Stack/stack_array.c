#include<stdio.h>
#define MAXSIZE 8
int stack[MAXSIZE];
int top = -1;

// Function to check whether stack is empty or not
int isEmpty(){
	if(top == -1){
		return 1;
	}else{
		return 0;
	}
}

// Function to check whether stack is full or not
int isFull(){
	if(top == MAXSIZE-1){
		return 1;
	}else{
		return 0;
	}
}

// Function to add item to the stack
void push(int value){
	if(isFull()){
		printf("Stack is Full, Can't add item \n");
	} else {
		top += 1;
		stack[top] = value;
		printf("------------------------------\n");
		printf("item added: %d \n",stack[top]);
		printf("------------------------------\n");
	}
}

// Function to delete item from stack
void pop(){
	if(!isEmpty()){
		printf("item removed : %d \n",stack[top]);
		top = top -1;
		
	} else {
		printf("Stack is Empty, can't remove item \n");
	}
}

// Function to return the topmost item from the stack
int peek(){
	return stack[top];
}

// Function to return the size of stack
int size(){
	return top + 1;
}

// Function to print the stack
void print_stack(){
	for(int i=0;i<=top;i++) {
		printf("%d ",stack[i]);
	}
}




void main(){

	int flag = 1;
	int input;
	while(flag){
		printf("1.isEmpty\n2.isFull\n3.push\n4.pop\n5.peek\n6.size\n7.print_stack\n9.exit\n");
		scanf("%d",&input);
		if(input==1){
			if(isEmpty()){
				printf("Stack is empty \n");
			}else{
				printf("Stack is not empty \n");
			}
		} else if(input==2){
			if(isFull()){
				printf("Stack is full \n");
			}else{
				printf("Stack is not full \n");
			}
		} else if(input==3){
			int item = 0;
			printf("Enter item to be added :");
			scanf("%d",&item);
			push(item);
		} else if(input==4){
			pop();
		} else if(input==5){
			printf("top item : %d \n",peek());
		} else if(input==6){
			printf("stack size : %d \n",size());
		} else if(input==7){
			print_stack();
		} else if(input==9){
			flag = 0;
		}
	}
	
}
	
