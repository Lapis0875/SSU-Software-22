#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum grade {
    A_PLUS, A0, A_MINUS, B_PLUS, B0, B_MINUS, C_PLUS, C0, C_MINUS, D_PLUS, D0, D_MINUS, F
} Grade;

typedef struct student {
    char name[20];
    int id;
    char grade[3];
    Grade grade2;
} Student;

void input_students(Student[], int);
Grade get_grade(char[3]);
int compare_students(const void*, const void*);
void sort_students(Student[], int);
void print_students(Student[], int);

int main(void)
{
    int n;
    printf("몇 명의 학생을 입력할까요? : ");
    scanf("%d", &n);
    Student *students = (Student*) calloc(n, sizeof(Student));
    input_students(students, n);
    sort_students(students, n);
    print_students(students, n);
    free(students);
    students = NULL;
    return 0;
}

/**
 * @brief 학생들의 정보를 표준 입력으로부터 입력받습니다.
 * 
 * @param students 학생들의 정보를 담을 Student 형의 배열.
 * @param size 배열의 길이.
 */
void input_students(Student students[], int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%s", students[i].name);
        scanf("%d", &students[i].id);
        scanf("%s", students[i].grade);
        students[i].grade2 = get_grade(students[i].grade);
    }
}

/**
 * @brief 학점 문자열을 grade 열거형으로 변환합니다.
 * 
 * @param grade 학점 문자열.
 * @return Grade 형 (grade 열거형)의 값.
 */
Grade get_grade(char grade[3])
{
    if (strcmp(grade, "A+"))
        return A_PLUS;
    else if (strcmp(grade, "A0"))
        return A0;
    else if (strcmp(grade, "A-"))
        return A_MINUS;
    else if (strcmp(grade, "B+"))
        return B_PLUS;
    else if (strcmp(grade, "B0"))
        return B0;
    else if (strcmp(grade, "B-"))
        return B_MINUS;
    else if (strcmp(grade, "C+"))
        return C_PLUS;
    else if (strcmp(grade, "C0"))
        return C0;
    else if (strcmp(grade, "C-"))
        return C_MINUS;
    else if (strcmp(grade, "D+"))
        return D_PLUS;
    else if (strcmp(grade, "D0"))
        return D0;
    else if (strcmp(grade, "D-"))
        return D_MINUS;
    else if (strcmp(grade, "F"))
        return F;
}

/**
 * @brief 두 Student 형의 grade2값을 비교합니다. qsort에 사용하고자 하는 comapre 함수입니다.
 * 
 * @param a 학생 1
 * @param b 학생 2
 * @return int 형의 비교 결과
 */
int compare_students(const void *a, const void *b)
{
    Student *stuA = (Student*) a;
    Student *stuB = (Student*) b;
    if (stuA->grade2 < stuB->grade2)    return 1;
    else if (stuA->grade2 > stuB->grade2)   return -1;
    return 0;
}

/**
 * @brief 학생들의 배열을 정렬합니다.
 * 
 * @param students 학생들의 정보를 담은 Student 형의 배열.
 * @param size 배열의 길이.
 */
void sort_students(Student students[], int size)
{
    qsort(students, size, sizeof(Student), compare_students);
}

/**
 * @brief 학생 정보를 출력합니다.
 * 
 * @param students 학생들의 정보를 담은 Student 형의 배열.
 * @param size 배열의 길이.
 */
void print_students(Student students[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%s %d %s\n", students[i].name, students[i].id, students[i].grade);
}