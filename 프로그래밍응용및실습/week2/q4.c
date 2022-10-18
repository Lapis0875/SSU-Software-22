#include <stdio.h>

int QUESTION_A = 0x1000;
int QUESTION_P = 0x2000;
int QUESTION_Q = 0x3000;
int QUESTION_R = 0x4000;

int convert(int, int, int);

int main(void)
{
    int a = 100, *p = &a, **q = &p, ***r = &q;
    printf("a = %p : %p\n", QUESTION_A, &a);
    printf("p = %p : %p\n", QUESTION_P, &p);
    printf("q = %p : %p\n", QUESTION_Q, &q);
    printf("r = %p : %p\n\n", QUESTION_R, &r);
    printf("%p %p %p %p %p\n", &a+1, p+1, q+1, r+1, *r+1);

    printf("&a+1 = %p (%p)\n", convert(&a+1, &a, QUESTION_A), &a+1);
    printf("p+1 = %p (%p)\n", convert(p+1, &a, QUESTION_A), p+1);
    printf("q+1 = %p (%p)\n", convert(q+1, &p, QUESTION_P), q+1);
    printf("r+1 = %p (%p)\n", convert(r+1, &q, QUESTION_Q), r+1);
    printf("*r+1 = %p (%p)\n", convert(*r+1, &p, QUESTION_P), *r+1);
    return 0;
}

int convert(int p, int origin, int base)
{
    return p - origin + base; 
}