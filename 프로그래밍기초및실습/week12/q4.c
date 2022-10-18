#include <stdio.h>

unsigned long long power_of_2(int n);
double power_of_2d(int n);

int main(void)
{
    for (int i = 0; i <= 10; i++)
        printf("2^%d = %llu\n", i, power_of_2(i));
    // printf("2^4 = %llu\n", power_of_2(4));
    printf("2^(-4) = %llu / %lf\n", power_of_2(-4), power_of_2d(-4));
    return 0;
}

unsigned long long power_of_2(int n)        // unsigned long long이므로, 2^-1 같은 경우는 모두 0임.
{
    unsigned long long res = 1;
    if (n > 0)
    {
        res *= 2 * power_of_2(n-1);
    }
    else if (n == 0) return res;
    else return 0;
}

double power_of_2d(int n)
{
    double res = 1;
    if (n >= 0)
    {
        for(int i = 0; i < n; i++)
        {
            res *= 2;
        }
    }
    else    // 2^-1 같이 지수가 음수일 경우 구현.
    {
        for (int i = 0; i > n; i--)
        {
            res /= 2;
        }
    }
    return res;
}