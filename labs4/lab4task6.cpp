#include <iostream>
#include <cstring>
using namespace std;

enum Tip
{
    LINUX,
    UNIX,
    WINDOWS
};
class OperativenSistem
{
private:
    char *ime;
    float verzija;
    Tip tip;
    float golemina;
    void copy(const OperativenSistem &other)
    {
        this->ime = new char[strlen(other.ime) + 1];
        strcpy(this->ime, other.ime);
        this->verzija = other.verzija;
        this->golemina = other.golemina;
        this->tip = other.tip;
    }

public:
    OperativenSistem()
    {
        this->ime = nullptr;
        verzija = 0;
        tip = (Tip)0;
        golemina = 0;
    }
    OperativenSistem(char *ime, float verzija, Tip tip, float golemina)
    {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->verzija = verzija;
        this->golemina = golemina;
        this->tip = tip;
    }
    // copy-constructor;
    OperativenSistem(const OperativenSistem &other)
    {
        copy(other);
    }
    OperativenSistem &operator=(const OperativenSistem &oSistem)
    {
        if (this != &oSistem)
        {
            delete[] ime;
            copy(oSistem);
        }
        return *this;
    }

    void pecati()
    {
        cout << "Ime: " << this->ime << " Verzija: " << this->verzija << " Tip: " << this->tip << " Golemina:" << this->golemina << "GB" << endl;
    }
    bool ednakviSe(const OperativenSistem &os)
    {
        if (strcmp(this->ime, os.ime) == 0)
        {
            if (this->verzija == os.verzija)
            {
                if (this->tip == os.tip)
                {
                    if (this->golemina == os.golemina)
                    {

                        return true;
                    }
                }
            }
        }
        else
        {
            return false;
        }
        // return ((strcmp(this->ime, os.ime) == 0) && (this->verzija == os.verzija) && (this->tip == os.tip) && (this->golemina == os.golemina));
    }
    int sporediVerzija(const OperativenSistem &os)
    {
        if (this->verzija == os.verzija)
        {
            return 0;
        }
        else if (this->verzija < os.verzija)
        {
            return -1;
        }
        else
            return 1;
    }
    bool istaFamilija(const OperativenSistem &sporedba)
    {
        return ((strcmp(this->ime, sporedba.ime) == 0) && this->tip == sporedba.tip);
    }
    ~OperativenSistem() { delete[] ime; }
    // friend void izbrishi(const OperativenSistem &operativenSistem);
};

class Repozitorium
{
private:
    char repoName[20];
    OperativenSistem *os;
    int repoBroj;

public:
    Repozitorium(const char *ime)
    {
        strcpy(this->repoName, ime);
    }
    Repozitorium(char *repoName = "", OperativenSistem *os = NULL, int repoBroj = 0)
    {
        strcpy(this->repoName, repoName);
        this->repoBroj = repoBroj;
        this->os = new OperativenSistem[repoBroj];
        for (int i = 0; i < repoBroj; i++)
        {
            this->os[i] = os[i];
        }
    }
    Repozitorium(const Repozitorium &other)
    {
        strcpy(this->repoName, other.repoName);
        this->repoBroj = other.repoBroj;
        this->os = new OperativenSistem[other.repoBroj];
        for (int i = 0; i < other.repoBroj; i++)
        {
            this->os[i] = other.os[i];
        }
    }
    Repozitorium &operator=(const Repozitorium &repo)
    {
        if (this != &repo)
        {
            delete[] os;
            strcpy(this->repoName, repo.repoName);
            this->repoBroj = repo.repoBroj;
            this->os = new OperativenSistem[repo.repoBroj];
            for (int i = 0; i < repo.repoBroj; i++)
            {
                this->os[i] = repo.os[i];
            }
        }
        return *this;
    }
    ~Repozitorium() { delete[] os; }

    void pecatiOperativniSistemi()
    {
        cout << "Repozitorium: " << repoName << endl;

        for (int i = 0; i < repoBroj; i++)
        {
            os[i].pecati();
        }
    }
    void izbrishi(const OperativenSistem &operativenSistem)
    {
        bool flag = false;
        for (int i = 0; i < repoBroj; i++)
        {
            if (os[i].ednakviSe(operativenSistem))
            {
                flag = true;
            }
            if (flag)
            {
                for (int j = i; j < repoBroj - 1; j++)
                {
                    this->os[j] = this->os[j + 1];
                }
                break;
            }
        }
    }
    void dodadi(const OperativenSistem &nov)
    {
        bool flag = true;
        for (int i = 0; i < repoBroj; i++)
        {
            if (os[i].istaFamilija(nov))
            {
                this->os[i] = nov;
                flag = false;
            }
        }
        if (flag)
        {
            OperativenSistem *temp = new OperativenSistem[repoBroj + 1];
            for (int i = 0; i < repoBroj; i++)
            {
                temp[i] = this->os[i];
            }
            temp[repoBroj++] = nov;
            delete[] os;
            this->os = temp;
        }
    }
};

int main()
{
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++)
    {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip)tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}