/* 

6)
a. Primitive operations on Stacks using arrays.
b. GCD using recursion.

*/

#include<stdio.h>

int gcd(int n1, int n2) {
    if (n2 != 0)
        return gcd(n2, n1%n2);
    else
        return n1;
}

int main() {
	int n1, n2, hcf, lcm;
	printf("Enter first no: ");
	scanf("%d", &n1);
	printf("Enter second no: ");
	scanf("%d", &n2);
	hcf = gcd(n1, n2);
	lcm = n1*n2/hcf;
	printf("GCD: %d\n", hcf);
	printf("LCM: %d\n\n", lcm);
}
