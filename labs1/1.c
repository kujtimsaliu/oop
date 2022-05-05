/*
За програмски јазик C.

Да се напише програма во која од стандарден влез
се вчитува N (бројот на производи), а потоа се вчитуваат
податоците за N производи (име, цена, количина). Програмата
 треба на стандарден излез да ја отпечати листата на купени
 производи и вкупната сума која треба да се плати во следниот
  облик (пример):

1. Flips    10.00 x 3 = 30.00
2. CocaCola 75.00 x 2 = 150.00
3. ChokoBanana  5.00 x 10 = 50.00
Total: 230.00
*/

#include <stdio.h>

struct list
{
    char name[20];
    float price;
    float quantity;
};

int main()
{
    int n;
    scanf("%d", &n);

    struct list l1;
    float total = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", &l1.name);
        scanf("%f %f", &l1.price, &l1.quantity);
        float sum = l1.price * l1.quantity;
        printf("%d. %s\t%.2f x %.1f = %.2f\n", i, l1.name, l1.price, l1.quantity, sum);
        total += sum;
    }
    printf("Total: %.2f", total);
}