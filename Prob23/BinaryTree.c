/*

23) Binary Tree operations:
i) Creation
ii) Traversal(Inorder, Preorder, Postoder)

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

Node create(Node root) {
	int item;
	printf("Enter data(-1 for no data): ");
	scanf("%d", &item);
	
	if(item == -1) 
		return NULL;
	
	root = getNode(item);
	
	printf("Enter left child of %d:\n", item);
	root->left = create(root->left);
	
	printf("Enter right child of %d:\n", item);
	root->right = create(root->right);
	
	return root;
}

void preorder(Node root) {
	if(root == NULL)
		return;
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node root) {
	if(root == NULL)
		return;
	inorder(root->left);
	printf("%d ", root->data);
	inorder(root->right);
}

void postorder(Node root) {
	if(root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->data);
}

int main() {
	Node root = NULL;
	root = create(root);
	printf("\n\nPreorder: ");
	preorder(root);
	printf("\n\nInorder: ");
	inorder(root);
	printf("\n\nPostorder: ");
	postorder(root);
	printf("\n\n");
}
