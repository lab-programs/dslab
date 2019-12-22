/*

21) Represent and evaluate a given polynomial using singly linked list.

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node {
	int coeff;
	int power;
	struct node* link;
};

typedef struct node* Node;

Node getNode(int c, int p) {
	Node temp = (Node) malloc(sizeof(struct node));
	temp->coeff = c;
	temp->power = p;
	temp->link = NULL;
	return temp;
}

Node insert(Node start) {
	int c, p;
	printf("Enter coefficient of the term: ");
	scanf("%d", &c);
	printf("Enter the power of the term: ");
	scanf("%d", &p);
	Node temp = getNode(c, p);
	if(start == NULL)
		return temp;
	else if(start->power <= temp->power) {
		temp->link = start;
		return temp;
	}
	else {
		Node curr;
		if(start->link == NULL) {
			start->link = temp;
			return start;
		}
		for(curr = start; curr->link->link != NULL; curr = curr->link) {
			if(curr->link->power <= temp->power) {
				temp->link = curr->link;
				curr->link = temp;
				return start;
			}
		}
		if(curr->link->power <= temp->power) {
			temp->link = curr->link;
			curr->link = temp;
			return start;
		}
		else 
			curr->link->link = temp;
		return start;
	}
}

void display(Node start) {
	if(start == NULL) {
		printf("Underflow\n\n");
		return;
	}
	Node curr;
	printf("Polynomial: ");
	for(curr = start; curr->link != NULL; curr = curr->link) 
		printf("(%d)*x^(%d) + ", curr->coeff, curr->power);
	printf("(%d)*x^(%d)\n\n", curr->coeff, curr->power);
}

void evaluate(Node start) {
	if(start == NULL) {
		printf("Underflow\n\n");
		return;
	}
	printf("Enter value of x: ");
	int x, sum = 0;
	scanf("%d", &x);
	for(Node curr = start; curr != NULL; curr = curr->link)
		sum += curr->coeff*((int)pow(x, curr->power));
	printf("The polynomial was evaluated to: %d\n\n", sum);
}

int main() {
	int ch;
	Node start = NULL;
	printf("1: Insert   2: Display   3: Evaluate   4: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: start = insert(start);	break;
			case 2: display(start);			break;
			case 3: evaluate(start);		break;
			case 4: printf("Terminated ..\n\n");    return 0;
			default: printf("Invalid Choice\n\n");
		}
	} while(ch != 4);
}
