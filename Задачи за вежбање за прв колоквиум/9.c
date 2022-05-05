#include <stdio.h>
struct Film
{
    char name[100];
    int time;
    float price;
    int discount;
};
typedef struct Film Film;
struct FilmFestival
{
    char name[100];
    char place[100];
    Film films[100];
    int no;
};
typedef struct FilmFestival FilmFestival;
void print(FilmFestival f)
{
    printf("%s %s\n", f.name, f.place);
    for (int i = 0; i < f.no; i++)
    {
        printf("%s %d %.2f\n", f.films[i].name, f.films[i].time, f.films[i].price);
    }
}
void bestFestival(FilmFestival *f, int n)
{
    // Filmfestival festival[100];
    // first condition -> discount
    // if same discount then duration of films KLLAK
    int count = 0;
    int flag = 0;
    int presentcount = 0;
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        // if (f[i].films->discount == 1){
        //     count++;
        // }

        for (int j = 0; j < f[i].no; j++)
        {

            if (f[i].films[j].discount == 1)
            {
                count++;
            }
        }
        if (flag = 0)
        {
            presentcount = count;
            flag++;
        } // ka me e assign in the first loop masane ska me hy ktu hiq nice maybe prollu
        if (flag != 0)
        {
            if (presentcount < count)
            {
                presentcount = count;
                temp = i;
            }
        }
    } // veq ta shoh a ka me rrok diku afer a kun hiq
    printf("Najdobar festival: %s %s", f[temp].name, f[temp].place);
    // printf("\n%d", count);
}
int main()
{
    int i, j, n, broj;
    FilmFestival ff[50];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        /* name of the festival */
        scanf("%s", ff[i].name);
        /* place it is held */
        scanf("%s", ff[i].place);
        /* number of movies */
        scanf("%d", &ff[i].no);

        for (j = 0; j < ff[i].no; j++)
        {
            scanf("%s", ff[i].films[j].name);      /* title of the movie */
            scanf("%d", &ff[i].films[j].time);     /* duration */
            scanf("%f", &ff[i].films[j].price);    /* price */
            scanf("%d", &ff[i].films[j].discount); /* discount */
        }
    }

    for (i = 0; i < n; ++i)
    {
        print(ff[i]); // mduket se sduhet me ff[i] print(ff, n) smth like this ??
    }
    // we ska error nice
    bestFestival(ff, n); // duhet me e ba ni func best festival

    return 0;
}