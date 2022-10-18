#include <stdio.h>
/*
변수 a, b를 사용하지 않고 a와 b의 값을 바꾸는 코드 작성. (변수 c, p, q 사용.)
*/

int main(void)
{
    int a = 5, b = 10, c;
    int *p, *q;

    p=&a;
    q=&b;
    
    // 추가코드
    c = *p;
    *p = *q;
    *q = c;
    
    printf("%d %d", a, b);
    return 0;
}