#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char inputString[]); 
void getInput(char s[]);

int main() {
	char s[100];

	itoa(250, s);

	printf("%s\n", s);

	return 0;
}

/* itoa: convert n to characters in s */
void itoa(int n, char s[]) {
	int i, sign;
	if ((sign = n) < 0) /* record sign */
		n = -n;
	/* make n positive */
	i = 0;
	do {
		/* generate digits in reverse order */
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char inputString[]) {

	// Get the length of the array
	int inputStringLength = strlen(inputString);
	
	// Store the old string
	char oldString[inputStringLength];

	// Copy the input string to oldString
	strcpy(oldString, inputString);

	/* String reversing */
	for (int i = inputStringLength; i > 0; i--) {
		if (inputString[i-1] != '\0') {
			inputString[inputStringLength-i] = oldString[i-1];
		} else {
			break;
		}
	}
	inputString[inputStringLength] = '\0';
}
