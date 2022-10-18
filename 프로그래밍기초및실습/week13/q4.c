#include <stdio.h>

void diff_array(int arr[], int first, int diff, int size);

int main(void)
{
    int array[10] = {};
    diff_array(array, 1, 7, 10);
    for (int i = 0; i < 10; i++)
        printf("%d\n", array[i]);
    return 0;
}

void diff_array(int arr[], int first, int diff, int size)
{
    int next = first;
    for (int i = 0; i < size; i++)
    {
        arr[i] = next;
        next += diff;
    }
}