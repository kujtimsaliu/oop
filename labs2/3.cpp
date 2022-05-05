
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//  vashiot kod ovde ppp
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
    void setName(char *i)
    {
        strcpy(ime, i);
    }
    void setReziser(char *r)
    {
        strcpy(reziser, r);
    }
    void setZanr(char *z)
    {
        strcpy(zanr, z);
    }
    void setGodina(int g)
    {
        godina = g;
    }
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
    int getGodina()
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
        int s = f[i].getGodina();
        if (godina == f[i].getGodina())
        {
            f[i].pecati();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    // da se inicijalizira niza od objekti od klasata Film
    Film fs[100];
    for (int i = 0; i < n; ++i)
    {
        char ime[100];
        char reziser[50];
        char zanr[50];
        int godina;
        cin >> ime;
        cin >> reziser;
        cin >> zanr;
        cin >> godina;
        // da se kreira soodveten objekt
        fs[i].setName(ime);
        fs[i].setReziser(reziser);
        fs[i].setZanr(zanr);
        fs[i].setGodina(godina);
    }

    int godina;
    cin >> godina;
    // da se povika funkcijata pecati_po_godina
    pecati_po_godina(fs, n, godina);
    return 0;
}