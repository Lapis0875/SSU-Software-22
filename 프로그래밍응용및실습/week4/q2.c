#include <stdio.h>
#include <time.h>

struct tm* get_tomorrow();
void print_day(struct tm*);

int main(void)
{
    struct tm *t = get_tomorrow();
    print_day(t);
    return 0;
}

struct tm* get_tomorrow()
{
    static int ONE_DAY = 60 * 60 * 24;      // 하루에 해당하는 초. static 변수로 선언해 함수 선언단계에 초기화 후 함수 내부적으로 계속 사용한다.
    time_t tomorrow = time(NULL) + ONE_DAY;
    return localtime(&tomorrow);
}

void print_day(struct tm* tomorrow)
{
    static char* days[7] = {"일", "월", "화", "수", "목", "금", "토"};      // 요일 출력을 위한 배열. static 변수로 선언함.
    printf("내일은 %d년 %d월 %d일 %s요일입니다.\n", tomorrow->tm_year+1900, tomorrow->tm_mon+1, tomorrow->tm_mday, days[tomorrow->tm_wday]);
}
