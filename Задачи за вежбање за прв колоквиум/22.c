#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct Proizvod
{
    char productCode[20];
    int productPrice, stock;
};
typedef struct Proizvod Proizvod;

struct Narachka
{
    char name[15];
    Proizvod niza[10];
    int orderedProduct[10];
    int n;
};
typedef struct Narachka Narachka;

int mozedapecati(Narachka narachka)
{
    for (int i = 0; i < narachka.n; i++)
    {
        if (narachka.orderedProduct[i] > narachka.niza[i].stock)
        {
            return 0;
        }
        else
            return 1;
    }
}

// void alphabeticallyOrder(Narachka *narachka)
// {
//     Narachka temp = narachka;
//     int n = narachka.n;
//     for (int i = 0; i < n - 1; i++)
//     {

//         if (strcmp(narachka->niza[i].productCode[0], narachka->niza[i + 1].productCode[0]) == 1)
//         {
//             *(temp).niza[i].productCode = narachka->niza[i + 1].productCode;
//             *(narachka)->niza[i + 1].productCode = narachka->niza[i].productCode;
//             *(narachka)->niza[i].productCode = temp.niza[i].productCode;
//         }
//     }
// }

void pecatiFakture(Narachka narachka)
{
    int vkupno = 0;
    printf("Faktura za %s\n", narachka.name);
    // printf("")
    Proizvod temp;
    if (mozedapecati(narachka))
    {
        for (int i = 0; i < (narachka.n) - 1; i++)
        {
            for (int j = i + 1; j < narachka.n; j++)
            {

                if (strcmp(narachka.niza[i].productCode, narachka.niza[j].productCode) > 0)
                {
                    temp = narachka.niza[i];
                    narachka.niza[i] = narachka.niza[j];
                    narachka.niza[j] = temp;
                }
            }
        }
        for (int i = 0; i < narachka.n; i++)
        {
            vkupno += narachka.orderedProduct[i] * narachka.niza[i].productPrice;
            printf("%s %d %d %d\n",
                   narachka.niza[i].productCode,
                   narachka.niza[i].productPrice,
                   narachka.orderedProduct[i],
                   (narachka.orderedProduct[i] * narachka.niza[i].productPrice));
        }
        printf("Vkupnata suma na fakturata e %d\n", vkupno);
    }
    else if (mozedapecati(narachka) == 0) // which means ne moze da pecati
    {
        // printf Fakturata ne moze da se izgotvi
        printf("Fakturata ne moze da se izgotvi");
    }
}

int main()
{

    Narachka narachka;

    // внеси го името лицето кое ја прави нарачката
    // внеси го бројот на порачани производи во нарачката

    char name[15];
    int orderedno;
    scanf("%s", &narachka.name);
    scanf("%d", &narachka.n);

    int i;
    //за секој од нарачаните производи се внесуваат информации
    for (i = 0; i < narachka.n; ++i)
    {
        // char productCode[20];
        // int productPrice, stock;
        // внеси код
        // внеси единицчна цена
        // внеси број на производи во магацин
        char pcode[20];
        int pPrice, stock;
        scanf("%s", &narachka.niza[i].productCode);
        scanf("%d", &narachka.niza[i].productPrice);
        scanf("%d", &narachka.niza[i].stock);
    }
    //за секој производ се внесува колку такви производи се
    //порачани во нарачката
    int j;
    for (j = 0; j < narachka.n; ++j)
    {
        //се внесува број на производи во нарачката
        scanf("%d", &narachka.orderedProduct[j]);
    }

    // повик на функцијата pecatiFaktura
    pecatiFakture(narachka);

    return 0;
}