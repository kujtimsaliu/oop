#include <stdio.h>
#include <ctype.h>

struct Pacient
{
    char ime_prezime[100];
    int osiguran; // 1-da, 0-ne;
    int brojNaPregledi;
} Pacient;
typedef struct Pacient Pacient;

struct MaticenDoktor
{
    char doktorIme[100];
    int brPacienti;
    Pacient pacienti[200];
    float cenaPregled;

} MaticenDoktor;
typedef struct MaticenDoktor MaticenDoktor;

void najuspesen_doktor(MaticenDoktor *maticendoktor, int n)
{
    float sum = 0, temp = 0;
    int flag = 0, r, j, p;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < maticendoktor[i].brPacienti; j++)
        {

            if (maticendoktor[i].pacienti[j].osiguran == 0)
            {
                sum += (float)maticendoktor[i].pacienti[j].brojNaPregledi * maticendoktor[i].cenaPregled;
            }
        }
        if (flag == 0)
        {
            temp = sum;
            flag++
        }
        if (flag != 0)
        {
            if (temp < sum)
            {
                temp = sum;
                r = i;
                p = j;
            }
        }
    }
    printf("Д-р.%s %f %d", maticendoktor[r].doktorIme, temp, maticendoktor[r].pacienti[p].brojNaPregledi);
}

int main()
{
    int n;
    scanf("%d", &n);

    MaticenDoktor maticendoktor[3];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &maticendoktor[i].doktorIme);
        scanf("%d", &maticendoktor[i].brPacienti);
        scanf("%f", &maticendoktor[i].cenaPregled);
        for (int j = 0; j < maticendoktor[i].brPacienti; j++)
        {
            scanf("%s %d %f", &maticendoktor[i].pacienti[i].ime_prezime,
                  &maticendoktor[i].pacienti[i].osiguran,
                  &maticendoktor[i].pacienti[i].brojNaPregledi);
        }
    }
    najuspesen_doktor(maticendoktor, n);

    return 0;
}