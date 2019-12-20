//Implementation of everything in SLL for exam with doc

/*

1) Singly Linked List with the following operations:
a. Inserting a node( Any desired position)
b. Deleting first node from the list
c. Display

3) Singly Linked List with the following operations:
a. Inserting a node at first position
b. Deleting a node (Any desired position)
c. Display

4) Singly Linked List with the following operations:
a. Inserting a node( Any desired position)
b. Deleting last node from the list
c. Display

5) Singly Linked List with the following operations:
a. Inserting a node at end of the list.
b. Deleting a node (Any desired position)
c. Display

*/


//Header files
#include<stdio.h>
#include<stdlib.h>


//Structure to create a node of SLL
struct node {
	int data;
	struct node* link;
};


//To make life easy
typedef struct node* Node;


//Size of SLL
int size = 0;


//Function to dynamically allocate space for a node 
//return the pointer to node
Node getNode(int item) {

  	//Use malloc to allocate m/y
	Node temp = (Node) malloc(sizeof(struct node));
  
  	//Assign data field of temp to item passed as paramenter
	temp->data = item;
  
  	//Assign link field of temp to NULL
	temp->link = NULL;
  
  	//Return temp
	return temp;
}


//General Insert function with O(N) time complexity
void insert(Node* curr, int item, int pos) {
	
	  //Check if the position given is valid
	if(pos < 1 || pos > size+1) 
		printf("Invalid Position\n");
	else {
  
	 	//Keep decrementing pos in a while 
		//loop until it becomes zero
		while(pos--) {
    
      		//Check if pos is equal to zero
			if(pos == 0) {
      
     	   			//Create a node with the item as parameter to temp
				Node temp = getNode(item);
        
        			//Assign link field of to the content of the 
        			//pointer to the (pointer to node)/curr 
				temp->link = *curr;
        
        			//Point the content of pointer to curr to 
        			//the node which temp is pointing
				*curr = temp;
			}
			else
        
        			//Make pointer to the pointer to node point to 
        			//the next pointer to node it was originally pointing
				curr = &(*curr)->link;
		}
    
    		//INCREMENT SIZE VALUE
		size++;
    
    		//Print item was inserted
		printf("%d inserted\n", item);
	}
}


//General Delete Program with O(N) complexity
Node delete(Node start, int pos) {
	
	//Check if position is valid, start is pointing to 
	//no node or size of the SLL is zero
	if(pos < 1 || pos > size || start == NULL || size == 0) 
		printf("Invalid Position/List is empty.\n");
	else {
  
    		//Decrement the value of size
		size--;
    
    		//Check if the position is equal to 1
		if(pos == 1) {
    
      			//Create a pointer temp to point to the node 
      			//which the link field of start pointer is pointing
			Node temp = start->link;
      
      			//Print that the element is deleted
      			printf("%d deleted\n", start->data);
      
      			//Free the allocated memory for the node
			free(start);
      
      			//Return the pointer to node: temp
			return temp;
		}
		else {
      			//Create a pointer to node: curr and assign it
      			//to start and another pointer to node: temp
			Node curr = start, temp;
      
      			//Keep pointing curr to the link field of curr
      			//until you reach the node just before the node
      			//you want to delete
			for(int i = 1; i < pos-1; i++) 
				curr = curr->link;
        
      			//Assign temp to the link field of curr
			temp = curr->link;
      
      			//If the node pointed by the link field of curr
      			//is not null, then link the curr whith the link 
      			//field of the link field of curr
			if(curr->link != NULL)
				curr->link = curr->link->link;
        
      			//Print that the element is deleted
      			printf("%d deleted\n", temp->data);
			
     	 		//Free the allocated memory of the node
			free(temp);
		}
	}
  
  	//Return the pointer to first node: start
	return start;
}


void display(Node start) {

  	//Check if start is pointing to anything or not
	if(start == NULL)
		printf("List is empty\n");
	else {
  
    		//Start printing
		printf("List: ");
    
    		//Print and move to the next node
		while(start != NULL) {
			printf("%d  ", start->data);
			start = start->link;
		}
		printf("\n");
	}
}


//Self explanatory function to insert at any given position of SLL
void insertAtPos(Node* start) {
	int item, pos;
	printf("Enter element: ");
	scanf("%d", &item);
	printf("Enter position(1 to %d): ", size+1);
	scanf("%d", &pos);
	insert(start, item, pos);
}


//Self explanatory function to insert at the beginning of SLL
void insertBeg(Node* start) {
	int item;
	printf("Enter element: ");
	scanf("%d", &item);
	insert(start, item, 1);
}


//Self explanatory function to insert at the end of SLL
void insertEnd(Node* start) {
	int item;
	printf("Enter element: ");
	scanf("%d", &item);
	insert(start, item, size+1);
}


//Self explanatory function to delete at any position of SLL
Node deleteAtPos(Node start) {
	int pos;
	printf("Enter position(1 to %d): ", size);
	scanf("%d", &pos);
	return delete(start, pos);
}


//Self explanatory function to delete at the beginning of SLL
Node deleteBeg(Node start) {   return delete(start, 1);   }


//Self explanatory function to delete at the end of SLL
Node deleteEnd(Node start) {   return delete(start, size);   }


//Main Function with a simple menu
int main() {
	Node start = NULL;
	int ch;
	printf("1: Insert at position\n2: Insert at beginning\n3: Insert at end\n4: Delete at position\n");
	printf("5: Delete at beginning\n6: Delete at end\n7: Display\n8: Exit\n\n");
	do {
		printf("Enter your choice: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: insertAtPos(&start);		break;
			case 2: insertBeg(&start);		break;
			case 3: insertEnd(&start);		break;
			case 4: start = deleteAtPos(start);	break;
			case 5: start = deleteBeg(start);	break;
			case 6: start = deleteEnd(start);	break;
			case 7: display(start);			break;
			case 8: printf("Terminated ..\n");	return 0;
			default: printf("Invalid Choice\n");
		}
	} while(ch != 8);
}
