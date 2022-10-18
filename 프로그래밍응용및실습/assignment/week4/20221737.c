#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define LOTTO_SIZE 6
#define LOTTO_NOT_MATCH "X"

typedef struct lottores {
    int rank;
    bool bonus;
    int *nums;
    char matches[6][3];
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
        LottoResult res = {};
        check_lotto(&res, lotto, bonus, nums[i]);
        print_result(i+1, bonus, &res);
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
                sprintf(res->matches[i], "%d", n);
                break;
            }
            else if (n == bonus)
            {
                has_bonus = true;
                checked = true;
                sprintf(res->matches[i], "%d", n);
                break;
            }
        }
        if (!checked)    strcpy(res->matches[i], LOTTO_NOT_MATCH);
    }
    res->rank = getrank(matchcnt, has_bonus);
    res->bonus = has_bonus;
    res->nums = nums;
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
    char numstr[17] = {}, matchstr[23] = {};
    int add_space = LOTTO_SIZE - 1;
    for (int i = 0; i < LOTTO_SIZE; i++)
    {
        char itostr[3] = {};
        sprintf(itostr, "%d", res->nums[i]);
        // printf("itostr = %s\n", itostr);
        strcat(numstr, itostr);
        // printf("numstr = %s\n", numstr);
        if (res->rank != 2 && res->nums[i] == bonus)
            strcat(matchstr, LOTTO_NOT_MATCH);
        else
            strcat(matchstr, res->matches[i]);
        // printf("matchstr = %s\n", matchstr);
        if (i < add_space)
        {
            strcat(numstr, " ");
            // printf("numstr = %s\n", numstr);
            strcat(matchstr, " ");
            // printf("matchstr = %s\n", matchstr);
        }
    }
    if (!res->rank)     // res->rank == 0
        printf("%d세트 번호<%s> -> %s (꽝)\n", index, numstr, matchstr);
    else
        printf("%d세트 번호<%s> -> %s (%d등)\n", index, numstr, matchstr, res->rank);
}