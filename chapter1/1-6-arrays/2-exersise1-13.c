#include <stdio.h>

int main(void) {
	
	int c, i, nspace, nother, nwhite;
	int ndigit[10];

	nwhite = nspace = nother = 0;
	for (i = 0; i < 10; i++) {
		ndigit[i] = 0;
	}	

	while ((c = getchar()) != EOF) {
		if (c >= '0' && c <= '9') {
			ndigit[c - '0']++;
		}
		else if (c == ' ' || c == '\n' || c == '\t') {
			nwhite++;
		}
		else {
			nother++;
		}	
	}

	

	printf("digits:\n");
	for (i = 0; i < 10; i++) {
		printf("%d>", i);	
		int amount = ndigit[i];
		for (int k = 0; k < amount; k++) {
			putchar('I');
		}
		putchar('\n');
	}
	printf("White space = %d\nother = %d\n", nwhite, nother);


}	
