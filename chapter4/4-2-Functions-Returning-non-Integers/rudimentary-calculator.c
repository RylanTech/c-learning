#include <stdio.h>
#include <stdlib.h> // Includes getline and atof
#include <string.h>

int main() {
	double sum = 0.0;

	char *line = NULL; // Creates a null pointer called "line"
	
	size_t len = 0;

	while (getline(&line, &len, stdin) > 0) {
		printf("\t%g\n", sum += atof(line));
	}

	return 0;
}
