#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Film
{
private:
    char ime[100];
    char reziser[50];
    char zanr[50];
    int godina;

public:
    Film()
    {
        strcpy(ime, "");
        strcpy(reziser, "");
        strcpy(zanr, "");
        godina = 0;
    }
    Film(char *i, char *r, char *z, int g)
    {
        strcpy(ime, i);
        strcpy(reziser, r);
        strcpy(zanr, z);
        godina = g;
    }
    // set values
    void setName(char *n)
    {
        strcpy(ime, n);
    }
    void setReziser(char *r)
    {
        strcpy(reziser, r);
    }
    void setZanr(char *z)
    {
        strcpy(zanr, z);
    }
    void setYear(int g)
    {
        godina = g;
    }
    // get values
    char getName()
    {
        return *ime;
    }
    char getReziser()
    {
        return *reziser;
    }
    char getZanr()
    {
        return *zanr;
    }
    int getYear()
    {
        return godina;
    }
    void pecati()
    {
        cout << "Ime: " << ime << endl;
        cout << "Reziser: " << reziser << endl;
        cout << "Zanr: " << zanr << endl;
        cout << "Godina: " << godina << endl;
    }
};

void pecati_po_godina(Film *f, int n, int godina)
{
    for (int i = 0; i < n; i++)
    {
        if (f[i].getYear() == godina)
        {
            f[i].pecati();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Film f[100];
    for (int i = 0; i < n; i++)
    {
        char name[100];
        char reziser[50];
        char zanr[50];
        int godina;
        cin >> name;
        cin >> reziser;
        cin >> zanr;
        cin >> godina;
        // read the values to the private attributes in the class Film
        // using set_value functions
        f[i].setName(name);
        f[i].setReziser(reziser);
        f[i].setZanr(zanr);
        f[i].setYear(godina);
    }
    int godina;
    cin >> godina;
    // cal the pecati_po_godina function
    pecati_po_godina(f, n, godina);
}