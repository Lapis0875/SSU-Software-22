#include <stdio.h>

int main(void)
{
    char *p[3][2] = {"abc", "defg", "hi", "jklmno", "pqrstuvw", "xyz"};
    printf("%c\n", *(*(*p)+2));   // c
    printf("%c\n", *(*(*(p+1)+1)+2));   // l
    printf("%s\n", *(*(p+2)));   // pqrstuvw
    printf("%s\n", *(*(p+1)+1)+2);   // lmno
    return 0;
}
