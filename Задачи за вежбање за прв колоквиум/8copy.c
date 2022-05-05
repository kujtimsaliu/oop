#include <stdio.h>
#include <ctype.h>

struct Laptop
{
    char firma[100];
    float size;
    int isTouch, cena;
};
typedef struct Laptop Laptop;

struct ITStore
{
    char nameProdavnica[100], lokacija[100];
    Laptop niza[100];
    int brojLaptop;
};
typedef struct ITStore ITStore;

void print(ITStore is[100], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %s\n", is[i].nameProdavnica, is[i].lokacija);
        for (int j = 0; j < is[i].brojLaptop; j++)
        {
            printf("%s ", is[i].niza[j].firma);

            // float x=4.3;
            // int t=x;
            // float t1 = x - t;

            float var1 = is[i].niza[j].size;
            int tmp = (int)var1;
            float var2 = var1 - tmp;
            if (var2 == 0)
            {
                printf("%.0f ", is[i].niza[j].size);
            }
            else
            {
                printf("%.1f ", is[i].niza[j].size);
            }

            printf("%d\n", is[i].niza[j].cena);
        }
    }
}

void najeftina_ponuda(ITStore is[100], int n)
{
    int temp = 0;
    int najeftin = 999999;
    int i_index = 0, j_index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < is[i].brojLaptop; j++)
        {
            if (is[i].niza[j].isTouch)
            {
                if (is[i].niza[j].cena < najeftin)
                {
                    najeftin = is[i].niza[j].cena;
                    i_index = i;
                    j_index = j;
                }
            }
        }
    }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\n", is[i_index].nameProdavnica, is[i_index].lokacija);
    printf("Najniskata cena iznesuva: %d", is[i_index].niza[j_index].cena);
}

int main()
{
    int n;
    scanf("%d", &n);
    ITStore is[100];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &is[i].nameProdavnica);
        scanf("%s", &is[i].lokacija);
        scanf("%d", &is[i].brojLaptop);

        for (int j = 0; j < is[i].brojLaptop; j++)
        {
            scanf("%s", &is[i].niza[j].firma);
            scanf("%f", &is[i].niza[j].size);
            scanf("%d", &is[i].niza[j].isTouch);
            scanf("%d", &is[i].niza[j].cena);
        }
    }

    print(is, n);
    najeftina_ponuda(is, n);

    return 0;
}