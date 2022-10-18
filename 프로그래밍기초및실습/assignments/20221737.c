#include <stdio.h>

int main(void)
{
	_Bool sign = 0;
	int bit1 = 10000000, bit2 = 1000000;		// 상수들
	int input = 0, temp = 0, result = 0;
	printf("-128부터 127까지의 십진수 정수 하나를 입력하세요 : ");
	scanf("%d", &input);
	if (input < -128 || input > 127) {
		printf("-128~127 사이의 정수를 입력하세요.\n");
		return 0;
	}
	// 부호 비트를 결정합니다.
	if (input < 0)	// 2의 보수 고려해야 함.
	{
		sign = 1;	
		temp = (input == -128) ? 127 : -input;
		// printf("temp = %d\n", temp);
	}
	else	// 2의 보수 고려 X
	{
		sign = 0;
		temp = input;
	}
	
	// 양수 값에 대해  각 자리 비트를 결정합니다.
	for (int i = bit2, j = 64; i >= 1; i /= 10, j /= 2) {
		//printf("i = %d, j = %d, temp = %d, result = %d\n", i, j, temp, result);
		// i 는 10의 거듭제곱, j는 2의 거듭제곱을 사용.
		result += (temp / j) * i;
		if (temp / j > 0) temp %= j;
		
	}
	// printf("10진수 %d -> 2진수 %07d\n", input, result);

	if (sign)	// 2의 보수를 계산합니다.
	{
		// printf("2의 보수를 계산합니다. 현재 비트 : %07d\n", result);
		// printf("비트를 반전합니다.\n");
		int copy = result;
		for (int i = 1, cnt = 8; cnt > 1; i *= 10, copy /= 10, cnt--)
		{
			// 비트 반전
			// printf("copy = %d\n", copy);
			// printf("result = %d\n", result);
			temp = copy % 10;	// 비트 가져오기
			// printf("%d번째 자리 : %d -> %d\n", cnt, temp, !temp);
			result = result - temp * i + !temp * i;	// 해당 자리 비트 반전
		}
		// printf("반전된 비트 : %07d\n", result);

		// printf("1을 더합니다.\n");
		copy = result;
		for (int i = 1, cnt = 8, upper = 1; cnt > 1; i *= 10, cnt--)
		{
			// 1 더하기
			temp = copy % 10;	// 비트 가져오기
			// printf("%d번째 자리수 : %d, copy = %d, result = %d\n", cnt, temp, copy, result);
			result -= temp * i;		// 해당 비트 0으로 초기화.
			copy /= 10;
			
			// 자리올림
			// 다음 자릿수에 더해야 하는 수 결정.
			temp += upper;
			// printf("temp = %d\n", temp);
			if (temp > 1)
			{
				temp = (temp > 2) ? 1 : 0;	// 만약 합이 3이될...수가있나?
				upper = 1;
			}
			else upper = 0;
			result += temp * i;	// 해당 비트 반영
		}

		if (input == -128) {
			// -128 예외처리
			// printf("-128입니다.\n");
			copy = result;
			for (int cnt = 8, i = 1, upper = 0; cnt > 1; i *= 10, cnt--)
			{
				temp = copy % 10;
				copy /= 10;
				result -= temp * i;
				// printf("%d번쨰 자리 : %d\n", cnt, temp);
				temp += 1 + upper;	// (-127) + (-1)
				
				if (temp > 1)
				{
					temp = (temp > 2) ? 1 : 0;	// 만약 합이 3이될...수가있나?
					upper = 1;
				}
				else upper = 0;
				result += temp * i;	// 해당 비트 반영
				
			}\
			// printf("result = %d\n", result);
		}
	}
	result += sign * bit1;	// 부호 비트 반영
	// 결과를 출력합니다.
	printf("%d의 이진수는 %08d입니다.\n", input, result);
	return 0;
}
