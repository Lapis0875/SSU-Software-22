#include <stdio.h>
#include <stdbool.h>

int bitReverse(int n);          // 각 자리 비트 반전하기
int twoComplement(int n, bool reverse);       // 음의 2진수에 대해 2의 보수법 적용 -> 절댓값 씌운 양수값 구하기
signed char binary2decimal(int n);      // 2진수 -> 10진수
int decimal2binary(signed char n);      // 10진수 -> 2진수


int b10 = 1000000000, b9 = 100000000, b8 = 10000000, b7 = 1000000, b2 = 10, b1 = 1;		// 상수들


int main(void)
{
    int option;
    int a, b, res;
    signed char decA, decB, decRes;

    printf("1. 이진수 변환기\n2. 이진수 덧셈기\n3. 이진수 뺄셈기\n\n");
    printf("번호를 선택하세요 > ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
        // 이진수 변환기
        printf("8비트 이진수를 입력하세요 : ");
        scanf("%d", &a);
        printf("%d에 대해 8비트 2진수를 계산합니다.\n", a);
        int dec = binary2decimal(a);
        printf("십진수로 %d입니다.\n", dec);
        break;
    
    case 2:
        // 이진수 덧셈기
        printf("첫 번째 8비트 이진수를 입력하세요 : ");
        scanf("%d", &a);
        printf("두 번째 8비트 이진수를 입력하세요 : ");
        scanf("%d", &b);
        // printf("%d + %d에 대해 8비트 2진수를 계산합니다.\n", a, b);
        decA = binary2decimal(a), decB = binary2decimal(b);
        // printf("a: bin(%08d) -> dec(%hhd) / b: bin(%08d) -> dec(%hhd)\n", a, decA, b, decB);
        decRes = decA + decB;
        // printf("result : dec(%hhd)\n", decRes);
        res = decimal2binary(decRes);
        printf("두 이진수의 합은 %08d이고, 십진수로 %hhd입니다.\n", res, decRes);
        break;
    
    case 3:
        // 이진수 뺄셈기
        printf("첫 번째 8비트 이진수를 입력하세요 : ");
        scanf("%d", &a);
        printf("두 번째 8비트 이진수를 입력하세요 : ");
        scanf("%d", &b);
        // printf("%d - %d에 대해 8비트 2진수를 계산합니다.\n", a, b);
        
        decA = binary2decimal(a), decB = binary2decimal(b);
        // printf("a: bin(%08d) -> dec(%hhd) / b: bin(%08d) -> dec(%hhd)\n", a, decA, b, decB);
        decRes = decA - decB;
        res = decimal2binary(decRes);
        // printf("%hhd - %hhd = %hhd\n", a, b, res);
        printf("두 이진수의 차는 %08d이고, 십진수로 %hhd입니다.\n", res, decRes);
        break;
    default:
        printf("존재하지 않는 옵션입니다! 1~3 중에 입력하세요.\n");
        break;
    }

    return 0;
}

/**
 * @fn int bitReverse(int n)
 * @brief 각 자리의 비트를 반전함.
 * @return 각 자리 비트를 반전한 8비트 2진수
 * @param n 8비트 2진수
 */
int bitReverse(int n) {
    // printf("[bitReverse(%08d)].start\n", n);
    int result = 0, sign = n / b8;
    int cnt = 8;
    for (int i = b1; i <= b7; i *= 10, n /= 10)
    {
        // printf("bit%d: %d -> %d\n", cnt, n % 10, !(n % 10));
        result += !(n % 10) * i;
        cnt--;
    }
    if (result / b8 != sign)
    {
        // printf("부호비트 손실. 복구함\n");
        result -= (result / b8) * b8;
        result += sign * b8;    // 부호비트 복구
    }
    // printf("%08d -> %08d\n", n, result);
    // printf("[bitReverse(%08d)].end(result=%08d)\n", n, result);
    return result;
}

/**
 * @fn int twoComplement(int n)
 * @brief 음수 값의 8비트의 2진수에 대해 2의 보수를 역산함.
 * @return 10진수로 변환한 결과값
 * @param n 8비트 2진수
 * @param reverse bool 값으로, 2의 보수를 역산할것인지(음수->양수), 계산할 것인지(양수->음수)를 판단함.
*/
int twoComplement(int n, bool reverse)
{
    // printf("[twoComplement(%d, %d)].start\n", n, reverse);
    bool sign = n / b8;
    if (reverse)
    {
        // 2의 보수 역산하기
        // 음의 2진수를 2의 보수 역산을 수행한다.
        // 10진수로 변환할 때, 절댓값에 해당하는 값을 얻기 위해 사용한다.
        // 1을 빼고, 비트를 반전한다.

        if (n == 10000000)
        {
            // -128의 경우, -127 + -1로 계산해 구한다.
            // 10000000이라는 값으로 1을 뺀 후 비트를 반전시키게되면,
            // 1 빼기 -> 01111111
            // 01111111 반전 -> 10000000
            // 으로 제자리로 돌아오게된다.
            // 유효한 방법을 생각해내지 못해, 그냥 처리하도록 하자.
            return 10000000;
        }

        int result = n;
        int cnt = 8;
        // printf("[twoComplement(%d, %d)].for<1sub>.start\n", n, reverse);
        for (int i = b1, sub = 1; i <= b8; i *= 10, n /= 10)
        {
            int bit = n % 10;
            printf("%d : %d\n", cnt, bit);
            if (sub)    // 이 자리에서 1을 빼야 함.
            {
                if (bit)    // 이 자리의 비트가 1임.
                {
                    // printf("1 빼기 끝.\n");
                    sub = 0;    // 더 이상 자리 올려가며 뺄 필요 없음.
                    bit = 0;
                    result -= i;
                }
                else    // 이 자리의 비트가 0임. 다음 자리에서도 뺴야 함.
                {
                    // printf("윗 자리에서 1 가져옴.\n");
                    sub = 1;
                    bit = 1;
                    result += i;
                }
            }
            else    // 더이상 뺄 값이 없으므로 종료.
            {
                // printf("[twoComplement(%d, %d)].for<1sub>.end<break>\n", n, reverse);
                break;
            }
            // printf("-> 현재 비트에 1 뺀 후 result = %08d\n", result);
            cnt--;
        }
        // printf("[twoComplement(%d, %d)].for<1sub>.end<finish>\n", n, reverse);
        result = bitReverse(result);
        // printf("[twoComplement(%d, %d)].end(result=%d)\n", n, reverse, result);
        return result;
    }
    else
    {
        // 2의 보수 계산하기
        // 음의 10진수를 우선 절댓값에 대해 2진수로 변환한 후, 2의 보수를 수행하는 과정이다.
        // 각 자리 비트를 반전한 후, 1을 더한다.
        int reversed = bitReverse(n);
        int result = reversed;
        int cnt = 8;
        // printf("[twoComplement(%d, %d)].for<1add>.start\n", n, reverse);
        for (int i = b1, add = 1; i <= b8; i *= 10, reversed /= 10)
        {
            int bit = reversed % 10;
            // printf("%d: %d, current = %d\n", cnt, bit, result);
            if (add)    // 더할 값이 존재함.
            {
                if (!bit)   // 이 자리의 비트가 0임.
                {
                    // printf("1 더하기 끝.\n");
                    add = 0;
                    bit = 1;
                    result += i;
                }
                else    // 이 자리의 비트가 1임.
                {
                    // printf("윗 자리로 1 올림.\n");
                    bit = 0;
                    result -= i;
                    add = 1;
                }
            }
            else    // 더이상 더할 값이 없으므로 종료.
            {
                // printf("[twoComplement(%d, %d)].for<1add>.end<break>\n", n, reverse);
                break;
            }
            // printf("-> 현재 비트에 1 더한 후 result = %08d\n", result);
            cnt--;
            // printf("[twoComplement(%d, %d)].for<1add>.end<finish>\n", n, reverse);
        }
        // printf("[twoComplement(%d, %d)].end(result=%d)\n", n, reverse, result);
        return result;
    }
}

/**
 * @fn int binary2decimal(int n)
 * @brief 8비트의 2진수를 부호를 고려해 10진수로 변환함
 * @return 10진수로 변환한 결과값
 * @param n 8비트 2진수
*/
signed char binary2decimal(int n)
{
    // if (n == 10000000) return -128;
    // printf("[binary2decimal(%d)].start\n", n);
    int dec = 0;
    int sign = n / b8, temp;

    // printf("binary : %08d, sign : %d\n", n, sign);

    if (n == 10000000)
    {
        // printf("[binary2decimal(%d)].end(result=-128)\n", n);
        return -128;
    }
    
    if (sign)   // 음수일 경우
        temp = twoComplement(n, true);
    else
        temp = n;
    
    // printf("temp = %d\n", temp);
    if (temp >= b8)
        temp = temp - sign * b8;    // 부호비트 제거
        

    for(int i = b7, bin = 64; i >= 1; i /= 10, bin /= 2)
    {
        int bit = temp / i;
        // printf("bit = %d, left = ", bit);
        // printf("i = %d, bin = %d, bit = %d : temp (%d -> ", i, bin, bit, temp);
        if (bit)
        {
            dec += bin;
            temp -= i;
        }
        // printf("%d) : dec = %d\n", temp, dec);
    }
    // printf("binary(%08d) -> decimal(%d)\n\n", n, sign ? -dec : dec);
    signed char result = sign ? -dec : dec;
    // printf("[binary2decimal(%08d)].end(result=%hhd)\n", n, result);
    return result;
}

/**
 * @fn int decimal2binary(int n)
 * @brief -128~127의 10진수 정수를 8비트의 2진수로 변환함
 * @return 2진수로 변환한 결과값
 * @param n -128~127의 10진수 정수
*/
int decimal2binary(signed char n)
{
    // printf("[decimal2binary(%d)].start\n", n);
	bool sign = n < 0;
	int temp = 0, result = 0;
	// 부호 비트를 결정합니다.
	if (sign)	// 2의 보수 고려해야 함.
	{
		temp = (n == -128) ? 127 : -n;
		// printf("temp = %d\n", temp);
	}
	else	// 2의 보수 고려 X
	{
		temp = n;
	}
	
	// 양수 값에 대해  각 자리 비트를 결정합니다.
	for (int i = b9, j = 256; i >= 1; i /= 10, j /= 2) {
		//printf("i = %d, j = %d, temp = %d, result = %d\n", i, j, temp, result);
		// i 는 10의 거듭제곱, j는 2의 거듭제곱을 사용.
        int bit = temp / j;
		result += (bit) * i;
		if (bit > 0) temp %= j;
		
	}
    result = result % b9;   // 뒤에서부터 8개비트만 가져옴.
	// printf("10진수 |%d| -> (부호x) 8비트 2진수 %08d\n", n, result);

	if (sign)	// 2의 보수를 계산합니다.
	{
        // printf("sign * b8 + result = %d\n", sign * b8 + result);
		result = twoComplement(result, false);
        // printf("n의 2의 보수 구하기 (128은 여기서 -1을 더해야함) : %d\n", result);
        int copy;

		if (n <= -128) {
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
    if (result < b8) {
	    result += sign * b8;	// 부호 비트 반영
    }
    // printf("dec(%d) -> binary(%08d)\n\n", n, result);
    // printf("[decimal2binary(%d)].end(result=%08d)\n", n, result);
	return result;
}