#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main(void) {
	/* Shifted over by 1 bit should be =*/
	char x = 'z';	
	x = (x >> 1);
	printf("%c\n", x);

	char newX = getbits(x, 6, 7);

	printf("%c\n", newX);

}

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n) {
	/* (p+1-n) moves the desired field to the right end of the word */
	/* ~(~0 << n) creates a mask saying "only preserve n amount of starting digits" */
	/* Together using &, it is saying shift over n positions until the deisred starting position p is reached, then combine that with the mask to only preserve the desired amount of digits starting p */
	
	return (x >> (p+1-n)) & ~(~0 << n);
}
