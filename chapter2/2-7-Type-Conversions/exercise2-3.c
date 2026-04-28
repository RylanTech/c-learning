/* This program converts hexadecimal input to integer output */
#include <stdio.h>

int convertHexToInt(char);
int getString(char[]);

int main(void) {
	int arrayLength;
	int totalValue = 0, converted;
	char inputArray[25];

	/* Get the input */
	arrayLength = getString(inputArray);
	
	/* Loop through each Hexadecimal digit */	
	for (int i = 0; i < arrayLength; i++) {
		
		/* Convert the input */
		converted = convertHexToInt(inputArray[i]);

		/* Take the previous digit, multiply it by 16 because it was an order hight than this itteration, and add this itteration's conversion */
		totalValue = (totalValue * 16) + converted;
	}
	
	/* if the input was hexidecimal, give it's output */
	printf("Hex value: %d\n", totalValue);
	return 0;
}

int convertHexToInt(char input) {
	
	if (input >= 0 && input <= 9) {
		/* Do nothing, the input is already 1 to 1 with hexadecimal */
	}
	else if (input >= '0' && input <= '9') {
		input = input - '0';	
	}
	else if (input >= 'a' && input <= 'f') {
		input = input - 'a' + 10;
	}
	else if (input >= 'A' && input <= 'F') {
		input = input - 'A' + 10;
	}
		
	return input;
}


int getString(char inputString[]) {
	int c, i;

	/* While there is input and the user has not ctrl-D'd */
	while ((c = getchar()) != EOF && c != '\n' && c != ' ' && c != '\0') {
		if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
			inputString[i] = c;
		}
		i++;
	}
	return i;
}
