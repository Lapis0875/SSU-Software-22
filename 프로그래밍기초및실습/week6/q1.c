#include <stdio.h>
#include <limits.h>

int main(void)
{
	printf("CHAR : MIN=%d, MAX=%d\n", CHAR_MIN, CHAR_MAX);
	printf("SIGNED CHAR : MIN = %d, MAX = %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("USI~ CHAR : MAX = %d\n", UCHAR_MAX);
	printf("SHORT : MIN = %d, MAX = %d\n", SHRT_MIN, SHRT_MAX);
	printf("U~ SHORT : MAX = %d\n", USHRT_MAX);
	printf("INT : MIN = %d, MAX = %d\n", INT_MIN, INT_MAX);
	printf("U~INT : MAX = %u\n", UINT_MAX);
	printf("LONG : MIN = %ld, MAX = %ld\n", LONG_MIN, LONG_MAX);
	printf("U~LONG : MAX = %lu\n", ULONG_MAX);
	printf("LONG LONG : MIN = %lld, MAX = %lld\n", LLONG_MIN, LLONG_MAX);
	printf("U~L~L : MAX = %llu\n", ULLONG_MAX);
}
