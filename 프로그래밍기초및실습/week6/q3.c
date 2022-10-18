#include <stdio.h>

int main(void)
{
  float C;
  printf("섭씨온도를 입력하세요 : ");
  scanf("%f", &C);
  printf("%.2f C = %.2f F\n", C, (float) 9 / 5 * C + 32);
  return 0;
}
