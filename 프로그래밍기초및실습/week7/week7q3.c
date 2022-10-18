#include <stdio.h>

int main(void)
{
    int n, i = 0, sum = 0;
    printf("n 값을 입력하세요 : ");
    scanf("%d", &n);

    if (n < 0) return 0;    // 음수는 받지 않습니다.

    while (i <= n)
    {
        if (i%2 == 0) sum += i;     // 짝수일 경우만 합에 더합니다.
        i++;
    }
    printf("0~%d까지의 합 : %d\n", n, sum);
    return 0;
}