#include <stdio.h>

#define	MAXLINE	1000

void reverseLine(char inputLine[], char outputLine[]);
int getlinev2(char inputString[], int limit);

int main(void) {
	char line[MAXLINE];
	char reversedLine[MAXLINE];

	while ((getlinev2(line, MAXLINE)) != EOF) {
		reverseLine(line, reversedLine);
		printf("%s", reversedLine);
	}
	return 0;
}

void reverseLine(char inputLine[], char outputLine[]) {
	int inputLineLength = 0;
	
	while (inputLine[inputLineLength] != '\n') {
		inputLineLength++;
	}
	
	/* line reversing */
	for (int i = inputLineLength; i > 0; i--) {
		if (inputLine[i-1] != '\0') {
			outputLine[inputLineLength - i] = inputLine[i - 1];
		}
	}
	outputLine[inputLineLength] = '\n';
	outputLine[inputLineLength + 1] = '\0';
}

/* getline: read a line into s, return length*/
int getlinev2(char s[], int lim) {
        int c, i;

        for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
                s[i] = c;
        }
        if (c == '\n') {
                s[i] = c;
                i++;
        }
        s[i] = '\0';
        return i;
}
