#include <stdio.h>
#include <time.h>

int main(void)
{
    const char* days[7] = {"일", "월", "화", "수", "목", "금", "토"};
    struct tm *t;
    time_t now = time(NULL);
    t = localtime(&now);
    _Bool am = t->tm_hour > 12;
    printf("오늘은 %d년 %d월 %d일 %s요일입니다.\n현재 시간은 %s %d시 %d분 %d초입니다.\n",
     t->tm_year+1900, t->tm_mon+1, t->tm_mday, days[t->tm_wday],
     am ? "오후" : "오전", am ? t->tm_hour - 12 : t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}
