#include <stdio.h>

int main(void)
{
    int a = -1;
    int result = scanf("hello %d", &a);
    printf("scanned %d, scanf result %d\n", a, result);
    return 0;
}