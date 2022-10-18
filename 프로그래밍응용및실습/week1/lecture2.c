#include <stdio.h>

int main(void)
{
    int i = 100, *p;

    p = &i;
    printf("i 주소 : %p\n", &i);
    printf("i 값 : %d\n", i);
    printf("p 값 : %p\n", p);
    printf("*p 값 : %d\n", *p);
    *p = 200;
    printf("i = %d\n", i);
    return 0;
}
