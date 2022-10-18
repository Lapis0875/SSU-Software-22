#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

void input_words(char*[]);
void print_array(char*[]);
void free_words(char*[]);
int compare_word(const void*, const void*);

/**
 * 20221737 김민준 2022.9.19 실습 5번 문항.
 * 포인터랑 동적 할당에 대해 좀 더 생각해 볼 수 있는 계기가 되어 좋았습니다.
 */
int main(void)
{
    char *words[N];
    int i;

    input_words(words);     // 단어 입력받기

    qsort(words, N, sizeof(char*), compare_word);       // qsort 활용해 정렬.

    print_array(words);     // 정렬된 내용 출력

    free_words(words);      // 메모리 할당 해제

    return 0;
}

/**
 * @brief 표준 입력으로부터 단어를 입력받아, 길이에 맞게 메모리를 동적할당 후 배열에 저장합니다.
 * 
 * @param words char* 형의 값들의 배열입니다.
 */
void input_words(char *words[])
{
    for (int i = 0; i < N; i++)
    {
        char* word;
        scanf("%s", word);
        
        words[i] = (char*) calloc(strlen(word) + 1, sizeof(char));
        strcpy(words[i], word);
    }
}

/**
 * @brief 동적할당된 배열의 각 원소들을 해제합니다.
 * 
 * @param words char* 형의 값들의 배열입니다.
 */
void free_words(char *words[])
{
    for (int i = 0; i < N; i++)
        free(words[i]);
}

/**
 * @brief 배열 내용을 출력합니다.
 * 
 * @param array char* 형의 값들의 배열입니다.
 */
void print_array(char* array[])
{
    for (int i = 0; i < N; i++)
        printf("%s\n", array[i]);
}

/**
 * @brief 두개의 char* 형의 값을 비교하는 함수입니다. strcmp를 사용합니다.
 * 
 * @param a const void* 형의 변수입니다.
 * @param b const void* 형의 변수입니다.
 * @return int 비교 결과입니다.
 */
int compare_word(const void *a, const void *b)
{
    return strcmp(*(const char**) a, *(const char**) b);
}
