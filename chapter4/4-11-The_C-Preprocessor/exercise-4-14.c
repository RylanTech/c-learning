#include <stdio.h>

#define swap(t, x, y) ((t = (x)), (x = (y)), (y = (t)))

int main(void) {
	int x, y, t;
	x = 10;
	y = 20;
	
	printf("x: %d\n y: %d\n", x, y);

	swap(t, x, y);

	printf("x: %d\n y: %d\n", x, y);

	return 0;
}
