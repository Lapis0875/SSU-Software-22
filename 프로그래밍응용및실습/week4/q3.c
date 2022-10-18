#include <stdio.h>
#include <string.h>
#define SIZE 10

typedef struct
{
    char *name;     // 연락처의 이름으로, 영문 이름입니다.
    char *email;    // 연락처의 이메일입니다.
    char *phone;    // 연락처의 전화번호입니다.
} Contact;

void prompt(int*);
void print_contact(Contact*);
Contact* query_name(int size, Contact[], char* name);
void name_prompt(int size, Contact[size]);
void query_all(int size, Contact[size]);
void all_prompt(int size, Contact[size]);

int main(void)
{
    Contact contacts[SIZE] = {
        {"Minjun Kim", "lapis0875@gmail.com", "010-7679-7381"},
        {"Only One", "some2mail1@gmail.com", "010-1111-1111"},
        {"Twosome Place", "some2mail2@gmail.com", "010-2222-2222"},
        {"Triple Sugars", "some2mail3@gmail.com", "010-3333-3333"},
        {"Four leaf Clover", "some2mail4@gmail.com", "010-4444-4444"},
        {"Five Fishes", "some2mail5@gmail.com", "010-5555-5555"},
        {"Hexagon Waxes", "some2mail6@gmail.com", "010-6666-6666"},
        {"Lucky 7", "some2mail7@gmail.com", "010-7777-7777"},
        {"8th", "some2mail8@gmail.com", "010-8888-8888"},
        {"9th", "some2mail9@gmail.com", "010-9999-9999"},
    };
    int size = sizeof(contacts) / sizeof(Contact);
    int choice;
    _Bool run = 1;
    while (run)
    {
        prompt(&choice);

        switch (choice) {
            case 1:
                name_prompt(size, contacts);
                break;
            case 2:
                all_prompt(size, contacts);
                break;
            case 3:
                printf("프로그램을 종료합니다.\n");
                run = 0;
                break;
        }
    }

    return 0;
}

/**
 * @brief 초기 메뉴 화면을 출력합니다.
 * 
 * @param choice 사용자가 선택한 동작의 번호를 전달받을 int형 포인터 변수입니다.
 */
void prompt(int *choice)
{
    printf("==============================\n");
    printf("연락처 정보 관리 프로그램\n");
    printf("제작자 : lapis0875\n");
    printf("아래 메뉴의 번호를 입력해 연락처 검색을 수행하세요.\n");
    printf("1. 이름으로 검색\n");
    printf("2. 전체 검색\n");
    printf("3. 종료\n");
    printf("==============================\n");
    printf("> ");
    scanf("%d", choice);
    getchar();  // 버퍼 청소
}

/**
 * @brief 연락처 정보를 출력하는 함수입니다.
 * 
 * @param c Contact형의 포인터 변수로, 출력할 연락처를 가리킵니다.
 */
void print_contact(Contact *c)
{
    if (c == NULL)
        printf("해당하는 연락처가 없습니다.\n\n");
    else
        printf("이름: %s\n이메일: %s\n전화번호: %s\n\n", c->name, c->email, c->phone);
}

/**
 * @brief 이름 기반으로 연락처를 검색합니다.
 * 
 * @param contacts 연락처의 배열입니다.
 * @param name 연락처의 이름입니다.
 * @return Contact* 해당하는 연락처의 포인터입니다. 만약 해당하는 연락처가 없을 경우, NULL을 반환합니다.
 */
Contact* query_name(int size, Contact contacts[size], char* name)
{
    for (int i = 0; i < size; i++)
    {
        if (!strcmp(contacts[i].name, name))
            return &contacts[i];
    }
    return (Contact*) NULL;     // 검색 결과가 없습니다.
}

/**
 * @brief 이름 검색 프롬프트.
 * 
 * @param size 연락처 배열의 길이입니다.
 * @param contacts 연락처 배열입니다.
 */
void name_prompt(int size, Contact contacts[size])
{
    char name[50] = {};
    printf("연락처의 이름을 입력하세요.\n> ");
    scanf("%[^\n]s", name);     // scanf의 형식 지정자를 통해, 공백은 포함하고 개행 문자 이전까지 한번에 읽어오게 함. (연락처 내 띄어쓰기를 허용하기 위함.)
    Contact *c = query_name(size, contacts, name);
    print_contact(c);
}

/**
 * @brief 전체검색 함수입니다. 모든 연락처를 출력합니다.
 * 
 * @param size 연락처 배열의 길이입니다.
 * @param contacts 연락처 배열입니다.
 */
void query_all(int size, Contact contacts[size])
{
    for (int i = 0; i < size; i++)
    {
        print_contact(&contacts[i]);
    }
}

/**
 * @brief 전체 검색 프롬프트입니다.
 * 
 * @param size 연락처 배열의 길이입니다.
 * @param contacts 연락처 배열입니다.
 */
void all_prompt(int size, Contact contacts[size])
{
    printf("전체 연락처를 검색합니다.\n");
    query_all(size, contacts);
}
