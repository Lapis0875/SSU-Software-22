#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{	
	int max = 45, min = 1;
	char answer;
	srand(time(NULL));
	
	do {	// 최소 한 번은 실행해야하므로 do~while
		printf("추천 로또 번호는 : ");
		for (int i = 0; i < 6; i++)
		{
			int gen = (rand() % (max - min + 1)) + min;		// min ~ max 범위의 랜덤한 정수 만들기.
			printf("%d ", gen);
		}
		printf("\n");
		printf("다시 생성할까요? ");
		scanf("%c", &answer);
		getchar();    // y\n, n\n 처럼 y, n 뒤에 따라오는 개행문자 처리. 처리 안하면 y 입력받은후 \n을 받아 종료해버리므로 이를 예방하기 위함.
	} while (answer == 'y');
	return 0;
}
