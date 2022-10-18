#include <stdio.h>

int main(void)
{
    int value1 = -1, value2 = -1;
    char a = 0xff;
    signed char b = 0xff;
    unsigned char c = 0xff;
    value1 = a == b;
    value2 = a == c;
    printf("char = signed char? : %d\nchar = unsigned char? : %d\n", value1, value2);
    return 0;
}