#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termio.h>

int getch(void);

int main(void)
{
    system("ls");   // ls 명령어 수행

    printf("몇 초 후에 화면을 지울까요? : ");
    // 5번의 getch함수 쓰라고 풀이에서 언급하심.
    int input = getch();    // 지울 초는 한자리 숫자 (2022.10.17 실습 도중에 언급하심.)
    printf("%c\n", input);

    // ASCII 코드 상의 숫자에 대한 값을 실제 숫자 값으로 변환합니다.
    int converted = input >= '0' && input <= '9' ? input - '0' : -1;
    if (converted < 0)
    {
        printf("잘못된 시간 초 입력입니다.\n");
        return 0;
    }

    sleep(converted);   // 지정 시간초 만큼 프로그램 실행 정지.

    system("clear");    // 콘솔 지우기
    return 0;
}

/**
 * @brief 문제 5번에서 정의된 함수. getchar과는 달리 사용자의 표준 입력으로부터의 입력값을 콘솔에 보여주지 않은 채 읽어들인다.
 * 
 * @return int 사용자가 입력한 문자 값.
 */
int getch(void)
{
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