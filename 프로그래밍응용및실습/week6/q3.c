#include <stdio.h>

typedef struct person {
    char name[10];
    unsigned id: 17;        // 0~99999, 99999 = 11000011010011111
    unsigned age: 7;        // 0 ~ 65, 65 = 1000001
    unsigned salary: 27;    // 0 ~ 1억, 1억 = 101111101011110000100000000
} Person;

unsigned long long pack_person(Person*);
void unpack_person(unsigned long long, Person*);
void print_person(Person*);

int main(void)
{
    Person people[7] = {
        {"tom", 10333, 21, 24000000},
        {"eric", 10333, 23, 28000000},
        {"jane", 40234, 26, 40000000},
        {"mary", 30022, 46, 65000000},
        {"kim", 90032, 25, 38000000},
        {"lee", 90038, 24, 30000000},
        {"Test_name", 99999, 65, 100000000}     // 최댓값
    };
    for (int i = 0; i < 7; i++)
    {
        printf("people[%d] :\n", i);
        print_person(&people[i]);
        unsigned long long packed = pack_person(&people[i]);
        printf("people[%d] = %llu\n", i, packed);
        // 101101 1100011 0110000 0000000 1010100 1101101 1101111 1110100
        printf("try unpack.\n");
        Person p = {};
        unpack_person(packed, &p);
        print_person(&p);
    }
    return 0;
}

/**
 * @brief 인물 정보를 패킹합니다.
 * 
 * @param p Person 형의 포인터.
 * @return unsigned long long 패킹된 값.
 */
unsigned long long pack_person(Person *p)
{
    unsigned long long packed = 0;
    for (int i = 0; i < 10; i++)
        packed |= (unsigned long long) p->name[i] << (7 * i);
    packed |= (unsigned long long) p->id << 70;
    packed |= (unsigned long long) p->age << 87;
    packed |= (unsigned long long) p->salary << 94;
    return packed;
}

/**
 * @brief 패킹된 값을 언패킹합니다.
 * 
 * @param packed 패킹된 값.
 * @param p 언패킹한 값을 저장할 Person형의 포인터 변수.
 */
void unpack_person(unsigned long long packed, Person *p)
{
    for (int i = 0; i < 10; i++)
        p->name[i] = (packed >> (7 * i)) & 0b1111111;
    p->id = (packed >> 70) & 0x1ffff;
    p->age = (packed >> 87) & 0x7f;
    p->salary = (packed >> 94) & 0x7ffffff;
}

/**
 * @brief 인물 정보를 출력합니다.
 * 
 * @param p Persno 형의 포인터.
 */
void print_person(Person *p)
{
    printf("이름 : %s\n", p->name);
    printf("ID : %u\n", p->id);
    printf("나이 : %u\n", p->age);
    printf("연봉 : %u\n", p->salary);
}