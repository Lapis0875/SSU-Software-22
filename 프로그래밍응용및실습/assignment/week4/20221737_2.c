#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LOTTO_SIZE 6            // 자주 쓰는 상수값에는 의미에 맞는 이름을 지어뒀습니다.
#define LOTTO_NOT_MATCH "X"     // 로또 번호와 일치하지 않는 숫자에 표기할 문자.
#define SPACE " "               // 띄어쓰기.

// 로또 번호 한 세트의 분석 결과를 저장할 구조체.
typedef struct lottores {
    int rank;
    bool bonus;
    int *nums;
    char *matches;
} LottoResult;

void lotto_input(int[LOTTO_SIZE], int*);
void check_lotto(LottoResult*, int[LOTTO_SIZE], int, int[LOTTO_SIZE]);
int getrank(int, bool);
void print_result(int, int, LottoResult*);

int main(void)
{
    int nums[5][LOTTO_SIZE] = {
        {1, 2, 3, 4, 5, 6},
        {10, 15, 25, 35, 40, 42},
        {1, 9, 11, 22, 23, 25},
        {9, 28, 31, 34, 35, 36},
        {1, 9, 23, 28, 33, 35}
    };
    int lotto[LOTTO_SIZE] = {};
    int bonus = 0;
    lotto_input(lotto, &bonus);

    for (int i = 0; i < 5; i++)
    {
        LottoResult res = {};       // 각 로또 세트의 결과를 저장할 구조체를 만든다
        check_lotto(&res, lotto, bonus, nums[i]);   // 정답 번호와 보너스 숫자, 이 세트의 로또 번호로 로또 결과를 분석하고, res에 저장한다.
        print_result(i+1, bonus, &res);         // res에 저장해둔 분석 결과를 출력한다.
    }
    return 0;
}

void lotto_input(int lotto[LOTTO_SIZE], int *bonus)
{
    printf("금주의 로또 번호를 입력하세요 -> ");
    for (int i = 0; i < LOTTO_SIZE; i++)
    {
        scanf("%d", &lotto[i]);
    }
    printf("보너스 번호를 입력하세요 -> ");
    scanf("%d", bonus);
}

/**
 * @brief 주어진 로또 번호가 몇등인지 판별하는 함수입니다.
 * 
 * @param lotto 이번 주의 로또 번호입니다.
 * @param bonus 이번 주의 보너스 숫자입니다.
 * @param nums 등수를 확인할 임의의 로또 번호입니다.
 * @return 로또의 결과를 저장한 LottoResult 구조체 타입의 값을 반환합니다.
 */
void check_lotto(LottoResult *res, int lotto[LOTTO_SIZE], int bonus, int nums[LOTTO_SIZE])
{
    int matchcnt = 0;
    bool has_bonus = false;
    char matchstr[LOTTO_SIZE][3] = {};
    size_t matchstr_size = 0;
    char temp[3] = {};

    for (int i = 0; i < LOTTO_SIZE; i++)
    {
        int n = nums[i];    // 임의의 로또 번호에서 순서대로 숫자 하나씩 가져와서
        bool checked = false;
        for (int j = 0; j < LOTTO_SIZE; j++)
        {
            // 이 숫자가 금주의 로또 번호에 존재하거나, 보너스 숫자와 일치하는지 확인한다.
            if (n == lotto[j])
            {
                matchcnt++;
                checked = true;
                sprintf(temp, "%d", n);
                strcpy(matchstr[i], temp);
                matchstr_size += strlen(temp);
                break;
            }
            else if (n == bonus)
            {
                has_bonus = true;
                checked = true;
                sprintf(temp, "%d", n);
                strcpy(matchstr[i], temp);
                matchstr_size += strlen(temp);
                break;
            }
        }
        if (!checked) 
        {
            strcpy(matchstr[i], LOTTO_NOT_MATCH);
            matchstr_size += strlen(LOTTO_NOT_MATCH);
        }
    }
    // 구조체에 정보 저장.
    res->rank = getrank(matchcnt, has_bonus);
    res->bonus = has_bonus;
    res->nums = nums;

    // 일치 결과를 단일 문자열로 만들기 위한 과정. 문자열에 사용되는 메모리를 줄여보고자 길이에 맞게 동적할당함.
    res->matches = (char*) calloc(matchstr_size + 6, sizeof(char)); // matchstr 배열의 각 원소들의 길이 합 + 띄어쓰기 5칸 + \0 1개
    sprintf(temp, "%d", bonus);     // 보너스 숫자를 문자열로 만들어 temp에 저장.
    for (int i = 0; i < LOTTO_SIZE; i++)
    {
        // 여기서 realloc을 써서 배열 길이에 맞게 확장해나가면 코드가 더 깔끔할것같은데, realloc이 강의자료에 없던 관계로..
        if (res->rank != 2 && strcmp(matchstr[i], temp) == 0)
            strcat(res->matches, LOTTO_NOT_MATCH);
        else
            strcat(res->matches, matchstr[i]);
        if (i < 5)  strcat(res->matches, SPACE);
    }
}

/**
 * @brief 로또 등수를 반환합니다.
 * 
 * @param matchcnt 로또 번호의 일치 개수.
 * @param bonus 보너스 숫자의 유무
 * @return int 1~5등 일 경우 해당 등수의 정수값을, 꽝일 경우 0을 반환합니다.
 */
int getrank(int matchcnt, bool bonus)
{
    switch (matchcnt)
    {
        case 6:
            return 1;
        case 5:
            // if (bonus) return 2;
            // else return 3;
            // bonus는 bool 타입이며, <stdbool.h>의 true와 false 매크로를 써 1 또는 0의 값 중 하나를 가짐을 보장할 수 있다.
            return 3 - bonus;
        case 4:
            return 4;
        case 3:
            return 5;
        default:
            return 0;
    }
}

/**
 * @brief 로또 결과를 콘솔에 출력합니다.
 * 
 * @param res LottoResult 형의 포인터입니다.
 */
void print_result(int index, int bonus, LottoResult *res)
{
    int add_space = LOTTO_SIZE - 1;
    printf("%d세트 번호(", index);
    for (int i = 0; i < LOTTO_SIZE; i++)
    {
        // 홍길동의 로또 세트 번호 출력.
        printf("%d", res->nums[i]);
        if (i < add_space)  printf(" ");
    }
    if (!res->rank)     // res->rank == 0
        printf(") -> %s (꽝)\n", res->matches);
    else
        printf(") -> %s (%d등)\n", res->matches, res->rank);
}