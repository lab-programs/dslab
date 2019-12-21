/*

7) Evaluation of a valid Postfix expression using stacks.

*/
#include<stdio.h>
#include<stdlib.h>
#define n 50

int s[n], top = -1;

void push(int item) {   s[++top] = item;   }

int pop() {   return s[top--];   }

int getans(char x, int a, int b) {
	switch(x) {
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '%': return a%b;
		case '^': return a^b;
	}
}

int isitadigit(char x) {   return ((int)x >= (int) '0' && (int)x <= (int)'9');   }

void evaluate(char* pf) {
	for(int i = 0; pf[i] != '\0'; i++) {
		if(isitadigit(pf[i]))
			push((int)pf[i] - 48);
		else {
			int a = pop(), b = pop();
			int c = getans(pf[i], b, a);
			push(c);
		}
	}
	printf("The postfix expression was evaluated to: %d\n", pop());
}



int main() {
	char pf[n];
	printf("Enter valid postfix expression(In the expression, you can use +, -, *, /, % and ^ only): ");
	scanf("%s", pf);
	evaluate(pf);
}
