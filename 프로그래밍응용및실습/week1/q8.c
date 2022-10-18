#include <stdio.h>

int main(void)
{
    int i, *p;
    scanf("%d", &i);
    scanf("%d", p);
    /*
    p는 포인터 변수로 쓰니 &을 안쓰는것은 맞다.
    하지만, p는 선언만 된 채로 특정 주소를 가리키고 있지 않아 쓰레기 값을 가지고 있다.
    이 주소는 우리가 접근해서는 안되는 주소이므로, 이 주소에 scanf를 사용시 오류가 발생한다.
    /*
    printf("%d\n", i);
    printf("%d\n", *p);
    return 0;
}