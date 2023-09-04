#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void Insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void PrintLL(struct Node* head){
	struct Node* current = head;
	while(current!=NULL){
		printf("%d -> ",current->data);
		current = current->next;
	}
	printf("NULL\n");
}

int countNodes(struct Node* head){
	int count = 0;
	struct Node* current = head;
	while(current!=NULL){
		count++;
		current = current->next;
	}
	return count;
}

void freeLL(struct Node* head){
	struct Node* current = head;
	while(current!=NULL){
		struct Node* temp = current;
		current = current->next;
		free(temp);
	}

}


int main() {
    struct Node* head = NULL;

    // Insert three elements into the linked list
    Insert(&head, 15);
    Insert(&head, 25);
    Insert(&head, 35);
    Insert(&head, 45);
    Insert(&head, 55);
    Insert(&head, 65);
    Insert(&head, 75);
    Insert(&head, 85);
    Insert(&head, 95);

    // Print the first element (head) of the linked list
    if (head != NULL) {
        printf("%d\n", head->data); // This will print 45
    } else {
        printf("Linked list is empty.\n");
    }
    
    PrintLL(head);
    int a = countNodes(head);
    printf("%d\n",a);
    freeLL(head);

    return 0;
}

