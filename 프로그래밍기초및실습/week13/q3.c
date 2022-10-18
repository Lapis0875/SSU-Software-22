#include <stdio.h>

void input(int size, int array[]);
void sort(int size, int array[]);
void printScores(int size, int array[]);

int main(void)
{
    int scores[5] = {};
    input(5, scores);
    sort(5, scores);
    printScores(5, scores);
    return 0;
}

/**
 * @brief size명의 점수를 입력받아 array에 저장합니다.
 * 
 * @param size 배열 크기
 * @param array 배열
 */
void input(int size, int array[])
{
    printf("성적을 입력하세요 : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

/**
 * @brief array의 원소들을 내림차순 (큼 -> 작음) 으로 정렬합니다. 버블 소트 방식.
 * 
 * @param size 배열 크기
 * @param array 배열
 */
void sort(int size, int array[])
{
    int temp = 0;
    for (int i = 0; i < size; i++)
        for (int j = i+1; j < size - i; j++)
        {
            if (array[i] < array[j])
            {
                // 원소 교체
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
}

/**
 * @brief 배열에 저장된 점수들을 출력합니다.
 * 
 * @param size 배열 크기
 * @param array 배열
 */
void printScores(int size, int array[])
{
    for (int i = 0; i < size; i++)
        printf("%d등 %d점\n", i+1, array[i]);
}