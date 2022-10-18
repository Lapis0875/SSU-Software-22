#include <stdio.h>
#define WON 0
#define DOLLAR 1
#define PRODUCT_SIZE 6

// 가격 정보를 저장할 공용체.
typedef union price {
    int won;
    double dollar;
} Price;

// 제품 정보를 저장할 구조체.
typedef struct product {
    char *name;
    _Bool w_d;
    Price price;
} Product;

void input(int*, int*);
void print_product(const Product*, int);
void filter_products(const Product[], int, int);

int main(void)
{
    const Product products[] = {
        {"PMP", WON, (Price) {.won = 600000}},
        {"MP3", WON, (Price) {.won = 153000}},
        {"SmartPhone", DOLLAR, (Price) {.dollar = 520.40}},
        {"TV", DOLLAR, (Price) {.dollar = 430.20}},
        {"Navigator", WON, (Price) {.won = 350000}},
        {"Laptop", DOLLAR, (Price) {.dollar = 1950.00}},
    };
    int money, exchange_rate;
    input(&money, &exchange_rate);
    filter_products(products, money, exchange_rate);
    return 0;
}

/**
 * @brief 표준 입력으로부터 보유 금액과 환율 정보를 입력받는다.
 * 
 * @param money 
 * @param exchange_rate 
 */
void input(int *money, int *exchange_rate)
{
    printf("보유 금액과 환율을 입력하세요.\n보유금액 : ");
    scanf("%d", money);
    printf("환율 : ");
    scanf("%d", exchange_rate);
}

/**
 * @brief 보유 금액과 환율에 따라, 보유 한도 내에 구매할 수 있는 제품을 추려서 출력한다.
 * 
 * @param products 제품 목록을 담은 const Product형 배열.
 * @param money 보유 잔고 (원)
 * @param exchange_rate 환율
 */
void filter_products(const Product products[], int money, int exchange_rate)
{
    int max_won = money;
    double max_dollar = money / exchange_rate;

    printf("구매 가능한 제품은 다음과 같습니다.\n");
    for (int i = 0; i < PRODUCT_SIZE; i++)
    {
        if ((products[i].w_d && products[i].price.dollar <= max_dollar)
         || (!products[i].w_d && products[i].price.won <= max_won))
            print_product(&products[i], exchange_rate);
    }
}

/**
 * @brief 주어진 제품의 정보를 출력한다.
 * 
 * @param product 정보를 출력할 제품
 * @param exchange_rate 환율
 */
void print_product(const Product *product, int exchange_rate)
{
    if (product->w_d)   printf("%s %.0lf원\n", product->name, product->price.dollar * exchange_rate);
    else    printf("%s %d원\n", product->name, product->price.won);

}