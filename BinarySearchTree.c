/*

19) Create and Display Binary Search Tree.

*/

#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

typedef struct node* Node;

Node getNode(int item) {
	Node temp = (Node) malloc(sizeof(struct node));
	temp->data = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(Node* root, int item) {
	if(*root == NULL) {
		*root = getNode(item);
		return;
	}
	else if((*root)->data > item)
		insert(&((*root)->left), item);
	else
		insert(&((*root)->right), item);
}

void display(Node root) {
	if(root == NULL)
		return;
	display(root->left);
	printf("%d  ", root->data);
	display(root->right);
}

int main() {
	int ch, item;
	Node root = NULL;
	printf("1: Insert   2: Display   3: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: printf("Enter element: ");
					scanf("%d", &item);
					insert(&root, item);
					printf("\n");
					break;
			case 2: printf("Inorder Traversal:  ");
					display(root);
					printf("\n\n");
					break;
			case 3: printf("Terminated ..\n\n");
					break;
			default: printf("Invalid Choice\n\n");
		}
	} while(ch != 3);
}
