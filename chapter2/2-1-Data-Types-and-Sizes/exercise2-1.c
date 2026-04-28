#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
// Printing ranges using standard macros from limits.h
    
	printf("Ranges for signed types:\n");
	printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
	printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("int: %d to %d\n", INT_MIN, INT_MAX);
	printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
	
	// Printing ranges for unsigned types
    	printf("\nRanges for unsigned types:\n");
    	printf("unsigned char: 0 to %u\n", UCHAR_MAX);
    	printf("unsigned short: 0 to %u\n", USHRT_MAX);
    	printf("unsigned int: 0 to %u\n", UINT_MAX);
    	printf("unsigned long: 0 to %lu\n", ULONG_MAX);

    	// Printing ranges for floating point types (from float.h)
   	 printf("\nRanges for floating point types:\n");
    	printf("float: %e to %e\n", FLT_MIN, FLT_MAX);
    	printf("double: %e to %e\n", DBL_MIN, DBL_MAX);
    	printf("long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);

    	return 0;
}
