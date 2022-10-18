#include <stdio.h>

void bin_num(int n);

int main(void)
{
    int n;
    printf("이진수로 변환할 십진 정수 입력: ");
    scanf("%d", &n);
    bin_num(n);
    return 0;
}

void bin_num(int n)
{
    printf("십진 값 %d의 출력 결과 : ", n);
    int mok = n, rest = 0;
    while (1)
    {
        mok = n / 2;
        rest = n % 2;

        printf("%d ", rest);
        if (mok < 2)
        {
            printf("%d\n", mok);
            break;
        }
        n = mok;
    }
}