/*

8)
a. Primitive operations on Stacks using arrays.
b. Tower of Hanoi problem for n disks using recursion.

*/

#include<stdio.h>

void toh(int n, char source, char destination, char spare) {
	if(n == 1) {
		printf("Moved rod 1 from %c to %c\n\n", source, destination);
		return;
	}
	toh(n-1, source, spare, destination);
	printf("Moved rod %d from %c to %c\n", n, source, destination);
	toh(n-1, spare, destination, source);
}

int main() {
	int n; 
	printf("Enter no. of disks: ");
	scanf("%d", &n);
	toh(n, 'A', 'B', 'C');
}
