#include <stdio.h>
#define PRINT_INT(x) printf(#x" = %d\n", x)

int main(void)
{
    int i;
    printf("i 값 입력 : ");
    scanf("%d", &i);
    PRINT_INT(i);
    return 0;
}
