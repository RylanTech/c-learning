#include <stdio.h>

int main(void) {
	char c;
       	int spaceCount = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (!spaceCount) {
				putchar(' ');
				spaceCount = 1;
			}
		} else {
			putchar(c);
			spaceCount = 0;
			
		}
	}

	
}
