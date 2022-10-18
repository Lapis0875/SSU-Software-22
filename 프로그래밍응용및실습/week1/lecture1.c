#include <stdio.h>

int main(void)
{
    int i, *p;
    register int v;

    p = 0;      // p = NULL; #define NULL 0 처럼 정의되어있음.
    p = &i;
    p = 3000;   // 컴파일 시 경고. 상수 값 사용.
    p = (int *) 1776;   // int형 상수를 int* 형으로 캐스트.
    p = &(i + 99);      // 컴파일 시 에러. 수식에 & 사용.
    p = &v;             // 오류, register 변수에 & 사용.    
    return 0;
}
