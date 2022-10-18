#include <stdio.h>

int main(void)
{
	int width, height;
	printf("사각형의 너비를 입력하세요 : ");
	scanf("%d", &width);
	printf("사각형의 높이를 입력하세요 : ");
	scanf("%d", &height);
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			printf("#");
		}
		printf("\n");
	}
	return 0;
}
