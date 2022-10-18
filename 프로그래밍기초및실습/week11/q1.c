#include <stdio.h>

int power(int n, int m); // n^m

int main(void)
{
    for(int i = 1; i <= 20; i++)
        printf("2^%d = %d\n", i, power(2, i));
    return 0;
}

int power(int n, int m) // n^m
{
    int i;
    int pow = 1;
    for (i = 0; i < m; ++i)
        pow *= n;
    return pow;
}