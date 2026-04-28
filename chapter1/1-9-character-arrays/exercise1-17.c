#include <stdio.h>

#define	MAXLINE	1000 /* maximum input line */
#define MAXNUMOFLINES	20	/* maximum number of lines to hold */
#define	NUMOFCHARSTOHOLD	20	/* determine how long an array of strings has to be to decide to hold it */

int getlinev2(char line[], int maxline);
void copy(char to[], char from[]);

int main(void) {
	int len;		/* current line length */
	int max;		/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char overLines[MAXNUMOFLINES][MAXLINE];	/* Holding every string over NUMOFCHARSTOHOLD lines */
	int currentArrIndex;	/* hold the current index in the array to place a new item in*/

	currentArrIndex = 0;
	while ((len = getlinev2(line, MAXLINE)) > 0) {
		if (len >= NUMOFCHARSTOHOLD) {
			copy(overLines[currentArrIndex], line);	
			currentArrIndex++;
		}
	}
	if (currentArrIndex > 0) {
		printf("\nAll lines over 20 characters:\n");
		for (int i = 0; i < currentArrIndex; i++) {
			printf("%s", overLines[i]);
		}	
	}
	return 0;
}

/* getline: read a line into s, return length*/
int getlinev2(char s[], int lim) {
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0') {
		i++;
	}	
};
