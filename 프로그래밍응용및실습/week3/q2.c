#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += atoi(argv[i]);
    }
    printf("평균은 %.0lf입니다.\n", sum / 3.0);
    return 0;
}
