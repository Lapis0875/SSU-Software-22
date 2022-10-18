#include <stdio.h>

int main(void)
{
    int a = 1, b = 2, c = 3;
    printf("%3d%3d%3d\n", a, b, c);     //  1  2  3
    {
        int b = 4;
        int c = 5;
        printf("%3d%3d%3d\n", a, b, c);     // 1  4  5
        a = b;
        {
            int c = 6;
            c = b;
            printf("%3d%3d%3d\n", a, b, c);     //  4  4  4
        }
        printf("%3d%3d%3d\n", a, b, c);     //  4  4  5
        {
            printf("%3d%3d%3d\n", a, b, c);     //  4  4  5
        }
        printf("%3d%3d%3d\n", a, b, c);         //  4  4  5
    }
    printf("%3d%3d%3d\n", a, b, c);         //  4  2  3
    return 0;
}