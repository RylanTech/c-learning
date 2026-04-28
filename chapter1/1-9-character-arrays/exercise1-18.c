#include <stdio.h>

#define	MAXLINE	1000
#define	MAXNUMOFLINES	20

int getlinev2(char s[], int lim);
void copy(char to[], char from[]);

int main(void) {
	int len;
	char line[MAXLINE];
	int currentIndex;
	char overLines[MAXNUMOFLINES][MAXLINE];
	
	currentIndex = 0;
	while ((len = getlinev2(line, MAXLINE)) > 0) {
		copy(overLines[currentIndex], line);
		currentIndex++;	
	}

	if (currentIndex > 0) {
		for (int i = 0; i < currentIndex; i++) {
			printf("%s\n", overLines[i]);
		}
	}
	return 0;
}


int getlinev2(char s[], int lim) {
	int c, i;
	int prevBlank = 0;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		if (prevBlank == 1 && (c == ' ' || c == '\t')) {
			/* Do nothing */
		} 
		else if (c == ' ' || c == '\t') {
			prevBlank = 1;
			s[i] = ' ';
		} else {
			prevBlank = 0;
			s[i] = c;
		}
	}
	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
        return i;
}

void copy(char to[], char from[]) {
        int i;

        i = 0;
        while ((to[i] = from[i]) != '\0') {
                i++;
        }
};
