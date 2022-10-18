#include <stdio.h>

unsigned long long pack_employee_data(unsigned id_no, unsigned job_type, unsigned salary, unsigned family);
void print_employee_data(unsigned long long employee);

int main() 
{
    unsigned id_no, salary, job_type, family;
    unsigned long long packed = pack_employee_data(999999, 999, 999999999, 9);
    print_employee_data(packed); // 최대값
    return 0;
}

/**
 * @brief ID, 작업형태, 연봉, 부양가족 수 정보를 패킹하는 함수입니다.
 * 
 * Family > Salary > Job_type > ID 순으로 메모리에 배치됩니다.
 * 
 * @param id_no ID. 십진수 6자리 (0 ~ 999999) : 20비트
 * @param job_type 직업형태. 십진수 3자리 (0 ~ 999) : 10비트
 * @param salary 연봉. 십진수 9자리 (0 ~ 999999999) : 30비트
 * @param family 부양가족 수. 십진수 1자리 (0 ~ 9) : 4비트
 * @return unsigned long long 패킹된 값.
 */
unsigned long long pack_employee_data(
    unsigned id_no,     // 20개 비트
    unsigned job_type,  // 10개 비트
    unsigned salary,    // 30개 비트
    unsigned family     // 4개 비트
) {
    unsigned long long packed = 0;
    packed |= (unsigned long long) id_no;       // unsigned int : 32비트, id_no는 20비트이므로 가능.
    packed |= (unsigned long long) job_type << 20;  // unsigned int : 32비트, job_type은 10비트이므로 20비트 밀어도 표현 범위 안.
    packed |= (unsigned long long) salary << 30;    // unsigned int : 32비트, salary는 30비트이므로 표현 범위를 확장해야 함.
    packed |= (unsigned long long) family << 60;
    return packed;
}

/**
 * @brief 패킹된 직원 정보를 언패킹해 출력하는 함수입니다.
 * 
 * @param employee 패킹된 unsigned long long 형의 값입니다.
 */
void print_employee_data(unsigned long long employee)
{
    static const unsigned long long IDMASK = 0xFFFFF;   // 1이 20개
    static const unsigned long long JOBMASK = 0x3FF;     // 1이 10개
    static const unsigned long long SALARYMASK = 0x3FFFFFFF;  // 1이 30개
    static const unsigned FAMILYMASK = 0xF;     // 1이 4개

    unsigned id_no = employee & IDMASK;
    unsigned job_type = (employee >> 20) & JOBMASK;
    unsigned salary = (employee >> 30) & SALARYMASK;
    unsigned family = (employee >> 60) & FAMILYMASK;
    printf("ID : %u\n", id_no);
    printf("작업 형태 : %u\n", job_type);
    printf("연봉 : %u\n", salary);
    printf("부양 가족 수 : %u\n", family);
}