#include <stdio.h>
#include <string.h>
typedef struct RabotnaNedela
{
    int rabotniCasovi[5];
    int broj;
} RabotnaNedela;

typedef struct Rabotnik
{
    char ime[50];
    RabotnaNedela niza[4];
} Rabotnik;

int maxNedela(Rabotnik *r)
{
    int i, j, broj;
    int vkupno = 0, max = 0;
    for (i = 0; i < 4; i++)
    {
        vkupno = 0;
        for (j = 0; j < 5; j++)
        {
            vkupno += r->niza[i].rabotniCasovi[j];
        }
        if (vkupno > max)
        {
            max = vkupno;
            broj = i + 1;
        }
    }
    return broj;
}
void table(Rabotnik *r, int n)
{
    int i, j, m, vkupno = 0, temp = 0;
    printf("Rab\t");
    for (int i = 0; i < 4; i++)
    {
        printf("%d\t", i + 1);
    }
    printf("Vkupno\n");
    for (i = 0; i < n; i++)
    {
        vkupno = 0;
        temp = 0;
        printf("%s\t", r[i].ime);
        for (j = 0; j < 4; j++)
        {
            vkupno = 0;
            for (m = 0; m < 5; m++)
            {
                vkupno += r[i].niza[j].rabotniCasovi[m];
            }
            printf("%d\t", vkupno);
            temp += vkupno;
        }
        printf("%d\n", temp);
    }
}
int main()
{
    int i, j, n, m;
    scanf("%d", &n);
    Rabotnik r[20];
    for (i = 0; i < n; i++)
    {
        scanf("%s", r[i].ime);
        for (j = 0; j < 4; j++)
        {
            for (m = 0; m < 5; m++)
            {
                scanf("%d", &r[i].niza[j].rabotniCasovi[m]);
            }
        }
    }
    printf("TABLE\n");
    table(r, n);
    printf("MAX NEDELA NA RABOTNIK: %s\n", r[n / 2].ime);
    printf("%d\n", maxNedela(&r[n / 2]));
}