// A calculator that uses reverse polish notation 
// Exercise 4.5 focuses on adding sin, exp, & pow functions. I kinda took my own approach to it. Since I was adding sin, I decided to add all 6 trigonomic functions. I may or may not complete this with exp or pow functions in the future.
// (1 - 2) * (4 + 5) is written as 1 2 - 4 5 + *
// Supports +, -, *, /, %, and trig functions.
// To use trig functions, you have to place the angle of the trig functon before declaring the actual trig function, e.g. (60 sin), which is the same as sin of 60 degrees.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define	MAXOP	100 /* max size of operand or operator */
#define	NUMBER	'0' /* signal that a number was found */
#define	MAXVAL	100 /* maximum depth of val stack */
#define	BUFSIZE	100 /* buffer size for ungetch */

// Trig functions
#define	SIN	100
#define	COS	101
#define TAN	102
#define	CSC	103
#define	SEC	104
#define	COT	105

int getop(char []);
void push(double);
double pop(void);
void ungetch(int);
int getch(void);
double degreeToRadian(double deg);

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
		case SIN:
			push(sin(degreeToRadian(pop())));
			break;
		case COS:
			push(cos(degreeToRadian(pop())));
			break;
		case TAN:
			push(tan(degreeToRadian(pop())));
			break;
		case CSC:
			push(1 / (sin(degreeToRadian(pop()))));
			break;
		case SEC:
			push(1 / (cos(degreeToRadian(pop()))));
			break;
		case COT:
			push(1 / (tan(degreeToRadian(pop()))));
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
		printf("Error: accessed undeclared stack position, cannot push %g\n", f);
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
	int c, i = 0;
	while ((s[0] = c = getch()) == ' ' || c == '\t') {
		;
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.') { // Not a number
		if (c == 's' || c == 'c' || c == 't') { // Trig function
			char trig[4];
			trig[0] = c;
			int ltrIdx = 1;
			while ((isalpha(s[++i] = c = getch())) && c != EOF && ltrIdx < 3) { // Collects trig function type
				trig[ltrIdx] = c;
				ltrIdx++;
			}
			trig[3] = '\0';
			
			if (strcmp(trig, "sin") == 0) {
				if (c != EOF) {
					ungetch(c);
				}
				return SIN;
			}
			else if (strcmp(trig, "cos")== 0) {
				if (c != EOF) {
					ungetch(c);
				}
				return COS;
			}
			else if (strcmp(trig, "tan") == 0) {		
				if (c != EOF) {
					ungetch(c);
				}
				return TAN;
			}
			else if (strcmp(trig, "csc") == 0) {
				if (c != EOF) {
					ungetch(c);
				}	
				return CSC;
			}
			else if (strcmp(trig, "sec") == 0) {
				if (c != EOF) {
					ungetch(c);
				}	
				return SEC;
			}
			else if (strcmp(trig, "cot") == 0) {
				if (c != EOF) {
					ungetch(c);
				}	
				return COT;
			}
			else {
				printf("Error: unrecognized trig function %s\n", trig);
				exit(EXIT_FAILURE);	
			}
		} else {
			return c;
		}
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

double degreeToRadian(double deg) { // I decided to switch the radians so you can enter common values for the trig function easily, such as pi (180) and 3pi/2 (270)
	return ((3.1415926535 / 180) * deg);
}
