#include <iostream>
#include <string.h>
using namespace std;

class OutOfBoundException
{
};
class Karticka
{
protected:
    char smetka[16];
    int pin;
    bool povekjePin;

public:
    Karticka(char *smetka, int pin)
    {
        strcpy(this->smetka, smetka);
        this->pin = pin;
        this->povekjePin = false;
    }
    char *getSmetka()
    {
        return smetka;
    }
    bool getDopolnitelenPin()
    {
        return povekjePin;
    }
    virtual int presmetajTezina()
    {
        int temp, br = 0;
        temp = pin;
        while (temp)
        {
            br++;
            temp /= 10;
        }
        return br;
    }

    friend ostream &operator<<(ostream &out, Karticka &k)
    {
        out << k.getSmetka() << ": " << k.presmetajTezina() << endl;
        return out;
    }
    virtual ~Karticka() {}
};

class SpecijalnaKarticka : public Karticka
{
private:
    int *dopolnitelni;
    int brKodovi;
    const int P = 4;

public:
    SpecijalnaKarticka(char *smetka, int pin) : Karticka(smetka, pin)
    {
        brKodovi = 0;
        dopolnitelni = new int[0];
        povekjePin = true;
    }
    const int getP()
    {
        return P;
    }
    int presmetajTezina()
    {
        int t1 = Karticka::presmetajTezina();
        return t1 + brKodovi;
    }
    SpecijalnaKarticka &operator+=(int novPin)
    {
        int *temp;
        temp = new int[brKodovi + 1];
        for (int i = 0; i < brKodovi; i++)
        {
            temp[i] = dopolnitelni[i];
        }
        temp[brKodovi] = novPin;
        brKodovi++;
        delete[] dopolnitelni;
        dopolnitelni = temp;
        return *this;
    }
    int getBrKodovi()
    {
        return brKodovi;
    }

    ~SpecijalnaKarticka() {}
};

class Banka
{
private:
    char naziv[30];
    Karticka *karticki[20];
    int broj;
    static int LIMIT;

public:
    Banka(char *naziv, Karticka **karticki, int broj)
    {
        strcpy(this->naziv, naziv);
        for (int i = 0; i < broj; i++)
        {
            if (karticki[i]->getDopolnitelenPin())
            {
                this->karticki[i] = new SpecijalnaKarticka(*dynamic_cast<SpecijalnaKarticka *>(karticki[i]));
            }
            else
                this->karticki[i] = new Karticka(*karticki[i]);
        }
        this->broj = broj;
    }
    ~Banka()
    {
        for (int i = 0; i < broj; i++)
            delete karticki[i];
    }

    static void setLIMIT(int l)
    {
        LIMIT = l;
    }

    void pecatiKarticki()
    {
        cout << "Vo bankata " << naziv << " moze da se probijat kartickite:" << endl;
        for (int i = 0; i < broj; i++)
        {
            if (karticki[i]->presmetajTezina() <= LIMIT)
            {
                cout << *karticki[i];
            }
        }
    }

    void dodadiDopolnitelenPin(char *smetka, int novPin)
    {
        for (int i = 0; i < broj; i++)
        {
            bool flag = false;
            int index;
            if (strcmp(karticki[i]->getSmetka(), smetka) == 0)
            {
                flag = true;
                index = i;
                // break;
            }
            if (flag)
            {
                SpecijalnaKarticka *sk = dynamic_cast<SpecijalnaKarticka *>(karticki[index]);
                if (sk != 0)
                {
                    if (sk->getBrKodovi() >= sk->getP())
                        throw OutOfBoundException();
                    *sk += novPin;
                }
            }
        }
    }
};
int Banka::LIMIT = 7;

int main()
{

    Karticka **niza;
    int n, m, pin;
    char smetka[16];
    bool daliDopolnitelniPin;
    cin >> n;
    niza = new Karticka *[n];
    for (int i = 0; i < n; i++)
    {
        cin >> smetka;
        cin >> pin;
        cin >> daliDopolnitelniPin;
        if (!daliDopolnitelniPin)
            niza[i] = new Karticka(smetka, pin);
        else
            niza[i] = new SpecijalnaKarticka(smetka, pin);
    }

    Banka komercijalna("Komercijalna", niza, n);
    for (int i = 0; i < n; i++)
        delete niza[i];
    delete[] niza;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> smetka >> pin;
        try
        {
            komercijalna.dodadiDopolnitelenPin(smetka, pin);
        }
        catch (OutOfBoundException)
        {
            cout << "Brojot na pin kodovi ne moze da go nadmine dozvolenoto";
        }
    }

    Banka::setLIMIT(5);

    komercijalna.pecatiKarticki();
}