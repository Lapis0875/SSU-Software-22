#include <stdio.h>

/*
출력값을 쓰고 이유 설명.
*/

int main(void)
{
    int *p=(int*)0x100;
    double *q=(double*)0x100;
    char *r=(char*)0x100;

    printf("%p %p %p", p+3, q+3, r+3);
    // p+3 : int형으로 3칸 : 12칸 이동 -> 0x10c
    // q+3 : double형으로 3칸 : 24칸 이동 -> 0x118
    // r+3 : char형으로 3칸 : 3칸 이동 -> 0x103
    return 0;
}