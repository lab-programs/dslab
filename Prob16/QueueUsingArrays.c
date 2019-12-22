/*

16) Primitive operations on linear queue using arrays

*/

#include<stdio.h>
#include<stdlib.h>
#define n 5

int q[n], f = -1, r = -1, count = 0;

void enqueue() {
	if(count == n || r == n-1)
		printf("Overflow\n\n");
	else {
		if(f == -1) 
			f++;
		count++;
		r++;
		printf("Enter element: ");
		scanf("%d", &q[r]);
		printf("%d inserted\n\n", q[r]);
	}
}

void dequeue() {
	if(count == 0 || f > r || f == -1) {
		f = -1;
		r = -1;
		printf("Underflow\n\n");
	}
	else {
		count--;
		printf("%d deleted\n\n", q[f]);
		f++;
	}
}

void display() {
	if(count == 0 || f > r || f == -1) 
		printf("Underflow\n\n");
	else {
		printf("Queue: ");
		for(int i = f; i <= r; i++)
			printf("%d ", q[i]);
		printf("\n\n");
	}
}

int main() {
	int ch;
	printf("1: Enqueue   2: Dequeue   3: Display   4: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: enqueue();		break;
			case 2: dequeue();  	break;
			case 3: display();  	break;
			case 4: printf("Terminated ..\n\n"); return 0;
			default: printf("Invalid Choice\n\n");
		}
	} while(ch != 4);
}
