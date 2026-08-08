// A calculator that uses reverse polish notation 
// Exercise 4.3 focuses on adding the % (modulo) functionality 
// (1 - 2) * (4 + 5) is written as 1 2 - 4 5 + *
// Supports + - * / %
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define	MAXOP	100 /* max size of operand or operator */
#define	NUMBER	'0' /* signal that a number was found */
#define	MAXVAL	100 /* maximum depth of val stack */
#define	BUFSIZE	100 /* buffer size for ungetch */

int getop(char []);
void push(double);
double pop(void);
void ungetch(int);
int getch(void);

// For the push and pop functions
int sp = 0;		/* next free stack position */
double val[MAXVAL];	/* value stack */

// For the getch and ungetch functions
char buf[BUFSIZE];	/* buffer for ungetch */
int bufp = 0;		/* next free position in buf */

int main(void) {
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0) {
				push(pop() / op2);
			}
			else {
				printf("Error: zero divisor\n");
			}
			break;
		case '%':	
			op2 = pop();
			if (op2 != 0.0) {
				push(fmod(pop(), op2)); // Used fmod instead of % operator to support double types
			}
			else {
				printf("Error: zero divisor\n");
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("Error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

// Push f onto value stack
void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	}
	else {
		printf("Error: stack full, cannot push %g\n", f);
	}
}

// Pop and return top value from stack
double pop(void) {
	if (sp > 0) {
		return val[--sp];
	}
	else {
		printf("Error: stack empty\n");
		return 0.0;
	}
}

// Get the next character or numeric operand
int getop(char s[]) {
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t') {
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.') { // Not a number
		return c;
	}
	i = 0;
	if (isdigit(c)) { // Collect integer part
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	if (c == '.') { // Collect fraction part
		while (isdigit(s[++i] = c = getch())) {
			;
		}
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

// Get a (possibly pushed-back) character
int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

// Push chacter back on input
void ungetch(int c) {
	if (bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	}
	else {
		buf[bufp++] = c;
	}
}
