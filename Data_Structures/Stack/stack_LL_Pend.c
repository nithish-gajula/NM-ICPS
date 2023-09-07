#include<stdio.h>
#include<stdlib.h>

typedef struct nodes {
	int num;
	struct nodes *next;
}Stack;


Stack *push_node(Stack *);
Stack *pop_node(Stack *);
Stack *create_node();
void print_node(Stack *);

int main(){
	Stack *TOP;
	int n;
	while(1){
		printf("0. Exit\n1. Push\n2. Pop\n3. Display\n");
		printf("Enter your choice :");
		scanf("%d",&n);
		switch(n){
			case 1:
				push_node(TOP);
				break;
			case 2:
				pop_node(TOP);
				break;
			case 3:
				print_node(TOP);
				break;
			case 0:
				return 0;
				break;
			default:
				printf("Wrong choice\n");
				break;
		}
	}
}

Stack *create_node() {
	Stack *node;
	node=(Stack *)malloc(sizeof(Stack));
	printf("Enter any number:");
	scanf("%d",&node->num);
	node->next=NULL;
	return node;
}

Stack *push_node(Stack *Head) {
	Stack *New;
	New=create_node();
	New->next=Head;
	return New;
}

Stack *pop_node(Stack *Head) {
	Stack *T=Head;
	if(Head!=NULL)
		T=Head->next;
	else
		printf("\n No nodes present\n");
		return T;
}

void print_node(Stack *T) {
	printf("\n-----------------------------------\n");
	printf("Node Data : ");
	while(T) {
		printf(" %d ",T->num);
		T=T->next;
	}
	printf("\n-----------------------------------\n");
}


