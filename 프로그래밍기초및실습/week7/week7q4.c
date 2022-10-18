#include <stdio.h>

int main(void)
{
    char ch1, ch2;
    int diff = 'a' - 'A';
    printf("알파벳 입력 : ");
    scanf("%c", &ch1);

    if (ch1 >= 'A' && ch1 <= 'Z') ch2 = ch1 + diff;  // 알파벳 대문자인 경우
    else if (ch1 >= 'a' && ch1 <= 'z') ch2 = ch1 - diff;    // 알파벳 소문자인 경우
    else printf("%c는 알파벳이 아닙니다!", ch1); ch2 = ch1;    // 알파벳이 아닌 경우
    printf("%c -> %c\n", ch1, ch2);
    return 0;
}