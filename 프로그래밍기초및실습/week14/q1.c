#include <stdio.h>
#define NULL_CHAR '\0'

void my_strcat(char a[], char b[]);

int main(void)
{
    char a[20] = "Soongsil";
    char b[20] = "university";
    my_strcat(a, b);
    printf("%s\n", a);
    return 0;
}

void my_strcat(char a[], char b[])
{
    char c;
    int last_index = 0;
    while ((c = a[last_index]) != NULL_CHAR)
    {
        last_index++;
    }
    int i = 0;
    while ((c = b[i]) != NULL_CHAR)
    {
        a[last_index + i] = b[i];
        i++;
    }
}