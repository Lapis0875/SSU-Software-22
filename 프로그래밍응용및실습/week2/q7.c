#include <stdio.h>

void print_string(char*);

int main(void)
{
    char *fruit = "strawberry";
    print_string(fruit);
    return 0;
}

void print_string(char *text)
{
    int i = 1;
    while (*text != '\0')
    {
        if (i % 2 == 1)
            printf("%c", *text);
        text++;
        i++;
    }
    printf("\n");
}
