#include <stdio.h>
#include "calc.h"

#define	MAXVAL	100

int sp = 0;
double val[MAXVAL];

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
