#include <stdio.h>

/*
[ 가정 ]
i 주소 0x1000
j 주소 0x2000
p 주소 0x3000
q 주소 0x4000
출력 결과 쓰시오.
*/

int main(void)
{
    int i = 100, j = 200, *p = &i, **q = &p;
    *q = &j;
    printf("*p = %u, **q = %u, p = %u, *q = %u, q = %u", *p, **q, p, *q, q);
    return 0;
}