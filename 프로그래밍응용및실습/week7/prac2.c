#include <stdio.h>
#define PI 3.14
#define CIRCLE(r) ((r) * (r) * (double) PI)

double circle(int);

int main(void)
{
    int i = 5;
    printf("CIRCLE(5++) = %lf\n", CIRCLE(i++));
    i = 5;
    printf("circle(5++) = %lf\n", circle(i++));

    return 0;
}

double circle(int r)
{
    return r * r * (double) PI;
}
