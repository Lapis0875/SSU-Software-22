#include <stdio.h>
#include <stdlib.h>

int main(void)
{	
	int n = 1;
	while (n <= 10)
	{
		printf("rand %d = %d\n", n, rand());
		n++;
	}
	return 0;
}
