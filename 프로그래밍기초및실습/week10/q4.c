#include <stdio.h>

float my_cal(float a, char operator, float b);

int main(void)
{
	float a, b;
	char operator;
	printf("수식을 입력하세요 : ");
	scanf("%f %c %f", &a, &operator, &b);
	printf("결과값은 %.2f 입니다.\n", my_cal(a, operator, b));
	return 0;
}

float my_cal(float a, char operator, float b)
{
	switch (operator)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
}
