#include <stdio.h>

int main(void)
{
	int count, das, single;
	printf("연필 개수를 입력하세요 : ");
	scanf("%d", &count);
	printf("연필 %d자루는 %d다스, %d자루입니다.\n", count, count / 12, count % 12);
	return 0;
}

