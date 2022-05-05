#include <iostream>
#include <cstring>
using namespace std;

class Gitara
{
private:
    char seriski[25];
    float cena;
    int godina;
    char tip[40];
    void copy(const Gitara &other)
    {
        strcpy(this->tip, other.tip);
        strcpy(this->seriski, other.seriski);
        this->cena = other.cena;
        this->godina = other.godina;
    }

public:
    Gitara(char *tip = "", char *seriski = "", float cena = 0, int godina = 0)
    {
        strcpy(this->tip, tip);
        strcpy(this->seriski, seriski);
        this->cena = cena;
        this->godina = godina;
    }
    Gitara(const Gitara &other)
    {
        copy(other);
    }
    Gitara &operator=(const Gitara &oG)
    {
        if (this != &oG)
        {
            copy(oG);
        }
        return *this;
    }
    ~Gitara() {}
    bool daliIsti(Gitara &g) { return strcmp(this->seriski, g.seriski) == 0; }
    void pecati() { cout << seriski << " " << tip << " " << cena << endl; }
    char *getTip() { return tip; }
    char *getSeriski() { return seriski; }
    int getGodina() { return godina; }
    float getNabavna() { return cena; }
};
class Magacin
{
private:
    char ime[30];
    char lokacija[60];
    Gitara *guitares;
    int brGitari;
    int godinaOtvaranje;

public:
    Magacin(char *ime = "", char *lokacija = "", int godinaOtvaranje = 0)
    {
        strcpy(this->lokacija, lokacija);
        strcpy(this->ime, ime);
        this->godinaOtvaranje = godinaOtvaranje;
        guitares = NULL;
        godinaOtvaranje = 0;
    }
    Magacin(const Magacin &m)
    {
        strcpy(this->lokacija, m.lokacija);
        strcpy(this->ime, m.ime);
        this->godinaOtvaranje = m.godinaOtvaranje;
        guitares = new Gitara[m.brGitari];
        for (int i = 0; i < m.brGitari; i++)
            guitares[i] = m.guitares[i];
        godinaOtvaranje = m.brGitari;
    }

    Magacin &operator=(const Magacin &m)
    {
        delete[] guitares;
        strcpy(this->lokacija, m.lokacija);
        strcpy(this->ime, m.ime);
        this->godinaOtvaranje = m.godinaOtvaranje;
        guitares = new Gitara[m.brGitari];
        for (int i = 0; i < m.brGitari; i++)
            guitares[i] = m.guitares[i];
        godinaOtvaranje = m.brGitari;
        return *this;
    }
    ~Magacin() { delete[] guitares; }
    double vrednost()
    {
        double sum;
        for (int i = 0; i < brGitari; i++)
        {
            sum += guitares[i].getNabavna();
        }
        return sum;
    }
    void dodadi(Gitara d)
    {
        Gitara *tmp = new Gitara[brGitari + 1];
        for (int i = 0; i < brGitari; i++)
        {
            tmp[i] = guitares[i];
        }
        tmp[brGitari++] = d;
        delete[] guitares;
        guitares = tmp;
    }
    void prodadi(Gitara p)
    {
        int j = 0;
        for (int i = 0; i < brGitari; i++)
        {
            if (guitares[i].daliIsti(p) == false)
            {
                guitares[j++] = guitares[i];
            }
        }
        brGitari = j;
        Gitara *tmp = new Gitara[brGitari];
        for (int i = 0; i < brGitari; i++)
        {
            tmp[i] = guitares[i];
        }
        delete[] guitares;
        guitares = tmp;
    }
    void pecati(bool daliNovi)
    {
        cout << ime << " " << lokacija << endl;
        for (int i = 0; i < brGitari; i++)
        {
            if (daliNovi == true && guitares[i].getGodina() > godinaOtvaranje)
            {
                guitares[i].pecati();
            }
            else if (daliNovi == false)
            {
                guitares[i].pecati();
            }
        }
    }
};

int main()
{
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, godina;
    float cena;
    char seriski[50], tip[50];

    if (testCase == 1)
    {
        cout << "===== Testiranje na klasata Gitara ======" << endl;
        cin >> tip;
        cin >> seriski;
        cin >> godina;
        cin >> cena;
        Gitara g(tip, seriski, godina, cena);
        cout << g.getTip() << endl;
        cout << g.getSeriski() << endl;
        cout << g.getGodina() << endl;
        cout << g.getNabavna() << endl;
    }
    else if (testCase == 2)
    {
        cout << "===== Testiranje na klasata Magacin so metodot print() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1");
        kb.pecati(false);
    }
    else if (testCase == 3)
    {
        cout << "===== Testiranje na klasata Magacin so metodot dodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2005);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;
            Gitara g(tip, seriski, godina, cena);
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
    }

    else if (testCase == 4)
    {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2012);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++)
        {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(false);
        kb.prodadi(brisi);
        kb.pecati(false);
    }
    else if (testCase == 5)
    {
        cout << "===== Testiranje na klasata Magacin so metodot prodadi() i pecati(true) ======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++)
        {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            cout << "gitara dodadi" << endl;
            kb.dodadi(g);
        }
        kb.pecati(true);
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        Magacin kb3;
        kb3 = kb;
        kb3.pecati(true);
    }
    else if (testCase == 6)
    {
        cout << "===== Testiranje na klasata Magacin so metodot vrednost()======" << endl;
        Magacin kb("Magacin1", "Lokacija1", 2011);
        cin >> n;
        Gitara brisi;
        for (int i = 0; i < n; i++)
        {
            cin >> tip;
            cin >> seriski;
            cin >> godina;
            cin >> cena;

            Gitara g(tip, seriski, godina, cena);
            if (i == 2)
                brisi = g;
            kb.dodadi(g);
        }
        cout << kb.vrednost() << endl;
        kb.prodadi(brisi);
        cout << "Po brisenje:" << endl;
        cout << kb.vrednost();
        Magacin kb3;
        kb3 = kb;
    }
    return 0;
}
