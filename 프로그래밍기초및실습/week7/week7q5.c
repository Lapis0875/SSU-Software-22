#include <stdio.h>

int main(void)
{
    int i;
    printf("3자리 정수를 입력하세요 : ");
    scanf("%d", &i);

    printf("백의 자리 숫자 : %d\n", i / 100);
    printf("일의 자리 숫자 : %d\n", i % 10);
    return 0;
}