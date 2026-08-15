#include <stdio.h>
#include <ctype.h>
#include "calc.h"

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

