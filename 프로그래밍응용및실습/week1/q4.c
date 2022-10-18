#include <stdio.h>

int main() {
    double d;
    double *dp;
    printf("%lu\n", sizeof(d));         // double형이라 8바이트.
    printf("%lu\n", sizeof(dp));        // 포인터 변수의 메모리 크기는 8바이트 (64bit 기준)
    return 0;
}