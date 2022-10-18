#include <stdio.h>
#define PRN_3(x, y, z) (printf(#x" : %.1f, "#y" : %.1f, "#z" : %.1f\n", x, y, z))

int main(void)
{
    float x = 1.1, y = 2.2, z = 3.3;
    PRN_3(x, y, z);
    return 0;
}
