#include <stdio.h>
#include <ctype.h>

struct Pacient
{
    char ime_prezime[100];
    int osiguran; // 1-da, 0-ne;
    int brojNaPregledi;
};
typedef struct Pacient Pacient;

struct MaticenDoktor
{
    char doktorIme[100];
    int brPacienti;
    Pacient pacienti[200];
    float cenaPregled;
};
typedef struct MaticenDoktor MaticenDoktor;

void najuspesen_doktor(MaticenDoktor *maticendoktor, int n)
{
    float sum = 0, temp = 0;
    int flag = 0, r, j, p, i_p;
    for (int i = 0; i < n; i++)
    {
        for (j = 0; j < maticendoktor[i].brPacienti; j++)
        {

            if (maticendoktor[i].pacienti[j].osiguran == 0)
            {
                sum = (float)maticendoktor[i].pacienti[j].brojNaPregledi * maticendoktor[i].cenaPregled;
            }
        }
        if (flag == 0)
        {
            temp = sum;
            r = i;
            p = j - 1;
            i_p = maticendoktor[i].pacienti[j - 1].brojNaPregledi;
            flag++;
        }
        if (flag != 0)
        {
            if (temp < sum)
            {
                temp = sum;
                r = i;
                p = j - 1;
                i_p = maticendoktor[i].pacienti[j - 1].brojNaPregledi;
            }
            else if (temp == sum)
            {
                if (maticendoktor[i].pacienti[p].brojNaPregledi > maticendoktor[i - 1].pacienti[i_p].brojNaPregledi)
                {
                    temp = sum;
                    r = i;
                    p = j - 1;
                    i_p = maticendoktor[i].pacienti[j - 1].brojNaPregledi;
                }
                else
                {
                }
            }
        }
    }
    printf("%s %.2f %d", maticendoktor[r].doktorIme, temp, maticendoktor[r].pacienti[p].brojNaPregledi);
}

int main()
{
    int i, j, n, broj;
    MaticenDoktor md[200];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        // ime na doktor
        scanf("%s", &md[i].doktorIme);
        // broj na pacienti
        scanf("%d", &md[i].brPacienti);
        // cena na pregled
        scanf("%f", &md[i].cenaPregled);

        for (j = 0; j < md[i].brPacienti; j++)
        {
            scanf("%s", &md[i].pacienti[j].ime_prezime);
            scanf("%d", &md[i].pacienti[j].osiguran);
            scanf("%d", &md[i].pacienti[j].brojNaPregledi);
        }
    }
    najuspesen_doktor(md, n);

    return 0;
}