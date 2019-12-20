/*

2)
a. Primitive operations on Stacks using arrays.
b. Binary search using recursion.

6)
a. Primitive operations on Stacks using arrays.
b. GCD using recursion.

8)
a. Primitive operations on Stacks using arrays.
b. Tower of Hanoi problem for n disks using recursion

*/

#include<stdio.h>
#define n 5

int top = -1, item;
int s[n];

void push() {
	if(top < n-1) {
		printf("Enter element: ");
		scanf("%d", &s[++top]);
		printf("%d pushed\n\n", s[top]);
	}
	else 
		printf("Overflow\n\n");
}

void pop() {
	if(top <= -1)
		printf("Underflow\n\n");
	else 
		printf("%d popped\n\n", s[top--]);
}

void display() {
	if(top <= -1)
		printf("Underflow\n\n");
	else {
		printf("Stack:  ");
		for(int i = 0; i <= top; i++)
			printf("%d  ", s[i]); 
		printf("\n\n");
	}
}

int main() {
	int ch;
	printf("1: Push\n2: Pop\n3: Display\n4: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: push();     			break;
			case 2: pop();				break;
			case 3: display();			break;
			case 4: printf("Terminated ..\n\n");	return 0;
			default: printf("Invalid Choice\n\n");
		}
	} while(ch != 4);
}
