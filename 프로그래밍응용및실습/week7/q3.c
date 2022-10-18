#include <stdio.h>
#define PI 3.14
#define AREA(r) ((r) * (r) * PI)
float area_f(float r) { return r * r * PI; }

int main(void)
{
    float a;
    int i = 1;
    printf("By macro\nr area\n");

    while (i <= 10) {
        printf("%d : ", i);
        // AREA(i++)로 할 시, i는 1, 3, 5, 7, 9로 한번의 AREA 호출당 i가 2씩 증가하게된다.
        // 매크로의 경우 문장을 대치하므로, i++이 2번씩 평가되기 때문이다.
        a = AREA(i);
        printf("%.2f\n", a);
        i++;
    }

    i = 1;
    printf("By inline function\nr area\n");

    while (i <= 10) {
        printf("%d : ", i);
        a = area_f(i++);
        printf("%.2f\n", a);
    }

    return 0;
}