#include <stdio.h>

int main(void)
{
    extern int a, b, c;
    printf("%3d%3d%3d\n", a, b, c);
    return 0;
}

int a = 1, b = 2, c = 3;