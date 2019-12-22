/*

20) Priority queue using array.

*/

#include<stdio.h>
#include<stdlib.h>
#define n 5

int pq[n], f = -1, r = -1;

void insert() {
	if(r >= n-1)
		printf("Overflow\n\n");
	else {
		if(f == -1)
			f = 0;
		int item;
		r++;
		printf("Enter element: ");
		scanf("%d", &item);
		printf("%d inserted\n\n", item);
		for(int i = f; i < r; i++) {
			if(pq[i] > item) {
				for(int j = r-1; j >= i; j--) 
					pq[j+1] = pq[j];
				pq[i] = item;
				return;
			}
		}
		pq[r] = item;
	}
}

void delete() {
	if(f == -1||r == -1) {
		r = -1;
		f = -1;
		printf("Underflow\n\n");
		return;
	}
	printf("%d deleted\n\n", pq[f]);
	for(int i = f; i < r; i++) 
		pq[i] = pq[i+1];
	r--;
}

void display() {
	if(f != -1 && r != -1) {
		printf("Priority queue: ");
		for(int i = f; i <= r; i++) 
			printf("%d  ", pq[i]);
		printf("\n\n");
		return;
	}
	printf("Underflow\n\n");
}

int main() {
	int ch;
	printf("1: Insert   2: Delete   3: Display   4: Exit\n\n");
	do {
		printf("Enter: ");
		scanf("%d", &ch);
		switch(ch) {
			case 1: insert();	break;
			case 2: delete();   break;
			case 3: display();	break;
			case 4: printf("Terminated ..\n\n");   break;
			default: printf("Invalid Choice\n\n");
		}
	} while(ch != 4);
}
