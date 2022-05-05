#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

class Lekar
{
protected:
    int faksimil;
    char ime[15];
    char prezime[15];
    double osnovnaPlata;
    void copy(const Lekar &other)
    {
        this->faksimil = other.faksimil;
        strcpy(this->ime, other.ime);
        strcpy(this->prezime, other.prezime);
        this->osnovnaPlata = other.osnovnaPlata;
    }

public:
    Lekar(int faksimil = 0, char *ime = "", char *prezime = "", double osnovnaPlata = 0)
    {
        this->faksimil = faksimil;
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->osnovnaPlata = osnovnaPlata;
    }
    Lekar(const Lekar &l)
    {
        copy(l);
    }
    void pecati()
    {
        cout << this->faksimil << ": " << ime << " " << prezime << endl;
    }
    double plata() { return osnovnaPlata; }
};

class MaticenLekar : public Lekar
{
private:
    int pacienti;
    double *kotizacii;
    void copy(const MaticenLekar &ml)
    {
        this->pacienti = ml.pacienti;
        kotizacii = new double[pacienti];
        for (int i = 0; i < pacienti; i++)
        {
            this->kotizacii[i] = ml.kotizacii[i];
        }
        strcpy(ime, ml.ime);
        strcpy(prezime, ml.prezime);
        osnovnaPlata = ml.osnovnaPlata;
        faksimil = ml.faksimil;
    }

public:
    MaticenLekar() : Lekar()
    {
        pacienti = 0;
        kotizacii = new double[0];
    }
    MaticenLekar(int faksimil, char *ime, char *prezime, double osnovnaPlata, int pacienti,
                 double *kotizacii) : Lekar(faksimil, ime, prezime, osnovnaPlata)
    {
        this->pacienti = pacienti;
        this->kotizacii = new double[pacienti];
        for (int i = 0; i < pacienti; i++)
        {
            this->kotizacii[i] = kotizacii[i];
        }
    }
    MaticenLekar(const Lekar &l, int pacienti, double *kotizacii) : Lekar(l)
    {
        this->pacienti = pacienti;
        this->kotizacii = new double[pacienti];
        for (int i = 0; i < pacienti; i++)
        {
            this->kotizacii[i] = kotizacii[i];
        }
    }
    MaticenLekar(const MaticenLekar &other)
    {
        copy(other);
    }
    MaticenLekar &operator=(const MaticenLekar &ml)
    {
        if (this != &ml)
        {
            delete[] kotizacii;
            copy(ml);
        }
        return *this;
    }
    ~MaticenLekar() { delete[] kotizacii; }
    double Kotizacija()
    {
        double vkupno = 0;
        for (int i = 0; i < pacienti; i++)
        {
            vkupno += kotizacii[i];
        }
        return (vkupno / pacienti);
    }
    double getPlata()
    {
        return osnovnaPlata + (0.3 * Kotizacija());
    }
    void pecati()
    {
        Lekar::pecati();
        cout << "Prosek na kotizacii: " << Kotizacija() << endl;
    }
};

int main()
{
    int n;
    cin >> n;
    int pacienti;
    double kotizacii[100];
    int faksimil;
    char ime[20];
    char prezime[20];
    double osnovnaPlata;

    Lekar *lekari = new Lekar[n];
    MaticenLekar *maticni = new MaticenLekar[n];

    for (int i = 0; i < n; i++)
    {
        cin >> faksimil >> ime >> prezime >> osnovnaPlata;
        lekari[i] = Lekar(faksimil, ime, prezime, osnovnaPlata);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> pacienti;
        for (int j = 0; j < pacienti; j++)
        {
            cin >> kotizacii[j];
        }
        maticni[i] = MaticenLekar(lekari[i], pacienti, kotizacii);
    }

    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        cout << "===TESTIRANJE NA KLASATA LEKAR===" << endl;
        for (int i = 0; i < n; i++)
        {
            lekari[i].pecati();
            cout << "Osnovnata plata na gorenavedeniot lekar e: " << lekari[i].plata() << endl;
        }
    }
    else
    {
        cout << "===TESTIRANJE NA KLASATA MATICENLEKAR===" << endl;
        for (int i = 0; i < n; i++)
        {
            maticni[i].pecati();
            cout << "Platata na gorenavedeniot maticen lekar e: " << maticni[i].plata() << endl;
        }
    }

    delete[] lekari;
    delete[] maticni;

    return 0;
}