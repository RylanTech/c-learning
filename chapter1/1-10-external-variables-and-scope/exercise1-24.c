#include <stdio.h>

#define	MAXCODECHARS	50000
#define MAXCODELINES	500
#define MAXCODELINECHARS	300
#define	MAXERRORS	100
#define	MAXERRORMESSAGE	2000


int getAndScanInput(char line[], char errors[][MAXERRORMESSAGE], int *numOfErrorsPtr, char codeByLine[][MAXCODELINECHARS], int *numOfLinesPtr);

int main(void) {
	
	char line[MAXCODECHARS];	
	char errors[MAXERRORS][MAXERRORMESSAGE];
	char codeByLine[MAXCODELINES][MAXCODELINECHARS];
	int numOfLines = 0;	
	int numOfErrors = 0;
	
	/* Get and scan the input */
	getAndScanInput(line, errors, &numOfErrors, codeByLine, &numOfLines);
	for (int i = 0; i < numOfErrors; i++) {
		printf("%s", errors[i]);
	}	

	return 0;
}

int getAndScanInput(char line[], char errors[][MAXERRORMESSAGE], int *numOfErrorsPtr, char codeByLine[MAXCODELINES][MAXCODELINECHARS], int *numOfLinesPtr) {
	int c;
	int i = 0;

	/* char codeByLine[MAXCODELINES][MAXCODELINECHARS]; */
	/* int lineNum = 0; */
	int lineNumChar = 0;

	int lastOpenBracketOcc = 0;
	int lastClosedBracketOcc = 0;
	int lastOpenParentheseOcc = 0;
	int lastClosedParentheseOcc = 0;
	int lastOpenSquareBracketOcc = 0;
	int lastClosedSquareBracketOcc = 0;
	int lastOpenSingleQuoteOcc = 0;
	int lastClosedSingleQuoteOcc = 0;
	int lastOpenDoubleQuoteOcc = 0;
	int lastClosedDoubleQuoteOcc = 0;
	int lastOpenCommentOcc = 0;
	int lastClosedCommentOcc = 0;

	int openBrackets = 0;
	int closedBrackets = 0;
	int openParenthese = 0;
	int closedParenthese = 0;
	int openSquareBrackets = 0;
	int closedSquareBrackets = 0;
	int openSingleQuotes = 0;
	int closedSingleQuotes = 0;
	int openDoubleQuotes = 0;
	int closedDoubleQuotes = 0;
	int openComments = 0;
	int closedComments = 0;

	int disabledState = 0;
	int ignoreNextChar = 0;

	int prevBackSlash = 0;

	while (i < MAXCODECHARS && (c = getchar()) != EOF) {
		if (disabledState == 1) {
			/* Checking for ending comments */
			if (c == '/' && line[i-1] == '*') {
				closedComments++;
				disabledState = 0;
				line[i] = c;
				codeByLine[*numOfLinesPtr][lineNumChar] = c;
				lastClosedCommentOcc = *numOfLinesPtr;
				i++;
				lineNumChar++;
				continue;
			}
		}
		else if (disabledState == 2) {
			/* If the previous line was a backslash, ignore this character */
			disabledState = 0;
			line[i] = c;
			codeByLine[*numOfLinesPtr][lineNumChar] = c;
			i++;
			lineNumChar++;
			continue;
		}
		else if (disabledState == 3 || disabledState == 4) {
			/* If there is a backslash, ignore the next character */
			if (c == '\\') {
				disabledState = 2;
				line[i] = c;
				codeByLine[*numOfLinesPtr][lineNumChar] = c;
				i++;
				lineNumChar++;
				continue;
			}

			if (disabledState == 3) {
				/* Checking for the ending single quote */
				if (c == '\'') {
					closedSingleQuotes++;
					disabledState = 0;
					line[i] = c;
					codeByLine[*numOfLinesPtr][lineNumChar] = c;
					lastClosedSingleQuoteOcc = *numOfLinesPtr;
					i++;
					lineNumChar++;
					continue;
				}
			}
			else if (disabledState == 4) {	
				/* Checking for the ending double quote */
				if (c == '"' && line[i-1] != '\'') {
					closedDoubleQuotes++;
					disabledState = 0;
					line[i] = c;
					codeByLine[*numOfLinesPtr][lineNumChar] = c;
					
					lastClosedDoubleQuoteOcc = *numOfLinesPtr;
					i++;
					lineNumChar++;
					continue;
				}
			}
		}
		else {
			/* If not in a disabled state, check if it needs to be enabled */
			if (c == '*' && line[i-1] == '/') {
				/* Checking for starting with a comment */
				openComments++;
				disabledState = 1;
				line[i] = c;
				codeByLine[*numOfLinesPtr][lineNumChar] = c;
				lastOpenCommentOcc = *numOfLinesPtr;
				i++;
				lineNumChar++;	
				continue;
			}
			else if (c == '\\') {
				ignoreNextChar = 1;
				line[i] = c;
				codeByLine[*numOfLinesPtr][lineNumChar] = c;	
				lineNumChar++;		
				i++;
				continue;
			}
			else if (c == '\'') {
				openSingleQuotes++;
				disabledState = 3;
				line[i] = c;
				codeByLine[*numOfLinesPtr][lineNumChar] = c;
				lastOpenSingleQuoteOcc = *numOfLinesPtr;
				i++;
				lineNumChar++;		
				continue;
			}
			else if (c == '"') {
				openDoubleQuotes++;
				disabledState = 4;
				line[i] = c;
				codeByLine[*numOfLinesPtr][lineNumChar] = c;
				lastOpenDoubleQuoteOcc = *numOfLinesPtr;
				i++;
				lineNumChar++;		
				continue;
			}
		}	

		line[i] = c;
		codeByLine[*numOfLinesPtr][lineNumChar] = c;
		lineNumChar++;

		if (c == '{') {
			openBrackets++;
			lastOpenBracketOcc = *numOfLinesPtr;
		}
		else if (c == '}') {
			closedBrackets++;
			lastClosedBracketOcc = *numOfLinesPtr;
		}
		else if (c == '(') {
			openParenthese++;
			lastOpenParentheseOcc = *numOfLinesPtr;
		}
		else if (c == ')') {
			closedParenthese++;
			lastClosedParentheseOcc = *numOfLinesPtr;
		}
		else if (c == '[') {
			openSquareBrackets++;
			lastOpenSquareBracketOcc = *numOfLinesPtr;
		}
		else if (c == ']') {
			closedSquareBrackets++;
			lastClosedSquareBracketOcc = *numOfLinesPtr;
		}
		else if (c == '\n') {
			(*numOfLinesPtr)++;
			lineNumChar = 0;
		}
		i++;
	}

	line[i] = '\0';
	codeByLine[*numOfLinesPtr][lineNumChar] = '\0';

	printf("Begin comments: %d\n", openComments);
	printf("Ending comments: %d\n", closedComments);
	printf("Open brackets: %d\n", openBrackets);
	printf("Closed brackets: %d\n", closedBrackets);
	printf("Open parenthese: %d\n", openParenthese);
	printf("Open parenthese: %d\n", closedParenthese);
	printf("Open square brackets: %d\n", openSquareBrackets);
	printf("Open square brackets: %d\n", closedSquareBrackets);

	if (openComments != closedComments) {
		sprintf(errors[*numOfErrorsPtr], "ERROR - Mismatched comments '/**/'\n\tLast comment opening: line %d\n\t%s\n\tLast comment closing: line %d\n\t%s\n", lastOpenCommentOcc + 1, codeByLine[lastOpenCommentOcc], lastClosedCommentOcc + 1, codeByLine[lastClosedCommentOcc]);
		(*numOfErrorsPtr)++;
	}

	if (openBrackets != closedBrackets) {
		sprintf(errors[*numOfErrorsPtr], "ERROR - Mismatched brackets '{}'\n\tLast bracket opening: line %d\n\t%s\n\tLast bracket closing: line %d\n\t%s\n", lastClosedBracketOcc + 1, codeByLine[lastOpenBracketOcc], lastClosedBracketOcc + 1, codeByLine[lastClosedBracketOcc]);
		(*numOfErrorsPtr)++;
	}	

	
	if (openParenthese != closedParenthese) {
		sprintf(errors[*numOfErrorsPtr], "ERROR - Mismatched parenthese '()'\n\tLast parenthese opening: line %d\n\t%s\n\tLast parenthese closing: line %d\n\t%s\n", lastOpenParentheseOcc + 1, codeByLine[lastOpenParentheseOcc], lastClosedParentheseOcc + 1, codeByLine[lastClosedParentheseOcc]);
		(*numOfErrorsPtr)++;
	}	

	if (openSquareBrackets != closedSquareBrackets) {
		sprintf(errors[*numOfErrorsPtr], "ERROR - Mismatched  square brackets '[]'\n\tLast square bracket opening: line %d\n\t%s\n\tLast square bracket closing: line %d\n\t%s\n", lastOpenSquareBracketOcc + 1, codeByLine[lastOpenSquareBracketOcc], lastClosedSquareBracketOcc + 1, codeByLine[lastClosedSquareBracketOcc]);
		(*numOfErrorsPtr)++;
	}	


	if (openSingleQuotes != closedSingleQuotes) {
		sprintf(errors[*numOfErrorsPtr], "ERROR - Mismatched single quotes '\"\"'\n\tLast single quote opening: line %d\n\t%s\n\tLast single quote closing: line %d\n\t%s\n", lastOpenSingleQuoteOcc + 1, codeByLine[lastOpenSingleQuoteOcc], lastClosedSingleQuoteOcc + 1, codeByLine[lastClosedSingleQuoteOcc]);
		(*numOfErrorsPtr)++;
	}


	if (openDoubleQuotes != closedDoubleQuotes) {
		sprintf(errors[*numOfErrorsPtr], "ERROR - Mismatched double quotes '\'\''\n\tLast double quote opening: line %d\n\t%s\n\tLast double quote closing: line %d\n\t%s\n", lastOpenDoubleQuoteOcc + 1, codeByLine[lastOpenDoubleQuoteOcc], lastClosedDoubleQuoteOcc + 1, codeByLine[lastClosedDoubleQuoteOcc]);
		(*numOfErrorsPtr)++;
	}

	return i;
}
