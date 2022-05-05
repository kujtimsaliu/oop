// In the C programming language to create a Laptop structure for writing specifications to a given laptop.
//  The structure should contain: (5 points)

// Company that produces it (string of 100 characters)
// Monitor size in inches (real number)
// Touch or not (Boolean variable)
// price (integer)
// Create an ITStore structure that contains: (5 points)

// Store Name (string of 100 characters)
// Location (string of 100 characters)
// Array of released laptops (array of up to 100 elements of the Laptop structure)
// Number of elements in the array (integer)
// Create a function to print information for all laptops in one store in the format: (10 points)

// [Store Name] [Location]
// [Mark1] [dim_monitor1] [Cena1]
// [Mark2] [dim_monitor2] [Cena2]
// [Mark3] [dim_monitor3] [Cena3]
// ...
// Create a function najeftina_ponuda, which receives an array of variables such as
//  ITStore and prints the name and location of the store that offers the cheapest
//  laptop and its price.
//  The cheapest laptop is the one that has the lowest price and offer for touch.
//   If there are more stores, print the first one found. * (15 points) *

// Complete the main function (10 points).

// The number of stores is entered from the keyboard, then the name and location are entered for each store,
// then the number of computers, then for each of the computers of the company that produces it, the size of the monitor,
// whether there is a touch and price. Then all the entered stores and the cheapest offer are printed.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct Laptop
{
    char company[100];
    float monitor_size;
    int t;
    int price;
};
typedef struct Laptop Laptop;

struct ITStore
{
    char storeName[100];
    char location[100];
    Laptop released[100];
    int n;
};
typedef struct ITStore ITStore;

void najeftina_ponuda(ITStore s[], int n)
{
    ITStore a;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < s[i].n; j++)
        {
            if (s[i].released->t == 1)
            {
                a = s[i];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s[i].n; j++)
        {
            if (s[j].released->t == 1 && (a.released->price > s[j].released->price))
            {
                a.released->price = s[j].released->price;
            }
        }
    }
    printf("Najeftina ponuda ima prodavnicata:\n%s %s\nNajniskata cena iznesuva: %d", a.storeName, a.location, a.released->price);
}

int main()
{
    ITStore s[100];
    int n;
    scanf("%d", &n); // broj na IT prodavnici

    // vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &s[i].storeName);
        scanf("%s", &s[i].location);
        scanf("%d", &s[i].n);
        for (int j = 0; j < s[i].n; j++)
        {
            scanf("%s", &s[j].released->company);
            scanf("%f", &s[j].released->monitor_size);
            scanf("%d", &s[j].released->t);
            scanf("%d", &s[j].released->price);
        }
    }

    // pecatenje na site prodavnici
    // [Store Name] [Location]
    // [Mark1] [dim_monitor1] [Cena1]
    // [Mark2] [dim_monitor2] [Cena2]
    // [Mark3] [dim_monitor3] [Cena3]
    //
    for (int i = 0; i < n; i++)
    {
        printf("%s %s\n", s[i].storeName, s[i].location);
        for (int j = 0; j < s[i].n; j++)
        {
            printf("%s %.1f %d\n", s[j].released->company, s[j].released->monitor_size, s[j].released->price);
        }
    }

    // povik na glavnata metoda
    najeftina_ponuda(s, n);

    return 0;
}