#include <stdio.h>

void my_print(char c, int count);

int main(void)
{
	my_print('*', 1);
	my_print('#', 5);
	my_print('@', 7);
	return 0;
}

void my_print(char c, int count)
{
	for (int i = 0; i < count; i++)
		printf("%c", c);
	printf("\n");
}
