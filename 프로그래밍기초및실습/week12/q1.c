#include <stdio.h>
#include <time.h>

int fibonacci_recursive(int n);
int fibonacci_loop(int n);
unsigned int rcalls = 0;

int main(void)
{
    clock_t lstart = clock();
    int lres = fibonacci_loop(44);
    clock_t lend = clock();
    printf("반복문으로 구한 피보나치 수열 44번째 항 : %d, 소요시간 %ld\n", lres, lend - lstart);

    clock_t rstart = clock();
    int rres = fibonacci_recursive(44);
    clock_t rend = clock();
    printf("재귀적으로 구한 피보나치 수열 44번째 항 : %d, 소요시간 : %ld, 호출횟수 %u\n", rres, rend - rstart, rcalls);

    printf("두 방식의 결과값 일치? %s\n", rres == lres ? "true" : "false");
    return 0;
}

int fibonacci_recursive(int n)
{
    rcalls++;
    if (n < 2)
        return n;
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int fibonacci_loop(int n)
{
    if (n < 2)
        return n;
    int nm2 = 0, nm1 = 1;   // n-2번째 항, n-1번째 항
    int res = 1;            // 현재 항 값
    for (int i = 2; i < n; i++)
    {
        nm2 = nm1;
        nm1 = res;
        res = nm2 + nm1;
    }
    return res;
}