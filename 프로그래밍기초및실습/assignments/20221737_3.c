#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define STU_INFO_SIZE 20
#define MAX_NAME_LENGTH 10

// 로직
void inputData(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[]);
void sort(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[], bool ascend);
void printArray(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[]);

// 1~4 옵션별 모듈화
void sortNameAscend(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[]);
void sortStuNumAscend(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[]);
void sortScoreDescend(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[]);
void searchWithName(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[]);

int main(void)
{
    bool loop = true;
    int option = 0;
    char names[STU_INFO_SIZE][MAX_NAME_LENGTH] = {};
    int stuNums[STU_INFO_SIZE] = {};
    int scores[STU_INFO_SIZE] = {};
    inputData(STU_INFO_SIZE, names, stuNums, scores);
    printArray(STU_INFO_SIZE, names, stuNums, scores);       // 디버깅용.

    while (loop)
    {
        printf("1. 이름 오름차순 출력\t2. 학번 오름차순 출력\n3. 점수 내림차순 출력\t4.이름 검색\n5.종료\n\n");
        printf("번호를 선택하세요 : ");
        scanf("%d", &option);
        printf("\n");   // 추가 공백이 필요해보임.

        switch (option)
        {
            case 1:
                // 이름 오름차순 출력
                sortNameAscend(STU_INFO_SIZE, names, stuNums, scores);
                printArray(STU_INFO_SIZE, names, stuNums, scores);
                break;

            case 2:
                // 학번 오름차순 출력
                sortStuNumAscend(STU_INFO_SIZE, names, stuNums, scores);
                printArray(STU_INFO_SIZE, names, stuNums, scores);
                break;

            case 3:
                // 점수 내림차순 출력
                sortScoreDescend(STU_INFO_SIZE, names, stuNums, scores);
                printArray(STU_INFO_SIZE, names, stuNums, scores);
                break;

            case 4:
                // 이름 검색
                searchWithName(STU_INFO_SIZE, names, stuNums, scores);
                break;
        
            case 5:
                // 종료
                loop = false;
                break;
        
            default:
                printf("1~5 중에서 선택해주세요.\n");
                break;
        }
    }
    return 0;
}


// 로직
/**
 * @brief 학생 정보 데이터를 배열에 저장합니다.
 * 
 * @param size 배열 크기
 * @param names 학생 이름 배열
 * @param stuNums 학생 학번 배열
 * @param scores 학생 점수 배열
 */
void inputData(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[])
{
    // 파일에 저장해두고 읽고싶은데... 안배운기능은 쓰면 안된대요
    strcpy(names[0], "Sophia"); stuNums[0] = 20220001; scores[0] = 98;
    strcpy(names[1], "Olivia"); stuNums[1] = 20220010; scores[1] = 96;
    strcpy(names[2], "Riley"); stuNums[2] = 20220002; scores[2] = 88;
    strcpy(names[3], "Emma"); stuNums[3] = 20220015; scores[3] = 77;
    strcpy(names[4], "Ava"); stuNums[4] = 20220009; scores[4] = 82;
    strcpy(names[5], "Isabella"); stuNums[5] = 20220014; scores[5] = 93;
    strcpy(names[6], "Aria"); stuNums[6] = 20220020; scores[6] = 84;    // <-- 여기까지했음
    strcpy(names[7], "Amelia"); stuNums[7] = 20220005; scores[7] = 79;
    strcpy(names[8], "Mia"); stuNums[8] = 20220016; scores[8] = 90;
    strcpy(names[9], "Liam"); stuNums[9] = 20220008; scores[9] = 80;
    strcpy(names[10], "Noah"); stuNums[10] = 20220012; scores[10] = 89;
    strcpy(names[11], "Jackson"); stuNums[11] = 20220004; scores[11] = 99;
    strcpy(names[12], "Aiden"); stuNums[12] = 20220018; scores[12] = 78;
    strcpy(names[13], "Elijah"); stuNums[13] = 20220017; scores[13] = 83;
    strcpy(names[14], "Grayson"); stuNums[14] = 20220003; scores[14] = 92;
    strcpy(names[15], "Lucas"); stuNums[15] = 20220013; scores[15] = 71;
    strcpy(names[16], "Oliver"); stuNums[16] = 20220007; scores[16] = 72;
    strcpy(names[17], "Caden"); stuNums[17] = 20220019; scores[17] = 68;
    strcpy(names[18], "Mateo"); stuNums[18] = 20220011; scores[18] = 96;
    strcpy(names[19], "David"); stuNums[19] = 20220006; scores[19] = 76;
}

/**
 * @brief 배열을 정렬합니다.
 * 
 * @param size 배열 크기
 * @param names 학생 이름 배열
 * @param stuNums 학생 학번 배열
 * @param scores 학생 점수 배열
 * @param ascend 오름차순 정렬할지 결정합니다. true일시 오름차순, false일시 내림차순 정렬합니다.
 */
void sort(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[], bool ascend)
{

}

/**
 * @brief 배열을 양식에 맞춰 출력합니다.
 * 
 * @param size 배열 크기
 * @param names 학생 이름 배열
 * @param stuNums 학생 학번 배열
 * @param scores 학생 점수 배열
 */
void printArray(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[])
{
    printf("이름\t  학번\t    점수\n");
    for (int i = 0; i < size; i++)
    {
        printf("%-10s%-10d%-10d\n", names[i], stuNums[i], scores[i]);
    }
    printf("\n");   // 가독성을 위한 추가 개행
}

// 1~4 옵션별 모듈화
/**
 * @brief 1번 옵션에 대한 구현입니다. 이름을 기준으로 오름차순 정렬합니다.
 * 
 * @param size 배열의 크기
 * @param names 학생 이름 배열
 * @param stuNums 학생 학번 배열
 * @param scores 학생 점수 배열
 */
void sortNameAscend(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[])
{
    int itemp;
    char ctemp[MAX_NAME_LENGTH] = {};
    for (int i = 0; i < size; i++)
    {
        // printf("\n%d번째 버블소트:\n", i+1);
        for (int j = size - 1; j > i; j--)
        {
            // printf("%d번째 인덱스 검사중\n", j);
            signed char res = strcmp(names[j], names[j-1]);
            // printf("%d(%s) %c %d(%s) [%d]\n", j, names[j], res < 0 ? '<' : (res == 0 ? '=' : '>'), j-1, names[j-1], res);
            if (res < 0)       // j-1의 이름이 j보다 클때
            {
                // printf("%d번째 인덱스의 학번이 그 다음 인덱스보다 큼. 자리바꿈\n", j-1);
                // printf("%d : %-10s%-10d%-10d\n", j-1, names[j-1], stuNums[j-1], scores[j-1]);
                // printf("%d : %-10s%-10d%-10d\n\n", j, names[j], stuNums[j], scores[j]);
                // Swap Student Numbers
                itemp = stuNums[j-1];
                stuNums[j-1] = stuNums[j];
                stuNums[j] = itemp;

                // Swap Names
                strcpy(ctemp, names[j-1]);
                strcpy(names[j-1], names[j]);
                strcpy(names[j], ctemp);

                // Swam Scores
                itemp = scores[j-1];
                scores[j-1] = scores[j];
                scores[j] = itemp;
                // printArray(STU_INFO_SIZE, names, stuNums, scores);
            }
        }
        // printArray(STU_INFO_SIZE, names, stuNums, scores);
    }
}

/**
 * @brief 2번 옵션에 대한 구현입니다. 학번을 기준으로 오름차순 정렬합니다. (버블소트)
 * 
 * @param size 배열의 크기
 * @param names 학생 이름 배열
 * @param stuNums 학생 학번 배열
 * @param scores 학생 점수 배열
 */
void sortStuNumAscend(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[])
{
    int itemp;
    char ctemp[MAX_NAME_LENGTH] = {};
    for (int i = 0; i < size; i++)
    {
        // printf("\n%d번째 버블소트:\n", i+1);
        for (int j = size - 1; j > i; j--)
        {
            // printf("%d번째 인덱스 검사중\n", j);
            if (stuNums[j] < stuNums[j-1])
            {
                // printf("%d번째 인덱스의 학번이 그 다음 인덱스보다 큼. 자리바꿈\n", j-1);
                // printf("%d : %-10s%-10d%-10d\n", j-1, names[j-1], stuNums[j-1], scores[j-1]);
                // printf("%d : %-10s%-10d%-10d\n\n", j, names[j], stuNums[j], scores[j]);
                // Swap Student Numbers
                itemp = stuNums[j-1];
                stuNums[j-1] = stuNums[j];
                stuNums[j] = itemp;

                // Swap Names
                strcpy(ctemp, names[j-1]);
                strcpy(names[j-1], names[j]);
                strcpy(names[j], ctemp);
                

                // Swam Scores
                itemp = scores[j-1];
                scores[j-1] = scores[j];
                scores[j] = itemp;
                // printArray(STU_INFO_SIZE, names, stuNums, scores);
            }
        }
        // printArray(STU_INFO_SIZE, names, stuNums, scores);
    }
}

/**
 * @brief 3번 옵션에 대한 구현입니다. 점수를 기준으로 내림차순 정렬합니다.
 * 
 * @param size 배열의 크기
 * @param names 학생 이름 배열
 * @param stuNums 학생 학번 배열
 * @param scores 학생 점수 배열
 */
void sortScoreDescend(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[])
{
    int itemp;
    char ctemp[MAX_NAME_LENGTH] = {};
    for (int i = 0; i < size; i++)
    {
        // printf("\n%d번째 버블소트:\n", i+1);
        for (int j = size - 1; j > i; j--)
        {
            // printf("%d번째 인덱스 검사중\n", j);
            if (scores[j] > scores[j-1])
            {
                // printf("%d번째 인덱스의 점수가 그 이전 인덱스보다 큼. 자리바꿈\n", j);
                // printf("%d : %-10s%-10d%-10d\n", j+1, names[j-1], stuNums[j-1], scores[j-1]);
                // printf("%d : %-10s%-10d%-10d\n\n", j, names[j], stuNums[j], scores[j]);
                // Swap Student Numbers
                itemp = stuNums[j-1];
                stuNums[j-1] = stuNums[j];
                stuNums[j] = itemp;

                // Swap Names
                strcpy(ctemp, names[j-1]);
                strcpy(names[j-1], names[j]);
                strcpy(names[j], ctemp);
                

                // Swam Scores
                itemp = scores[j-1];
                scores[j-1] = scores[j];
                scores[j] = itemp;
                // printArray(STU_INFO_SIZE, names, stuNums, scores);
            }
        }
        // printArray(STU_INFO_SIZE, names, stuNums, scores);
    }

}

/**
 * @brief 4번 옵션에 대한 구현입니다. 이름으로 학생 정보를 검색합니다.
 * 
 * @param size 배열의 크기
 * @param names 학생 이름 배열
 * @param stuNums 학생 학번 배열
 * @param scores 학생 점수 배열
 */
void searchWithName(int size, char names[][MAX_NAME_LENGTH], int stuNums[], int scores[])
{
    char searchName[MAX_NAME_LENGTH] = {};
    int stuNum, score;
    printf("이름을 입력하세요 : ");
    scanf("%s", searchName);

    for (int i = 0; i < size; i++)
    {
        if (strcmp(names[i], searchName) == 0)
        {
            stuNum = stuNums[i];
            score = scores[i];
            break;
        }
    }
    printf("이름\t  학번\t    점수\n");
    printf("%-10s%-10d%-10d\n\n", searchName, stuNum, score);
}