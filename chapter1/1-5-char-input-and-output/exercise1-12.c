#include <stdio.h>

#define	OUT	0
#define	IN	1

int main(void) {
	int nw, c;
	int state = OUT;	
	
	nw = 0;

	while ((c = getchar()) != EOF) {
		if (c == '\n' || c == ' ' || c == '\t') {
			state = OUT;
		}
		else if (state == OUT) {
			state = IN;
			nw++;
		}
	}
	printf("Number of words: %d\n", nw);	
}
