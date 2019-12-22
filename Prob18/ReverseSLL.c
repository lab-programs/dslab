/*

18) Reverse a given singly linked list.

*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* link;
};

typedef struct node* Node;

Node getNode(int item) {
	Node temp = (Node) malloc(sizeof(struct node));
	temp->data = item;
	temp->link = NULL;
	return temp;
} 

Node insertEnd(Node start) {
	int item;
	printf("Enter element: ");
	scanf("%d", &item);
	Node temp = getNode(item);
	printf("\n");
	if(start == NULL)
		return temp;
	else {
		Node curr;
		for(curr = start; curr->link != NULL; curr = curr->link);
		curr->link = temp;
		return start;
	}
}

Node insertBeg(Node start, int item) {
	Node temp = getNode(item);
	temp->link = start;
	return temp;
}

Node reverse(Node start) {
	if(start == NULL) {
		printf("List is Empty. Can't reverse\n\n");
		return start;
	}
	Node newStart = NULL;
	for(Node curr = start; curr != NULL; curr = curr->link)
		newStart = insertBeg(newStart, curr->data);
	return newStart;
}

void display(Node start) {
	if(start == NULL)
		printf("List is Empty. Can't display\n\n");
	else {
		printf("List: ");
		for(Node curr = start; curr != NULL; curr = curr->link)
			printf("%d ", curr->data);
		printf("\n\n");
	}
}

int main() {
	int ch;
	Node start = NULL;
	printf("1: Insert   2: Reverse   3: Display   4: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: start = insertEnd(start);		break;
			case 2: start = reverse(start);			break;
			case 3: display(start);					break;
			case 4: printf("Terminated ..\n\n");	break;
			default: printf("Invalid Choice\n\n");
		}
	} while(ch != 4);
}
