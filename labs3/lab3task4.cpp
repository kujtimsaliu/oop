
// vasiot kod ovde
#include <iostream>
#include <cstring>
using namespace std;

class Masa
{
private:
    int dolzina;
    int sirina;

public:
    // contructor wiht and without parameters
    // also pecati() metoda
    Masa()
    {
        sirina = 1;
        dolzina = 1;
    }
    Masa(int sirina, int dolzina)
    {
        this->sirina = sirina;
        this->dolzina = dolzina;
    }
    void print()
    {
        cout << "Masa: " << sirina << " " << dolzina << endl;
    }
};

class Soba
{
private:
    Masa masa;
    int sobaSirina;
    int sobaDolzina;

public:
    // contructor wiht and without parameters
    // also pecati() metoda
    Soba()
    {
        sobaDolzina = 1;
        sobaDolzina = 1;
    }
    Soba(int sobaS, int sobaD, Masa _m)
    {
        sobaSirina = sobaS;
        sobaDolzina = sobaD;
        masa = _m;
    }
    void pecati()
    {
        cout << "Soba: ";
        cout << sobaSirina << " " << sobaDolzina << " ";
        masa.print();
    }
};

class Kukja
{
private:
    Soba soba;
    char adresa[50];

public:
    // конструктор со и без параметри,
    // деструктор и метода pecati()
    // во која се повикува и pecati() за објектот Soba.
    Kukja()
    {
        strcpy(adresa, "");
    }
    Kukja(Soba s, char *_adresa)
    {
        soba = s;
        strcpy(adresa, _adresa);
    }
    void pecati()
    {
        cout << "Adresa: " << adresa << " ";
        soba.pecati();
    }

    ~Kukja() {}
};

// ne smee da se menuva main funkcijata!
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int masaSirina, masaDolzina;
        cin >> masaSirina;
        cin >> masaDolzina;
        Masa m(masaSirina, masaDolzina);
        int sobaSirina, sobaDolzina;
        cin >> sobaSirina;
        cin >> sobaDolzina;
        Soba s(sobaSirina, sobaDolzina, m);
        char adresa[30];
        cin >> adresa;
        Kukja k(s, adresa);
        k.pecati();
    }

    return 0;
}