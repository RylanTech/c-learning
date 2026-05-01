#include <stdio.h>

// Expand abbreviations from a-d to abcd, or 1-4 to 1234
void expand(char s1[], char s2[]);
void expandSet(char s1[], char s2[], int *s1Pos, int *s2Posi, char startingChar);
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
			if ((s1[i-1] >= '0' && s1[i-1] <= '9') && (s1[i+1] >= s1[i-1]) && (s1[i+1] <= '9')) { // For all integers
				// Calculates the needed output based off of the starting position	
				expandSet(s1, s2, &i, &k, '0');
				i++;
				continue;
			}
			else if ((s1[i-1] >= 'a' && s1[i-1] <= 'z') && (s1[i+1] >= s1[i-1]) && (s1[i+1] <= 'z')) { // For all lowercase letters
				expandSet(s1, s2, &i, &k, 'a');
				i++;
				continue;
			}	
			else if ((s1[i-1] >= 'A' && s1[i-1] <= 'Z') && (s1[i+1] >= s1[i-1]) && (s1[i+1] <= 'Z')) { // For all uppercase letters
				expandSet(s1, s2, &i, &k, 'A');
				i++;
				continue;
			}
		}

		// If the current character is not '-', add it to the output string
		s2[k++] = s1[i++];
	}
	
	// Add a string termination character to the output string
	s2[k] = '\0';
}

void expandSet(char s1[], char s2[], int *s1Pos, int *s2Pos, char startingChar) {
	// Gets the difference between the starting character and ending character 
	int itterationsNeeded = s1[(*s1Pos)+1] - s1[(*s1Pos)-1] - 1;

	// Creates a starting number by subtracting the starting character to starting from the integer 0; 
	int startingNumber = s1[(*s1Pos)-1] - startingChar;

	// Itterate through the difference between the starting character and ending character
	for (int j = 1; j <= itterationsNeeded; j++) {
		// Add the starting character plus the current itteration from 1 (0 is added from s1 directly), then add the starting point to turn it to its corresponding character type	
		s2[(*s2Pos)++] = startingNumber + j + startingChar;	
	}
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

