/*

11) Queues using Singly Linked List.

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

Node enqueue(Node start) {
	int item;
	printf("Enter element: ");
	scanf("%d", &item);
	printf("%d inserted\n\n", item);
	Node temp = getNode(item), curr = start;
	if(start == NULL)
		return temp;
	else {
		while(curr->link != NULL) 
			curr = curr->link;
		curr->link = temp;
		return start;
	}
}

Node dequeue(Node start) {
	if(start != NULL) {
		Node temp = start->link;
		printf("%d deleted\n\n", start->data);
		free(start);
		return temp;
	}
	printf("Underflow\n\n");
	return start;
}

void display(Node start) {
	if(start != NULL) {
		printf("Queue: ");
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
	printf("1: Enqueue   2: Dequeue   3: Display   4: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: start = enqueue(start);			break;
			case 2: start = dequeue(start);			break;
			case 3: display(start);					break;
			case 4: printf("Terminated ..\n\n");	break;
			default: printf("Invalid Choice\n\n");
		}
	} while(ch != 4);
}
