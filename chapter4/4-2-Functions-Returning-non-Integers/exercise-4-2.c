// Extend atof to handle scientific notation
// Note: This only works when the power is a positive or negitive integer
#include <stdio.h>
#include <stdlib.h> // Includes getline and atof
#include <string.h>
#include <ctype.h> // Includes isspace
#include <math.h> // Includes pow

double sciNotationAtof(char s[]);

int main() {
	double sum = 0.0;

	char *line = NULL; // Creates a null pointer called "line"
	
	size_t len = 0;

	while (getline(&line, &len, stdin) > 0) {
		printf("\t%g\n", sum += sciNotationAtof(line));
	}

	return 0;
}

double sciNotationAtof(char s[]) {
	double val;
	double divisionPower = 1.0;
	double powerVal = 1;
	int i, sign;

	// Handling the integer part
	for (i = 0; isspace(s[i]); i++) {
		// Remove whitespaces
	}
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-') { // Move past the index the sign value
		i++;
	}
	for (val = 0.0; isdigit(s[i]); i++) { // Convert the string into a double until the decimal is reached 
		val = 10.0 * val + (s[i] - '0');
	}

	// Handling the decimal part
	if (s[i] == '.') { // If the current index is a decimal, then move past it and handle the decimal logic
		i++;
		
		for (divisionPower = 1.0; isdigit(s[i]); i++) { // Add the decimal's number to the total value in the 1s place, then increase the power by a magnitude
			val = 10.0 * val + (s[i] - '0');
			divisionPower *= 10;
		}
	}
	
	// Handle the power part
	if (s[i] == '^') { // If the current index is a carrot, then move past it and handle the power logic
		powerVal = 0;
		i++;

		int powerSign = (s[i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-') { // Move past the index the sign value
			i++;
		}
		for (powerVal = 0; isdigit(s[i]); i++) { // Convert the string into an integer until the end
			// Convert the power string-integer into an integer
			powerVal = 10 * powerVal + (s[i] - '0');
			printf("e %g\n", powerVal);
		}
	}	

	double decimalValue = sign * val / divisionPower; // Return the value multiplied by the sign (either -1 or 1), then devide by the power to put the decimal back where it belongs
	
	
	double totalValueToAdd = pow(decimalValue, powerVal); // Use the pow function to raise the number to the correct power
	
	// Tracking the values:
	// printf("inputVal: %g\npowerVal %g\naddingVal: %g\n", decimalValue, powerVal, totalValueToAdd);

	// Return the total value
	return totalValueToAdd;
}
