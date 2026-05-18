#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);

int main(void) {
	
	char resultString[64];

	itob(12345, resultString, 2);
	printf("%s\n", resultString);
	
	itob(255, resultString, 16);
	printf("%s\n", resultString);

	return 0;
}

void itob(int n, char s[], int b) {
	if (b < 2) { // At least a base two system is required
		printf("Error, b must be equal to, or greater than 2");
		return;
	}

	if (n == 0) { // For when n equals zero, just return '0'
		s[0] = '0';
		s[1] = '\0';
		return;
	}

	int temp_n = n;
	char invertedNumString[64];
	int index = 0;
	
	// Loop until the value of temp_n is less than zero after deviding it by b so many times
	while (temp_n > 0) {
		// Get the remainder of temp_n / b
		int remainder = temp_n % b;

		char digitCharacter;

		// If the remainder is less than 10, which it will have a max value of b - 1, add the correct digit. If it is greater than or equal to 10, add the correct letter.
		if (remainder < 10) {
			digitCharacter = remainder + '0';	
		} else {
			digitCharacter = (remainder - 10) + 'A';
		}

		invertedNumString[index++] = digitCharacter;

		temp_n = temp_n / b;
	}

	invertedNumString[index] = '\0';

	int len = strlen(invertedNumString);

	// Reverse the inverted string
	for (int i = 0; i < len; i++) { 
		s[i] = invertedNumString[len - 1 - i];
	}
	s[len] = '\0';
}
