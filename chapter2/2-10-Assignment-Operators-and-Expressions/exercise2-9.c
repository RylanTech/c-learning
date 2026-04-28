#include <stdio.h>

int bitcount(unsigned x);

int main(void) {
	int i = bitcount(13);

	printf("%d\n", i);

}

int bitcount(unsigned x) {
	int b = 0;
	while (x != 0) {
		// The same as x = x & (x - 1)
		x &= (x - 1);  // delete rightmost 1-bit and compare it to the original
		//
		// 10101001 - 169
		// 10101010 - 170
		//
		// 01000000 - 40
		// 01000001 - 41
		//
		// Comparing a number with itself -1 will remove the last 1 in it's sequence
		b++;
	}
	return b;
}
