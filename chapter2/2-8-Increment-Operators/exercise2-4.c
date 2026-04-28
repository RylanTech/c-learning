/* Write an alternative version of squeeze(s1,s2) that deletes each character in s1 that matches any character in the string s2. */
#include <stdio.h>

#define	MAXSTRINPUT	100

// Filter function, syntax: strcat2(input, filer, output);
void strcat2(char s1[], char s2[], char returnString[]);

int main(void) {
	
	char c;
	int i = 0;
	char inputArr[MAXSTRINPUT];
	char filterArr[MAXSTRINPUT];
	char outputArr[MAXSTRINPUT];

	printf("Please enter the input string: ");
	
	// Get the input array from the user
	while ((c = getchar()) != EOF && c != '\n' && c != '\0' && i < MAXSTRINPUT - 1) {
		inputArr[i++] = c;
	}
	inputArr[i] = '\0';

	i = 0;
	printf("\nPlease enter the that characters to filter: ");	
	// Get the filter array from the user
	while ((c = getchar()) != EOF && c != '\n' && c != '\0' && i < MAXSTRINPUT - 1) {
		filterArr[i++] = c;
	}
	filterArr[i] = '\0';

	strcat2(inputArr, filterArr, outputArr);

	printf("\nFiltered string:\n%s\n", outputArr);

	return 0;
}

void strcat2(char s1[], char s2[], char returnString[]) {

	int i = 0;
	int k = 0;
	while (s1[i] != '\0') {
		int j = 0;
		int matchFound = 0;

		while (s2[j] != '\0' && matchFound != 1) {
			// If a match was found, set the matchfound variable.
			if (s1[i] == s2[j]) {
				matchFound = 1;
			}

			j++;
		}

		if (matchFound == 1) {
			// Do nothing an move onto the next character
		}
		else {
			returnString[k++] = s1[i];
		}
		i++;
	}

	returnString[i] = '\0';
}
