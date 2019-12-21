/*
 
9) Conversion of a valid Infix expression to Postfix Expression using stacks. Program
should support for both parenthesized and parenthesize free expressions with the
operators: +, -, *, /, %(Remainder), ^(Power) and alphanumeric operands.

*/

#include<stdio.h>
#include<ctype.h>
#define n 50

int s[n], top=-1;
char pf[n];

void push(int item) {   s[++top] = item;   }

int pop() {   return s[top--];   }

int priority(char x) {
	switch(x) {
		case '+':
		case '-': return 1;
		case '*': 
		case '/': return 2;
		case '^': return 3;
		default: return -1;
	}
}

int main() {
	char exp[n];
	int i = 0;
	printf("Enter valid infix expression: ");
	scanf("%s", exp);
	char* e;
	char x;
	e = exp;
	while(*e != '\0') {
		if(isalnum(*e))
			pf[i++] = *e;
		else if(*e == '(') 
			push(*e);
		else if(*e == ')') {
			while((x = pop()) != '(')
				pf[i++] = x;
		}
		else {
			if(priority(s[top]) >= priority(*e)) 
				pf[i++] = pop();
			push(*e);
		}
		e++;
	}
	while(top != -1)
		pf[i++] = pop();
	pf[i] = '\0';
	printf("\nConverted Postfix Expression: %s\n\n", pf);
}
