/*

10) Stack using Singly Linked List.

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

Node push(Node start) {
	int item;
	printf("Enter element: ");
	scanf("%d", &item);
	Node temp = getNode(item);
	temp->link = start;
	printf("%d pushed\n\n", item);
	return temp;
}

Node pop(Node start) {
	if(start != NULL) {
		Node temp = start->link;
		printf("%d popped\n\n", start->data);
		free(start);
		return temp;
	}
	printf("Underflow\n\n");
	return start;
}

void display(Node start) {
	if(start != NULL) {
		printf("Stack: ");
		while(start != NULL) {
			printf("%d ", start->data);
			start = start->link;
		}
		printf("\n\n");
		return;
	}
	printf("Underflow\n\n");
}

int main() {
	Node start = NULL;
	int ch;
	printf("1: Push   2: Pop   3: Display   4: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: start = push(start);	 	 break;
			case 2: start = pop(start); 	 	 break;
			case 3: display(start);			 	 break;
			case 4: printf("Terminated ..\n\n"); return 0;
			default: printf("Invalid Choice\n\n");
		}
	}while(ch != 4);
}
