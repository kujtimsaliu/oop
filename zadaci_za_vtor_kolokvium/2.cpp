// vashiot kod ovde

#include <iostream>
#include <cstring>
using namespace std;

class Vozac
{
protected:
    char ime[100];
    int vozrast;
    int trki;
    bool vet;

public:
    Vozac(char *ime, int vozrast, int trki, bool vet)
    {
        strcpy(this->ime, ime);
        this->vozrast = vozrast;
        this->trki = trki;
        this->vet = vet;
    }

    virtual double earnings() = 0;
    virtual double danok() = 0;

    friend ostream &operator<<(ostream &out, Vozac &v)
    {
        out << v.ime << endl
            << v.vozrast << endl
            << v.trki << endl;
        if (v.vet)
            out << "VETERAN" << endl;
        return out;
    }
    bool operator==(Vozac &v)
    {
        return (this->earnings() == v.earnings());
    }
};

class Avtomobilist : public Vozac
{
private:
    double cena;

public:
    Avtomobilist(char *ime, int vozrast, int trki, bool vet, double cena)
        : Vozac(ime, vozrast, trki, vet)
    {
        this->cena = cena;
    }
    double danok()
    {
        return (this->trki > 10 ? earnings() * 0.15 : earnings() * 0.10);
    }
    double earnings()
    {
        return this->cena / 5;
    }
};

class Motociklist : public Vozac
{
private:
    int power;

public:
    Motociklist(char *ime, int vozrast, int trki, bool vet, int power)
        : Vozac(ime, vozrast, trki, vet)
    {
        this->power = power;
    }
    double danok()
    {
        return (vet ? earnings() * 0.25 : earnings() * 0.20);
    }
    double earnings()
    {
        return this->power * 20;
    }
};
int soIstaZarabotuvachka(Vozac **v, int n, Vozac *vx)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (vx->earnings() == v[i]->earnings())
            num++;
    }
    return num;
}

int main()
{
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac *[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for (int i = 0; i < n; ++i)
    {
        cin >> ime >> vozrast >> trki >> vet;
        if (i < x)
        {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        }
        else
        {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for (int i = 0; i < n; ++i)
    {
        delete v[i];
    }
    delete[] v;
    delete vx;
    return 0;
}