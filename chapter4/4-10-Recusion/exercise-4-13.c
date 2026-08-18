#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	MAXLINE	100

void recurseReverse(char v[], int *i);

int main(void) {
	char *v = NULL;
	size_t len = 0;
	ssize_t read;
	
	int i = 0;
	
	read = getline(&v, &len, stdin);
	
	recurseReverse(v, &i);

	printf("%s\n", v);

	free(v);
	return 0;
}

void recurseReverse(char v[], int *iPtr) {
	char letter = v[*iPtr];
	int currentIndex = *iPtr;
	if (v[*iPtr] != '\0') {
		(*iPtr)++;
		recurseReverse(v, iPtr);
		v[*iPtr - currentIndex - 1] = letter;
	}
	// printf("CurrentIndex: %d\n", currentIndex);
	// printf("Letter: %c\n", letter);
	// printf("string: %s\n", v);	
}
