#include <stdio.h>
#include <string.h>

int is_palindrome(char word[]);

int main(void)
{
    char a[20] = "Soongsil";
    char b[20] = "toot";
    char c[20] = "tomato";
    char d[20] = "otto";
    printf("%s is %s\n", a, is_palindrome(a) ? "palindrome" : "not palindrome");
    printf("%s is %s\n", b, is_palindrome(b) ? "palindrome" : "not palindrome");
    printf("%s is %s\n", c, is_palindrome(c) ? "palindrome" : "not palindrome");
    printf("%s is %s\n", d, is_palindrome(d) ? "palindrome" : "not palindrome");
    return 0;
}

int is_palindrome(char word[])
{
    int length = strlen(word);
    for (int i = 0; i < length/2 + 1; i++)
    {
        if (word[i] != word[length-i-1])
            return 0;
    }
    return 1;
}