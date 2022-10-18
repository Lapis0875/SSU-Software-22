#include <stdio.h>
#include <float.h>

int main(void)
{
	printf("FLT : MIN = %g, MAX = %g, DIG=%d\n", FLT_MIN, FLT_MAX, FLT_DIG);
	printf("DBL : MIN=%g, MAX=%g, DIG=%d\n", DBL_MIN, DBL_MAX, DBL_DIG);
	printf("LDBL : MI%Lg, MAX=%Lg, DIG=%d\n", LDBL_MIN, LDBL_MAX, LDBL_DIG);
}
