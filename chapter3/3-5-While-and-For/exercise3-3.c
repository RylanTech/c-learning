#include <stdio.h>

// Expand abbreviations from a-d to abcd, or 1-4 to 1234
void expand(char s1[], char s2[]);
int getString(char inputString[]);

#define	MAXARRAYSIZE	100

int main() {
	
	int c;	
	char s1[MAXARRAYSIZE];
	char s2[MAXARRAYSIZE];

	getString(s1);
	expand(s1, s2);

	printf("%s\n", s2);

	return 0;
}

void expand(char s1[], char s2[]) {
	int i = 0;
	int k = 0;
	
	// Loop through the string's characters
	while (s1[i] != '\0') {
		
		// If there is a dash...
		if (s1[i] == '-' && i != 0 && s1[i+1] != '\0') {			
			
			// Imagine 'a' through 'b' where the domain is 0-9.
			// If 'a' is greater than 0, but less than or equal to 9, and 'b' is greater than 'a' but less than or equal to 9
			// This accounts for all integers
			if ((s1[i-1] >= '0' && s1[i-1] <= '9') && (s1[i+1] >= s1[i-1]) && (s1[i+1] <= '9')) {
				int itterationsNeeded = s1[i+1] - s1[i-1];
				int startingNumber = s1[i-1] - '0';

				for (int j = 1; j <= itterationsNeeded - 1; j++) {
					s2[k++] = startingNumber + j + '0';	
				}

				i++;
				continue;
				
			}

		}
		s2[k++] = s1[i++];
	}
	
	s2[k] = '\0';
}

int getString(char inputString[]) {
	int c, i = 0;
	
	/* While there is input and the user has not ctrl-D'd */
	while ((c = getchar()) != EOF && c != '\n') {
		inputString[i] = c;
		i++;
	}

	inputString[i] = '\0';

	return i;
}

