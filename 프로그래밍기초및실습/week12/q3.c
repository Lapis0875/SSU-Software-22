#include <stdio.h>

int r_sum(int num);

int main(void)
{
    printf("1~5 합 : %d\n", r_sum(5));
    return 0;
}

int r_sum(int num)
{
    if (num == 1)
        return num;
    return num + r_sum(num - 1);
}