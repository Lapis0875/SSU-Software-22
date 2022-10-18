#include <stdio.h>

struct info{
    char name[20]; // 이름
    double score; // 평점 평균
    int credit; // 취득 학점
};

void input_data(struct info[], int);
void scholarship(struct info[], int);

int main(void)
{
    struct info students[5]; // 5명의 학생
    input_data(students, 5); // 이름, 평점 평균, 취득 학점을 입력받는 함수
    scholarship(students, 5); // 장학생의 이름, 평점 평균, 취득 학점을 출력하는 함수
    return 0;
}

/**
 * @brief 학생들의 정보를 표준 입력으로부터 입력받는다.
 * 
 * @param students 학생들의 정보를 저장할 info 구조체의 배열.
 * @param size 배열의 길이
 */
void input_data(struct info students[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("학생의 이름을 입력하세요 : ");
        scanf("%s", students[i].name);
        
        printf("취득 학점을 입력하세요 : ");
        scanf("%d", &students[i].credit);
        
        printf("평점 평균을 입력하세요 : ");
        scanf("%lf", &students[i].score);
    }
}

/**
 * @brief 장학금의 대상자를 출력한다.
 * 
 * @param students 학생들의 정보가 저장된 info 구조체의 배열.
 * @param size 배열의 길이
 */
void scholarship(struct info students[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (students[i].credit >= 20 && students[i].score >= 4.3)
            printf("장학생의 이름 : %s, 취득 학점 : %d, 평점 평균 %.2lf\n", students[i].name, students[i].credit, students[i].score);
    }
}
