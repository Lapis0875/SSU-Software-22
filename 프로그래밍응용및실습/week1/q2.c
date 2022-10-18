#include <stdio.h>

/*
2. 다음 프로그램의 실행 결과를 쓰시오. 단, a의 주소는 0x1000, p의 주소는 0x2000이라고 가정한다.
답 : 0x1000, 10, 10, 0x1000, 10
*/

int main(void) {

    unsigned int a = 10, *p;
    p = &a;
    printf("0x1000 = %p\n\n", &a);
    printf("%p\n", p);
    printf("%u\n", *p);
    printf("%u\n", *&a);
    printf("%p\n", *&p);
    printf("%u\n", **&p);
    return 0;

}