#include <stdio.h>

int QUESTION_POINTER = 0x600;
int convert_answer(int, int);

int main(void)
{
    int ary[5] = {10, 15, 20, 25, 30}; // &ary[0] = 0x600
    int *ap = ary;

    printf("&ary[0] = %p = 0x600\n===\n", ap);

    printf("1. &ary[2] : %p (%p)\n", convert_answer(&ary[2], ary));
    printf("2. &ap[3] : %p (%p)\n", convert_answer(&ap[3], ary));
    printf("3. ap+2 : %p (%p)\n", convert_answer(ap+2, ary));
    printf("4. *ap : %d\n", *ap);
    printf("5. ap[3]+1 : %d\n", ap[3]+1);
    printf("6. ary+2 : %p (%p)\n", convert_answer(ary+2, ary));
    printf("*7. *ary+2 : %d\n", *ary+2);
    printf("8. &ary[0]+2 : %p (%p)\n", convert_answer(&ary[0]+2, ary));
    printf("9. &*ary+2 : %p (%p)\n", convert_answer(&*ary+2, ary));
    printf("10. &*(ary+2) : %p (%p)\n", convert_answer(&*(ary+2), ary));
    return 0;
}

int convert_answer(int pointer, int origin)
{
    printf("raw value : %p\n", pointer);
    return pointer - origin + QUESTION_POINTER;
}