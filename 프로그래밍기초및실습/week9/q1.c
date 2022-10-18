#include <stdio.h>

int main(void)
{
	int n;
	printf("출력할 단을 입력하시오 : ");
	scanf("%d", &n);
	for (; n < 10; n++)
	{
		for (int i = 1; i < 10; i++)
		{
			printf("%d * %d = %d\n", n, i, n * i);
		}
	}	
	return 0;
}
