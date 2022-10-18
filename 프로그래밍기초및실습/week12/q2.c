#include <stdio.h>

void re_bin_num(int n);

int main(void)
{
    int n;
    printf("음이 아닌 정수의 십진 값을 입력해주세요: ");
    scanf("%d", &n);
    printf("%d의 출력 결과 : ", n);
    re_bin_num(n);
    printf("\n");
    return 0;
}

void re_bin_num(int n)
{
    int mok = n / 2;
    int res = n % 2;

    if (mok > 0)
    {
        re_bin_num(mok);
    }
    else
        printf("%d", mok);
    printf("%2d", res);
}