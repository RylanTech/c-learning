#include <stdio.h>

/* print Fahrenheit-Celsuis table with a function */

float calculateFahrToCel(int f);

int main(void) {
	int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20) {
		printf("%3d %6.1f\n", fahr, calculateFahrToCel(fahr));
	}
}

float calculateFahrToCel(int f) {
	return (5.0/9.0)*(f-32);
}
