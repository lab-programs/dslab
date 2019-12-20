/*

2)
a. Primitive operations on Stacks using arrays.
b. Binary search using recursion.

*/

#include<stdio.h>
#define SIZE 5
int binSearch(int* a, int key, int low, int high) {
	int mid = (low + high)/2;
	if(low > high)
		return 1;
	if(a[mid] == key) {
		printf("Element %d found at location %d\n\n", key, mid+1);
		return 0;
	}
	else if(a[mid] > key)
		return binSearch(a, key, low, mid-1);
	else 
		return binSearch(a, key, mid+1, high);
}

int main() {
	int n, a[SIZE], key;
	printf("Enter no of elements in the array: ");
	scanf("%d", &n);
	printf("Enter the array: ");
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("Enter the key element to search: ");
	scanf("%d", &key);
	if(binSearch(a, key, 0, n-1))
		printf("Element %d not found\n\n", key);
}
