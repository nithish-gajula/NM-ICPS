#include<stdio.h>
#define MAXSIZE 4

typedef struct {
	int data[MAXSIZE];
	int front;
	int rear;
} Queue;

void initialization(Queue* queue){
	queue->front = -1;
	queue->rear = -1;
}


int isEmpty(Queue* queue){
	if(queue->rear == -1){
		return 1;
	} else {
		return 0;
	}
}

int isFull(Queue* queue){
	if(queue->rear == MAXSIZE-1){
		return 1;
	} else {
		return 0;
	}
}

void Enqueue(Queue* queue,int value){
	if(isFull(queue)){
		printf("Queue is Full, Can't add items\n");
	} else {
		if(queue->rear==-1){
			queue->front += 1;
		}
		queue->rear += 1;
		queue->data[queue->rear] = value;
		printf("item added : %d \n",queue->data[queue->rear]);
	}
}

void Dequeue(Queue* queue){
	if(isEmpty(queue)){
		printf("Queue is Empty, Can't Delete items\n");
	} else {
		for (int i=1;i<=queue->rear;i++){
			queue->data[i-1] = queue->data[i];
		}
		queue->rear -= 1;
	}
}

void peek(Queue* queue){
	printf("Latest item : %d \n",queue->data[queue->rear]);
}

void Display(Queue* queue){
	if(isEmpty(queue)){
		printf("Queue is empty, Can't display items\n");
	} else {
		printf("-------------------------------\n");
		printf("Queue is : ");
		for (int i=0;i<=queue->rear;i++){
			printf(" %d ",queue->data[i]);
		}
		printf("\n-------------------------------\n");
	}
}

void size(Queue* queue){
	printf("Number of items present in queue : %d",queue->rear+1);
}

void main(){

	Queue q1;
	initialization(&q1);

	int value,flag = 1;
	do{
		int value, choice;
		printf("\n0. Exit\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Size\n");
		printf("Enter your choice :");
		scanf("%d",&choice);
		
		switch (choice) {
			case 0:
				flag=0;
				break;
			case 1:
				printf("Enter item to add :");
				scanf("%d",&value);
				Enqueue(&q1,value);
				break;
			case 2:
				Dequeue(&q1);
				break;
			case 3:
				peek(&q1);
				break;
			case 4:
				Display(&q1);
				break;
			case 5:
				size(&q1);
				break;
			default :
				printf("Wrong Input given\n");
		}
	
	} while(flag);
}
