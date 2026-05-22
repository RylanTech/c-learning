//Exercise 4-1. Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none.

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */

int getline2(char *line, int max);
int strindex(char *source, char *searchfor);

/* find all lines matching pattern */
int main(void) {
	char line[MAXLINE];
	int found = 0;
	char pattern[] = "ould"; /* pattern to search for */
	
	while (getline2(line, MAXLINE) > 0) {
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	}
	return found;
}

/* getline: get line into s, return length */
int getline2(char *s, int lim) {
	int c, i;

	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

/* strindex: return the rightmost index of t in s, -1 if none */
int strindex(char *s, char *t) {
	int i, j, k, pm;
	int m = -1;
	int patlen = strlen(t);

	// Loop through every letter
	for (i = 0; s[i] != '\0'; i++) {
		// Does this letter match the first letter in the pattern?
		if (s[i] == t[0]) {
			pm = i;
			
			// Check for the full pattern match 
			for (k = i, j = 0; j <= patlen; k++, j++) {	
				// Compare the current string positions
				if (s[k] == t[j]) {
					// If the final letter match is true, then set this as the latest match
					
					if (j == patlen - 1) {
						m = pm;
					}
				} else {
					// If the match isn't a full match, break the for loop
					break;
				}
			}
		}
	}

	printf("last match: %d\n", m);	

	return m;
}
