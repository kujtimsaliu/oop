#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Tanc
{
    char ime[15], zemja[15];
};
typedef struct Tanc Tanc;

struct Tancer
{
    char ime[20], prezime[20];
    Tanc niza[5];
};
typedef struct Tancer Tancer;

void tancuvanje(Tancer *t, int n, char *zemja)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (strcmp(t[i].niza[j].zemja, zemja) == 0)
            {
                printf("%s %s, %s\n", t[i].ime, t[i].prezime, t[i].niza[j].zemja);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    Tancer tancer[20];

    for (int i = 0; i < n; i++)
    {
        scanf("%s", &tancer[i].ime);
        scanf("%s", &tancer[i].prezime);
        for (int j = 0; j < 3; j++)
        {
            scanf("%s", &tancer[i].niza[j].ime);
            scanf("%s", &tancer[i].niza[j].zemja);
        }
    }
    char zemja[15];
    scanf("%s", &zemja);
    tancuvanje(tancer, n, zemja);

    return 0;
}