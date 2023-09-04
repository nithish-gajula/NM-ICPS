#include<stdio.h>
#define MAXSIZE 4
int queue[MAXSIZE];
int front = -1;
int rear = -1;

int isEmpty(){
	if(rear == -1){
		return 1;
	} else {
		return 0;
	}
}

int isFull(){
	if(rear == MAXSIZE-1){
		return 1;
	} else {
		return 0;
	}
}

void Enqueue(int value){
	if(isFull()){
		printf("Queue is Full, Can't add item\n");
	} else {
		if(rear==-1){
			front += 1;
		}
		rear += 1;
		queue[rear] = value;
		printf("item added : %d \n",queue[rear]);
	}
}

void Dequeue(){
	if(isEmpty()){
		printf("Queue is Empty, Can't delete item\n");
	} else {
		for (int i=1; i<=rear; i++){
			queue[i-1] = queue[i];
		}
		rear -= 1;
	}
}

void peek(){
	printf("Latest element : %d \n", queue[rear]);
}

void Display(){
	if(isEmpty()){
		printf("Queue is Empty, Can't display items\n");
	} else {
		printf("------------------------------------\n");
		printf("Queue is : ");
		for (int i=0; i<=rear; i++){
			printf(" %d ",queue[i]);
		}
		printf("\n----------------------------------\n");
	}
}

void size(){
	printf("Number of items present in queue : %d \n",rear+1);
}

void main(){
	
	int flag = 1;
	int value, choice;
	
	do {
		printf("0. Exit\n1. Enqueue\n2. Dequeue\n3. peek\n4. Display\n5. Size\n");
		printf("Enter your choice :");
		scanf("%d",&choice);
	
		switch (choice){
		
			case 0:
				flag = 0;
				printf("Exiting the program\n");
				break;
			case 1:
				printf("Enter item to add : ");
				scanf("%d",&value);
				Enqueue(value);
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				peek();
				break;
			case 4:
				Display();
				break;
			case 5:
				size();
				break;
			default:
				printf("Wrong input\n");
				break;
		
		}
	
	} while(flag);
	
}


