#include <iostream>
#include <cstring>
#include <ctype.h>
using namespace std;

enum TIP
{
    pop,
    rap,
    rok
};

class Pesna
{
private:
    char *ime{nullptr};
    int duration{0};
    TIP tip;

    void copy(const Pesna &other)
    {
        this->ime = new char[strlen(other.ime) + 1];
        strcpy(this->ime, other.ime);
        this->duration = other.duration;
        this->tip = other.tip;
    }

public:
    Pesna(char *ime = "", int duration = 0, TIP tip = pop)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->duration = duration;
        this->tip = tip;
    }
    Pesna(const Pesna &other)
    {
        copy(other);
    }
    Pesna operator=(const Pesna &oPesna)
    {
        if (this != &oPesna)
        {
            copy(oPesna);
        }
        return *this;
    }
    void pecati()
    {
        cout << "\"" << ime << "\"-" << duration << "min" << endl;
    }
    int getDuration()
    {
        return duration;
    }
    TIP getTip()
    {
        return tip;
    }
};
class CD
{
private:
    Pesna niza[10];
    int pesniBroj;
    int maxDuration;

public:
    CD(int maxDuration)
    {
        this->pesniBroj = 0;
        this->maxDuration = maxDuration;
    }

    int hasSpace(Pesna p)
    {
        int sum = 0;
        for (int i = 0; i < pesniBroj; i++)
        {
            sum += niza[i].getDuration();
        }
        sum += p.getDuration();
        if (sum < maxDuration)
        {
            return 1;
        }
        else
            return 0;
    }

    void dodadiPesna(Pesna p)
    {
        if (pesniBroj <= 10)
        {
            if (hasSpace(p))
            {
                niza[pesniBroj++] = p;
            }
        }
    }
    void pecatiPesniPoTip(TIP t)
    {
        for (int i = 0; i < pesniBroj; i++)
        {
            if (t == niza[i].getTip())
            {
                niza[i].pecati();
            }
        }
    }
    Pesna getPesna(int i)
    {
        return niza[i];
    }
    int getBroj()
    {
        return pesniBroj;
    }
};

int main()
{
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if (testCase == 1)
    {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; // se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime, minuti, (TIP)kojtip);
        p.pecati();
    }
    else if (testCase == 2)
    {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; // se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (TIP)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < n; i++)
            (omileno.getPesna(i)).pecati();
    }
    else if (testCase == 3)
    {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; // se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (TIP)kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    }
    else if (testCase == 4)
    {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; // se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (TIP)kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((TIP)kojtip);
    }
    else if (testCase == 5)
    {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; // se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (TIP)kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((TIP)kojtip);
    }

    return 0;
}