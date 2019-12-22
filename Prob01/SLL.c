/*

1) Singly Linked List with the following operations:
a. Inserting a node( Any desired position)
b. Deleting first node from the list
c. Display

*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
};
typedef struct node* Node;

int size = 0;

Node getNode(int item) {
	Node temp = (Node) malloc(sizeof(struct node));
	temp->data = item;
	temp->link = NULL;
	return temp;
}

Node insertAtPos(Node start) {
	int item, pos;
	printf("Enter element: ");
	scanf("%d", &item);
	printf("Enter position(1 to %d): ", size+1);
	scanf("%d", &pos);
	
	Node temp = getNode(item);
	if(pos < 1 || pos > size+1) {
		printf("Invalid Position\n\n");
		return start;
	}
	printf("%d inserted\n\n", item);
	size++;
	if(start == NULL)
		return temp;
	if(pos == 1) {
		temp->link = start;
		return temp;
	}
	Node curr = start;
	for(int i = 1; i < pos-1; i++)
		curr = curr->link;
	temp->link = curr->link;
	curr->link = temp;
	return start;
}

Node deleteFirst(Node start) {
	if(start == NULL) {
		printf("List is empty. Can't Delete\n\n");
		return start;
	}
	size--;
	Node temp = start->link;
	printf("%d deleted\n\n", start->data);
	free(start);
	return temp;
}

void display(Node start) {
	if(start == NULL) {
		printf("List is empty. Can't Display\n\n");
		return;
	}
	printf("List: ");
	for(Node curr = start; curr != NULL; curr = curr->link)
		printf("%d ", curr->data);
	printf("\n\n");
}

int main() {
	int ch;
	Node start = NULL;
	printf("1: Insert at any position    2: Delete first node    3: Display    4: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: start = insertAtPos(start);		break;
			case 2: start = deleteFirst(start);		break;
			case 3: display(start);					break;
			case 4: printf("Terminated ..\n\n");	return 0;
			default: printf("Invalid Choice\n\n");
		}
	} while(ch != 4);
}
