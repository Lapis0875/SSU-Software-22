#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{	
	int n = 1;
	srand(time(NULL));
	while (n <= 10)
	{
		printf("rand %d = %d\n", n, rand());
		n++;
	}
	return 0;
}
