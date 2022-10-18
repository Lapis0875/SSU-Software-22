#include <stdio.h>

int is_prime(int n);

int main(void)
{
	int n;
	printf("소수인지 확인할 수 입력: ");
	scanf("%d", &n);
	printf("%d는 %s니다.\n", n, is_prime(n) ? "소수입" : "소수가 아닙");
	return 0;
}

int is_prime(int n)
{
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}
