#include <stdio.h>

double power(int n, int m); // n^m

int main(void)
{
    for(int i = -1; i >= -10; i--)
        printf("2^%d = %lf\n", i, power(2, i));
    return 0;
}

double power(int n, int m) // n^m
{
    int i;
    double pow = 1.0;
    if (m >= 0)
        for (i = 0; i < m; ++i)
            pow *= n;
    else
        for(int i = 0; i > m; --i)
            pow /= n;
    return pow;
}