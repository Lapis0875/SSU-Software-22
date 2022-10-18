#include <stdio.h>

void divisor(int n);

int main(void)
{
	divisor(10);
	return 0;
}

void divisor(int n)
{
	for (int i = 1; i < n; i++)
		if (n % i == 0)
			printf("%d, ", i);
	printf("%d\n", n);
}
