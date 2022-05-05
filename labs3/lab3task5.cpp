#include <iostream>
#include <cstring>
using namespace std;

class Rabotnik
{
private:
    char ime[30];
    char prezime[30];
    int plata;

public:
    //За оваа класа да се креираат default конструктор и конструктор со аргументи.
    //Да се имплементираат и следните методи:
    // getPlata() која ја враќа платата на работникот
    // pecati() која ги печати името, презимето и платата.
    Rabotnik()
    {
        strcpy(ime, "");
        strcpy(prezime, "");
        plata = 0;
    }
    Rabotnik(char *ime, char *prezime, int plata)
    {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        this->plata = plata;
    }
    void setIme(char *ime)
    {
        strcpy(this->ime, ime);
    }
    void setPrezime(char *prezime)
    {
        strcpy(this->prezime, prezime);
    }
    void setPlata(int _plata)
    {
        plata = _plata;
    }
    int getPlata()
    {
        return plata;
    }
    void print()
    {
        cout << ime << " " << prezime << " " << plata << endl;
    }
};

class Fabrika
{
public:
    Rabotnik workers[100];
    int numberEmployment;

public:
    Fabrika() { numberEmployment = 0; }
    Fabrika(Rabotnik workers[], int numberEmployment)
    {
        this->numberEmployment = numberEmployment;
        for (int i = 0; i < numberEmployment; i++)
        {
            this->workers[i] = workers[i];
        }
    }
    void pecatiVraboteni()
    {
        cout << "Site vraboteni: " << endl;
        for (int i = 0; i < numberEmployment; i++)
        {
            workers[i].print();
        }
    }
    void pecatiSoPlata(int plata)
    {
        cout << "Vraboteni so plata povisoka od " << plata << ":" << endl;
        for (int i = 0; i < numberEmployment; i++)
        {
            if (workers[i].getPlata() >= plata)
            {
                workers[i].print();
            }
        }
    }
};

int main()
{
    char ime[20], prezime[20];
    int plata;
    int n;
    cin >> n;
    Rabotnik r1[100];
    for (int i = 0; i < n; i++)
    {
        cin >> ime;
        cin >> prezime;
        cin >> plata;
        r1[i].setIme(ime);
        r1[i].setPrezime(prezime);
        r1[i].setPlata(plata);
    }

    int min;
    cin >> min;
    Fabrika f1(r1, n);
    f1.pecatiVraboteni();
    f1.pecatiSoPlata(min);

    return 0;
}
