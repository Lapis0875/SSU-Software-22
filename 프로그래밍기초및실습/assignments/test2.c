#include <stdio.h>

int main(void)
{
    signed char a, b, res;
    char op;
    _Bool retry = 0;
    do {
        printf("{a}{op}{a} 로 입력.\n예시: 5+10\n> ");
        int sr = scanf("%hhd %c %hhd", &a, &op, &b);
        printf("%d %c %d = ", a, op, b);
        switch(op)
        {
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
        }
        printf(" %d\n", res);
        retry = sr == 3;
    } while (retry);
    return 0;
}