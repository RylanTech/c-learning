#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main(void) {
	int x = 'a';
	x = rightrot(x, 5);

	printf("%s", x);
}

unsigned rightrot(unsigned x, int n) {
	return x >> n;
}
