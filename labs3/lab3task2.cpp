#include <iostream>
#include <cstring>

using namespace std;

class Potpisuvac
{
private:
    char ime[20];
    char prezime[20];
    char embg[14];

public:
    // default cnstrctor
    Potpisuvac()
    {
        strcpy(ime, "");
        strcpy(prezime, "");
        strcpy(embg, "");
    }
    Potpisuvac(char *ime, char *prezime, char *embg)
    {
        strcpy(this->ime, ime);
        strcpy(this->prezime, prezime);
        strcpy(this->embg, embg);
    }
    Potpisuvac(const Potpisuvac &p9)
    {
        strcpy(ime, p9.ime);
        strcpy(prezime, p9.prezime);
        strcpy(embg, p9.embg);
    }
    char *getEmbg()
    {
        return embg;
    }
};
class Dogovor
{
private:
    int broj;
    char kategorija[50];
    Potpisuvac p[3];

public:
    Dogovor() {}
    Dogovor(int broj, char *kategorija, Potpisuvac _p[])
    {
        this->broj = broj;
        strcpy(this->kategorija, kategorija);
        for (int i = 0; i < 3; i++)
        {
            p[i] = _p[i];
        }
    }
    bool proverka()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 3; j++)
            {
                if (strcmp(p[i].getEmbg(), p[j].getEmbg()) == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// ne smee da se menuva main funkcijata
int main()
{
    char embg[14], ime[20], prezime[20], kategorija[20];
    int broj, n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> embg >> ime >> prezime;
        Potpisuvac p1(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p2(ime, prezime, embg);
        cin >> embg >> ime >> prezime;
        Potpisuvac p3(ime, prezime, embg);
        cin >> broj >> kategorija;
        Potpisuvac p[3];
        p[0] = p1;
        p[1] = p2;
        p[2] = p3;
        Dogovor d(broj, kategorija, p);
        cout << "Dogovor " << broj << ":" << endl;
        if (d.proverka() == true)
            cout << "Postojat potpishuvaci so ist EMBG" << endl;
        else
            cout << "Ne postojat potpishuvaci so ist EMBG" << endl;
    }
    return 0;
}