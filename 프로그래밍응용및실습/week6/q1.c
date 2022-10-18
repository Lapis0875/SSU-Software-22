#include <stdio.h>

void bit_print(unsigned int);

int main(void)
{
    // 1-1 : 이진수 *10011101*과 10111101의 배타적 논리합을 수행한 후의 결과를 이진수로 써라.
    unsigned int a = 0b10011101 ^ 0b10111101;
    printf("10011101 XOR 10111101 = "); bit_print(a); printf("\n");
    // 1-2 : 위 결과에서 얻은 이진수를 다시 10111101로 배타적 논리합을 수행하고 그 결과를 이진수로 써라.
    unsigned int b = a ^ 0b10111101;
    printf("a XOR 10111101 = "); bit_print(b); printf("\n");
    // 1-3 : 이진수 *11101110*과 01011101의 배타적 논리합을 수행한 후의 결과를 이진수로 써라.
    unsigned int c = 0b11101110 ^ 0b01011101;
    printf("11101110 XOR 01011101 = "); bit_print(c); printf("\n");
    // 1-4 : 위 결과에서 얻은 이진수를 다시 01011101로 배타적 논리합을 수행하고 그 결과를 이진수로 써라.
    unsigned int d = c ^ 0b01011101;
    printf("c XOR 01011101 = "); bit_print(d); printf("\n");
    // 1-5 : 1-2와 1-4에서 얻은 결과를 1-1의 10011101과 1-3의 11101110과 비교해 보아라. 이 사실을 통해 알 수 있는 것은?
    printf("1-2 : "); bit_print(b); printf(" == 10011101\n");
    printf("1-4 : "); bit_print(d); printf(" == 11101110\n");
    return 0;
}

void bit_print(unsigned int bits) {
    int i;
    unsigned int n = 8;
    unsigned int mask = 1 << (n-1);
    for (i = 1; i <= n; ++i) {
        // printf("bit_print(%d).%d = %d\n", bits, i, bits & mask);
        putchar(((bits & mask) == 0) ? '0' : '1');
        bits <<= 1;
        if (i % 8 == 0 && i < n)
            putchar(' ');
    }
}