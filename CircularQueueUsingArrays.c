/*

17) Implement Circular queue using arrays.

*/

#include<stdio.h>
#include<stdlib.h>
#define n 5

int cq[n], f = -1, r = -1, count = 0;

void enqueue() {
	if(count == n)
		printf("Overflow\n\n");
	else {
		count++;
		if(f == -1)
			f++;
		r = (r+1)%n;
		printf("Enter element: ");
		scanf("%d", &cq[r]);
		printf("%d inserted\n\n", cq[r]);
	}
}

void dequeue() {
	if(count == 0) 
		printf("Underflow\n\n");
	else {
		count--;
		printf("%d deleted\n\n", cq[f]);
		f = (f+1)%n;
	}
}

void display() {
	if(count == 0)
		printf("Underflow\n\n");
	else {
		printf("Circular Queue: ");
		for(int i = f; i != r; i = (i+1)%n) 
			printf("%d ", cq[i]);
		printf("%d\n\n", cq[r]);
	}
}

int main() {
	int ch;
	printf("1: Enqueue   2: Dequeue   3: Display   4: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: enqueue();	break;
			case 2: dequeue(); 	break;
			case 3: display();	break;
			case 4: printf("Terminated ..\n\n");  break;
			default: printf("Invalid Choice\n\n");
		}
	} while(ch != 4);
}
