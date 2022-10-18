#include <stdio.h>

void f(int a[3]);

int main(void)
{
    char s[] = "I like C.";
    char *p = "I like C.";
    int a[3];
    double d[5];
    printf("%d %d %d %d\n", sizeof(s), sizeof(p), sizeof(a), sizeof(d));    // char[10] = 1x10, char* = 8, int[3] = 4x3, double[5] = 8x5
    f(a);
    return 0;
}

void f(int a[3])
{
    printf("f():sizeof(a) = %ld\n", sizeof(a));         // 매개변수 a는 배열의 상수 포인터이다. 64비트 운영체제에서 포인터의 크기는 8이다.
}