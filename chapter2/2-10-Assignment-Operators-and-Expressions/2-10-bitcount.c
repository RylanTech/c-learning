#include <stdio.h>

int bitcount(unsigned x);

int main(void) {

	int bits = bitcount(13);

	printf("%d\n", bits);
}

int bitcount(unsigned x) {
	int b;

	// Loop until x equals 0. which it will when all bits have been shifted. After each loop, shift x to the right by 1.
	for (b = 0; x != 0; x >>= 1) {
		// If x equals 1, and 01 (octal) equal 1, which it always will, increase b by 1
		if (x & 01) {
			b++;
		}
	}
	return b;
};
