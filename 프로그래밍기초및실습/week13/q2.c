#include <stdio.h>

void set_to_zero(int a[], int size);

int main(void)
{
    return 0;
}

void set_to_zero(int a[], int size)
{
    for (int i = 0; i < size; i ++)
        a[i] = 0;
}