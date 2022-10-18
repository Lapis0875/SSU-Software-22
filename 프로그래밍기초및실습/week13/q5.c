#include <stdio.h>

void grade_array(int score[], char grade[], int size);

int main(void)
{
    int scores[10] = {100, 95, 89, 82, 74, 79, 66, 61, 50, 40};
    char grades[10] = {};
    grade_array(scores, grades, 10);
    for (int i = 0; i < 10; i++)
        printf("%d : %d점, 학점 %c\n", i+1, scores[i], grades[i]);
    return 0;
}

void grade_array(int score[], char grade[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int s = score[i];
        if (s >= 90 && s <= 100)
            grade[i] = 'A';
        else if (s >= 80 && s < 90)
            grade[i] = 'B';
        else if (s >= 70 && s < 80)
            grade[i] = 'C';
        else if (s >= 60 && s < 70)
            grade[i] = 'D';
        else
            grade[i] = 'F';
    }
}