#include <stdio.h>
#include <termio.h>

int getch(void) {
    int ch;
    struct termios buf;
    struct termios save;

    tcgetattr(0, &save);
    buf = save;

    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);

    ch=getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}

int main(void)
{
    const char a = 'a';
    int ch;
    
    printf("%c\n", a);
    ch = getch();
    // 성능 상의 이유로, printf 뒤에 \n 문자를 붙이지 않으면 바로 출력하지 않을 수 있음 (버퍼링 등에 의해)
    // 따라서, \n을 사용해 ch를 바로 출력시킴.
    printf("%c\n", ch);

    if (ch == a)
        printf("GOOD\n");
    else
        printf("BAD\n");
    return 0;
}
