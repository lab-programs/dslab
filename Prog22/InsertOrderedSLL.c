/*

22) Insert a given element into an ordered list and display the contents.

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

Node insert(Node start) {
	int item;
	printf("Enter element: ");
	scanf("%d", &item);
	Node temp = getNode(item);
	printf("%d inserted\n\n", item);
	if(start == NULL) 
		return temp;
	else if(start->data >= item) {
			temp->link = start;
			return temp;
	}
	else {
		Node curr;
		for(curr = start; curr->link != NULL; curr = curr->link) {
			if(curr->link->data >= item) {
				temp->link = curr->link;
				curr->link = temp;
				return start;
			}
		}
		curr->link = temp;
		return start;
	}
}

void display(Node start) {
	if(start == NULL) {
		printf("List is empty. Can't display\n\n");
		return;
	}
	Node curr;
	printf("List: ");
	for(curr = start; curr != NULL; curr = curr->link) 
		printf("%d ", curr->data);
	printf("\n\n");
}

int main() {
	Node start = NULL;
	int ch;
	printf("1: Insert   2: Display   3: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: start = insert(start);	break;
			case 2: display(start);			break;
			case 3: printf("Terminated ..\n\n");    return 0;
			default: printf("Invalid Choice\n\n");
		}
	} while(ch != 3);
}
