#include <iostream>
#include <cstring>

using namespace std;

// Vasiot kod tuka

/*
 * Да се дефинира класа Pica за која ќе се чуваат податоци за:

име на пицата (низа од 15 знаци)
цена (цел број)
состојки (динамички алоцирана низа од знаци)
намалување на цената во проценти (цел број) - ако пицата не е на промоција намалувањето има вредност нула, во спротивно, вредност поголема од нула и не поголема од 100.
За потребите на оваа класа да се креираат
потребните конструктори
и да се напише соодветен деструктор.

Дополнително за оваа класа да се дефинира функцијата:

pecati() - функција во која ќе се печатат податоците за пицата во следниот формат: име - состојки, цена.
istiSe(Pica p) - функција за споредба на две пици според состојките :
Да се дефинира класа Picerija во која се чуваат:

име (низа од максимум 15 знаци)
динмички алоцирана низа од објекти од класата Pica
број на пици (цел број)
За потребите на оваа класа да се дефинираат потребните конструктори и да се напише соодветен деструктор. Да се имплементираат и следниве методи:

dodadi (Pica P) - за додавање нова пица во пицеријата, но само ако не постои иста во низата (нема пица со исти состојки со пицата што треба да се додаде).
void piciNaPromocija() - се печатат сите пици од пицеријата што се на промоција во формат : име - состојки, цена, цена со попуст.
 */
#include <iostream>
#include <cstring>
using namespace std;

class Pica
{
private:
    char ime[15];
    int cena, popust;
    char *sostojki;

public:
    Pica(char *ime = "", int cena = 0, char *sostojki = "", int popust = 0)
    {
        strcpy(this->ime, ime);
        this->cena = cena;
        this->popust = popust;
        this->sostojki = new char[strlen(sostojki) + 1];
        strcpy(this->sostojki, sostojki);
    }
    Pica(const Pica &other)
    {

        this->sostojki = new char[strlen(other.sostojki) + 1];
        strcpy(this->sostojki, other.sostojki);
        strcpy(this->ime, other.ime);
        this->cena = other.cena;
        this->popust = other.popust;
    }
    Pica &operator=(const Pica &overloadingPica)
    {
        if (this != &overloadingPica)
        {
            delete[] sostojki;
            this->sostojki = new char[strlen(overloadingPica.sostojki) + 1];
            strcpy(this->sostojki, overloadingPica.sostojki);
            strcpy(this->ime, overloadingPica.ime);
            this->cena = overloadingPica.cena;
            this->popust = overloadingPica.popust;
        }
        return *this;
    }
    ~Pica() { delete[] sostojki; }
    void pecati()
    {
        cout << this->ime << " - " << this->sostojki << ", " << this->cena;
    }
    bool istiSe(Pica p) { return strcmp(this->sostojki, p.sostojki) == 0; }
    char *getSostojki()
    {
        return sostojki;
    }
    int getCena()
    {
        return cena;
    }
    int getPopust()
    {
        return popust;
    }
};
class Picerija
{
private:
    char ime[15];
    Pica *picca;
    int brojNaPici;

public:
    Picerija(char *ime = "", Pica *picca = NULL, int brojNaPici = 0)
    {
        strcpy(this->ime, ime);
        this->brojNaPici = brojNaPici;
        this->picca = new Pica[this->brojNaPici];
        for (int i = 0; i < this->brojNaPici; i++)
        {
            this->picca[i] = picca[i];
        }
    }
    Picerija(const Picerija &other)
    {
        strcpy(this->ime, other.ime);
        this->brojNaPici = other.brojNaPici;
        this->picca = new Pica[other.brojNaPici];
        for (int i = 0; i < this->brojNaPici; i++)
        {
            this->picca[i] = other.picca[i];
        }
    }
    Picerija &operator=(const Picerija &other)
    {
        if (this != &other)
        {
            delete[] picca;
            strcpy(this->ime, other.ime);
            this->brojNaPici = other.brojNaPici;
            this->picca = new Pica[other.brojNaPici];
            for (int i = 0; i < this->brojNaPici; i++)
            {
                this->picca[i] = other.picca[i];
            }
        }
        return *this;
    }
    //    dodadi (Pica P) - за додавање нова пица во пицеријата, но само ако не постои иста во низата (нема пица со исти состојки со пицата што треба да се додаде).
    //    void piciNaPromocija() - се печатат сите пици од пицеријата што се на промоција во формат : име - состојки, цена, цена со попуст.
    void dodadi(Pica &p)
    {
        bool flag1 = true;
        for (int i = 0; i < brojNaPici; i++)
        {
            if (picca[i].istiSe((p)))
            {
                flag1 = false;
            }
        }
        if (flag1)
        {
            Pica *tempPici = new Pica[this->brojNaPici + 1];
            for (int i = 0; i < this->brojNaPici; i++)
            {
                tempPici[i] = this->picca[i];
            }
            tempPici[brojNaPici++] = p;
            delete[] picca;
            picca = tempPici;
        }
    }
    void piciNaPromocija()
    {
        for (int i = 0; i < brojNaPici; i++)
        {
            if (picca[i].getPopust())
            {
                picca[i].pecati();
                cout << " " << picca[i].getCena() * (1 - (picca[i].getPopust() / 100.0)) << endl;
            }
        }
    }

    ~Picerija()
    {
        delete[] picca;
    }

    void setIme(char *ime)
    {
        strcpy(this->ime, ime);
    }
    char *getIme()
    {
        return ime;
    }
};

int main()
{

    int n;
    char ime[15];
    cin >> ime;
    cin >> n;

    Picerija p1(ime);
    for (int i = 0; i < n; i++)
    {
        char imp[100];
        cin.get();
        cin.getline(imp, 100);
        int cena;
        cin >> cena;
        char sostojki[100];
        cin.get();
        cin.getline(sostojki, 100);
        int popust;
        cin >> popust;
        Pica p(imp, cena, sostojki, popust);
        p1.dodadi(p);
    }

    Picerija p2 = p1;
    cin >> ime;
    p2.setIme(ime);
    char imp[100];
    cin.get();
    cin.getline(imp, 100);
    int cena;
    cin >> cena;
    char sostojki[100];
    cin.get();
    cin.getline(sostojki, 100);
    int popust;
    cin >> popust;
    Pica p(imp, cena, sostojki, popust);
    p2.dodadi(p);

    cout << p1.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p1.piciNaPromocija();

    cout << p2.getIme() << endl;
    cout << "Pici na promocija:" << endl;
    p2.piciNaPromocija();

    return 0;
}
