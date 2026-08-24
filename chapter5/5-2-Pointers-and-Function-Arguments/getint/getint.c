#include <ctype.h>
#include <stdio.h>

#define	SIZE	100

int getch(void);
void ungetch(int);
int getint(int *pn);

int main(void) {
	int n, array[SIZE];

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {
		printf("array space %d: %d\n", n, array[n]); 
	}
	

	return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {
	int c, sign;

	while (isspace(c = getch())) // Skips whitespace
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') { // Checks to see if the current number is valid
		ungetch(c);	/* NaN */
		return 0;
	}

	sign = (c == '-') ? -1 : 1; // Account for if the sign is either + or -
	if (c == '+' || c == '-') {
		c = getch();
	}
	
	if (!isdigit(c)) {
		ungetch(c);
		*pn = 0;
		return 0;
	}

	for (*pn = 0; isdigit(c); c = getch()) { // Convert the input into an intger and place it in the point pn
		*pn = 10 * *pn + (c - '0');
	}

	*pn *= sign;
	if (c != EOF) {
		ungetch(c);
	}
	return c;
}
