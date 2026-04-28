#include <stdio.h>

unsigned testInvert(unsigned x);
unsigned invert(unsigned x, int p, int n);

int main(void) {
	char fullInvert = testInvert('M');
	/* The inverse of M is 2 */
	printf("full invert: %c\n", fullInvert);

	char partialInvert = invert('A', 0, 2);
	/* Inverting the first to bits of A (01000010) to B (01000001) */
	printf("partial invert: %c\n", partialInvert);

}

unsigned testInvert(unsigned x) {
	/* (x ^ (~0) XOR's (^) x with bits that are all 1s (~0), this results in inverting x */
	/* The & 127 is limiting the length of the result of the XOR to 7 bits, which is how long an ASCII value should be*/
	return (x ^ (~0)) & 127;
}

unsigned invert(unsigned x, int p, int n) {
	return (x ^ ((~(~0 << n)) << p));
}
