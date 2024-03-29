#include <stdio.h>

/*
void 포인터 :
- 타입이 없는 포인터
*/

int main(void)
{
    int i, j =  20;
    void *v;
    v = &j;                 // void 형 포인터에 j의 주소를 저장하는 시점에, j의 타입 정보가 사라짐. -> v는 주소는 알지만 타입 정보는 모름.
    i = *((int*) v) + 10;   // v가 가리키는 곳의 데이터 형을 int형으로 다룸.
    // i = *v + 10;         // 컴파일 오류. v를 통해 찾아가도 void형 포인터이므로 정수인지 알 수 없어 몇 바이트를 읽어와야 하는지 알지 못함.
    return 0;
}
