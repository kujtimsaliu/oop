#include <iostream>
#include <cstring>
using namespace std;

class Automobile
{
private:
    char *marka;
    int *registracija;
    int brzina;

public:
    Automobile()
    {
        this->registracija = new int[5];
        this->brzina = 0;
    }
    Automobile(char *marka, int *registracija, int brzina)
    {
        this->marka = new char[strlen(marka) + 1];
        strcpy(this->marka, marka);
        this->registracija = new int[5];
        for (int i = 0; i < 5; i++)
        {
            this->registracija[i] = registracija[i];
        }
        this->brzina = brzina;
    }
    bool operator==(const Automobile &a)
    {
        for (int i = 0; i < 5; i++)
        {
            if (this->registracija[i] != a.registracija[i])
            {
                return false;
            }
        }
        return true;
    }
    friend ostream &operator<<(ostream &out, Automobile &a)
    {
        out << "Marka\t" << a.marka << "\tRegistracija[ ";
        for (int i = 0; i < 5; i++)
        {
            out << a.registracija[i] << " ";
        }
        out << "]" << endl;
        return out;
    }
    int getBrzina()
    {
        return brzina;
    }
};

class RentACar
{
private:
    char ime[100];
    Automobile *niza;
    int size;

public:
    RentACar(char *ime)
    {
        strcpy(this->ime, ime);
        this->size = 0;
        this->niza = new Automobile[size];
    }
    RentACar &operator+=(Automobile a)
    {
        Automobile *tmp = new Automobile[size + 1];
        for (int i = 0; i < size; i++)
        {
            tmp[i] = niza[i];
        }
        if (size)
        {
            delete[] niza;
        }
        tmp[size++] = a;
        niza = tmp;
        return *this;
    }
    // try the other way here - Reminder
    // RentACar &operator-=(Automobile &a)
    // {
    //     int deleteIdx = size;
    //     for (int i = 0; i < size; i++)
    //         if (niza[i] == a)
    //             deleteIdx = i;
    //     if (deleteIdx == size)
    //         return *this;
    //     for (int i = deleteIdx; i < size - 1; i++)
    //         niza[i] = niza[i + 1];
    //     size--;
    //     return *this;
    // }
    RentACar &operator-=(Automobile &a)
    {
        int j = 0;
        Automobile *tmp = new Automobile[size];
        for (int i = 0; i < size; i++)
        {
            if (niza[i] == a)
                continue;
            else
                tmp[j++] = niza[i];
        }
        size = j;
        delete[] niza;
        niza = tmp;
        return *this;
    }
    void pecatiNadBrzina(int max)
    {
        cout << ime << endl;
        for (int i = 0; i < size; i++)
        {
            if (niza[i].getBrzina() > max)
                cout << niza[i];
        }
    }
};

int main()
{
    RentACar agencija("FINKI-Car");
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char marka[100];
        int regisracija[5];
        int maximumBrzina;

        cin >> marka;

        for (int i = 0; i < 5; i++)
            cin >> regisracija[i];

        cin >> maximumBrzina;

        Automobile nov = Automobile(marka, regisracija, maximumBrzina);

        // dodavanje na avtomobil
        agencija += nov;
    }
    // se cita grehsniot avtmobil, za koj shto avtmobilot so ista registracija treba da se izbrishe
    char marka[100];
    int regisracija[5];
    int maximumBrzina;
    cin >> marka;
    for (int i = 0; i < 5; i++)
        cin >> regisracija[i];
    cin >> maximumBrzina;

    Automobile greshka = Automobile(marka, regisracija, maximumBrzina);

    // brishenje na avtomobil
    agencija -= greshka;

    agencija.pecatiNadBrzina(150);

    return 0;
}