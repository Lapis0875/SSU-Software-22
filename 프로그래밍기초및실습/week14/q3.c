#include <stdio.h>
#include <string.h>

int my_strsearch(char a[], char b[]);

int main(void)
{
    char a[20] = "cat lion tiger";
    char b[20] = "tiger";
    char c[20] = "lion";
    char d[20] = "cat";
    printf("%s 안에 %s : %d\n", a, b, my_strsearch(a, b));
    printf("%s 안에 %s : %d\n", a, c, my_strsearch(a, c));
    printf("%s 안에 %s : %d\n", a, d, my_strsearch(a, d));
    return 0;
}

int my_strsearch(char a[], char b[])
{
    int index = -1;
    int b_i = 0;
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] == b[b_i])
        {
            if (index == -1)
            {
                // 현재 인덱스 기록
                index = i;
            }
            b_i++;
            if (b_i == strlen(b))
                return index;
        }
        else
        {
            if (index != -1)
            {
                // 이 부분은 일치하는 문자열이 아님. 뒤부터 새로 탐색 시작.
                index = -1;
                b_i = 0;
            }
        }
    }
    return index;
}