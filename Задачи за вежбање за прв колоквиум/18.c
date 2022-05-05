#include <stdio.h>
#include <ctype.h>
#include <string.h>

struct SkiLift
{
    char imeSkiLift[15];
    int maxbr;
    int isWorking;
};

typedef struct SkiLift SkiLift;

struct SkiCenter
{
    char imeSkiCentar[15];
    char country[20];
    SkiLift niza[20];
    int broj;
};
typedef struct SkiCenter SkiCenter;

int kapacitet(SkiCenter sc)
{
    int i, vkupno = 0;
    for (i = 0; i < sc.broj; i++)
    {
        if (sc.niza[i].isWorking == 1)
        {
            vkupno += sc.niza[i].maxbr;
        }
    }
    return vkupno;
}

void najgolemKapacitet(SkiCenter *sc, int n)
{
    int cap = 0, i_sl = 0, flag = 0, temp, total = 0, max = 0, temp2;

    for (int i = 0; i < n; i++)
    {
        temp = kapacitet(sc[i]);
        if (temp > max)
        {
            max = temp;
            temp2 = i;
        }
        else if (temp == max)
        {
            if (sc[i - 1].broj > sc[i].broj)
            {
                continue;
            }
            else
            {
                max = temp;
                temp2 = i;
            }
        }
    }
    printf("%s\n%s\n%d", sc[temp2].imeSkiCentar, sc[temp2].country, temp);
}

int main()
{
    int n;
    scanf("%d", &n);
    SkiCenter skicenter[20];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &skicenter[i].imeSkiCentar);
        scanf("%s", &skicenter[i].country);
        scanf("%d", &skicenter[i].broj);
        for (int j = 0; j < skicenter[i].broj; j++)
        {
            scanf("%s", &skicenter[i].niza[j].imeSkiLift);
            scanf("%d", &skicenter[i].niza[j].maxbr);
            scanf("%d", &skicenter[i].niza[j].isWorking);
        }
    }
    najgolemKapacitet(skicenter, n);
    return 0;
}