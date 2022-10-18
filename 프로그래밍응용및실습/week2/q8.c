#include <stdio.h>

void cipher(char *str, int num); //str은 원본 문자열, num은 아스키 값의 변화량

int main(void)
{
    char a[] = "helloworld";
    printf("원본 : %s\n", a);
    cipher(a, 4);
    printf("대치암호 : %s\n", a);
    return 0;
}

/**
 * @brief 전달받은 문자열을 대치암호를 이용해 변환한다.
 * 
 * @param str 원본 문자열
 * @param num 아스키 값의 변화량
 */
void cipher(char *str, int num)
{
    while (*str != '\0')
    {
        char new = *str + num;
        if (new > 'z')
            new = 'a' + (new - 'z' - 1);
        *str = new;
        str++;
    }
}