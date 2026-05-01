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
				// 1 is subtracted from itterationsNeeded because we will just use the ending number that the user already types in s1.
				int itterationsNeeded = s1[i+1] - s1[i-1] - 1;
				
				// Creating a starting number (integer) from the character that is used to start with. e.g. character '1' translates to integer 1
				int startingNumber = s1[i-1] - '0';

				// Itterating through the difference between the starting integer and ending integer
				for (int j = 1; j <= itterationsNeeded; j++) {
					// Add the starting integer plus the current itteration starting from 1 (0 is added from s1 directly), then add '0' to turn it into its corresponding character type
					s2[k++] = startingNumber + j + '0';
				}

				i++;
				continue;
				
			}
			else if ((s1[i-1] >= 'a' && s1[i-1] <= 'z') && (s1[i+1] >= s1[i-1]) && (s1[i+1] <= 'z')) { // This does pretty much the same thing as the version above, just adjusted for characters instead of integers
				// Gets the difference between the starting character and ending character
				int itterationsNeeded = s1[i+1] - s1[i-1] - 1;

				// Creates a starting number by subtracting the starting character 'a' to starting from the integer 0; 
				int startingNumber = s1[i-1] - 'a';
				
				// Itterate through the difference between the starting character and ending character
				for (int j = 1; j <= itterationsNeeded; j++) {
					// Add the starting character plus the current itteration from 1 (0 is added from s1 directly), then add 'a' to turn it to its corresponding character type
					s2[k++] = startingNumber + j + 'a';	
				}
				
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

