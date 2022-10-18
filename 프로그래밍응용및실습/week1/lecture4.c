#include <stdio.h>

/*
포인터 변수의 크기 :
- 시스템에 따라 상이함.
    - 32bit -> 4바이트
    - 64bit -> 8바이트
- sizeof 연산자로 계산
- 포인터 변수가 가리키는 타입과 관계없이 **크기가 동일**.
*/

int main(void)
{
    int i;
    int *ip = &i;
    double d;
    double *dp = &d;
    // 과거 컴파일러의 경우 sizeof가 int를 돌려줬으나, 최근 컴파일러의 경우 sizeof가 long을 돌려줌.
    printf("%ld %ld\n", sizeof(i), sizeof(ip));
    printf("%ld %ld\n", sizeof(d), sizeof(dp));
    return 0;
}
