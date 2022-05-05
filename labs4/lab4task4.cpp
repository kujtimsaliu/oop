#include <iostream>
#include <cstring>

using namespace std;

enum ZANR
{
    akcija,
    komedija,
    drama
};

class Film
{
private:
    char *name{nullptr};
    int memorija;
    ZANR zanr;

public:
    // without arguments // defualt constructor
    Film()
    {
        this->name = nullptr;
        this->memorija = 0;
        this->zanr = ZANR(0);
    }
    // with arguments
    Film(char *name, int memorija, ZANR zanr)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->memorija = memorija;
        this->zanr = zanr;
    }
    Film(const Film &other)
    {
        delete[] name;
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->memorija = other.memorija;
        this->zanr = other.zanr;
    }
    Film operator=(const Film &filmOverloading)
    {
        if (this != &filmOverloading)
        {
            delete[] name;
            this->name = new char[strlen(filmOverloading.name) + 1];
            strcpy(this->name, filmOverloading.name);
            this->memorija = filmOverloading.memorija;
            this->zanr = filmOverloading.zanr;
        }
        return *this;
    }
    void pecati()
    {
        cout << this->memorija << "MB-" << '"' << this->name << '"';
        cout << endl;
    }
    int getMemorija() { return this->memorija; }
    ZANR getZanr()
    {
        return this->zanr;
    }
};

class DVD
{
private:
    Film films[5];
    int numberOfFilms;
    int nCapacity;

public:
    // default constructor
    // DVD()
    // {

    //     this->numberOfFilms = 0;
    //     this->nCapacity = 0;
    // }
    DVD(int nCapacity = 0, Film *films = NULL, int numberOfFilms = 0)
    {
        this->nCapacity = nCapacity;
        this->numberOfFilms = numberOfFilms;
        for (int i = 0; i < this->numberOfFilms; i++)
        {
            this->films[i] = films[i];
        }
    }
    DVD(const DVD &other)
    {
        this->nCapacity = other.nCapacity;
        this->numberOfFilms = other.numberOfFilms;
        for (int i = 0; i < this->numberOfFilms; i++)
        {
            this->films[i] = other.films[i];
        }
    }
    DVD operator=(const DVD &equalO)
    {
        if (this != &equalO)
        {
            delete[] films;
            this->nCapacity = equalO.nCapacity;
            this->numberOfFilms = equalO.numberOfFilms;
            for (int i = 0; i < this->numberOfFilms; i++)
            {
                this->films[i] = equalO.films[i];
            }
        }
        return *this;
    }
    void dodadiFilm(Film &film)
    {
        int res = 0;
        for (int i = 0; i < numberOfFilms; i++)
        {
            res += films[i].getMemorija();
        }
        if (this->nCapacity - res >= film.getMemorija() && numberOfFilms < 5)
        {
            films[numberOfFilms++] = film;
        }
    }
    void pecatiFilmoviDrugZanr(ZANR z)
    {
        for (int i = 0; i < numberOfFilms; i++)
        {
            if (films[i].getZanr() != z)
            {
                films[i].pecati();
            }
        }
    }
    float procentNaMemorijaOdZanr(ZANR z)
    {
        int memorijaOdZanrZ = 0;
        int celaMemorija = 0;
        for (int i = 0; i < this->numberOfFilms; i++)
        {
            if (films[i].getZanr() == z)
            {
                memorijaOdZanrZ += films[i].getMemorija();
            }
            celaMemorija += films[i].getMemorija();
        }
        return (memorijaOdZanrZ / (float)celaMemorija) * 100;
    }
    Film getFilm(int i)
    {
        return films[i];
    }
    int getBroj()
    {
        return this->numberOfFilms;
    }
};

int main()
{
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, memorija, kojzanr;
    char ime[50];

    if (testCase == 1)
    {
        cout << "===== Testiranje na klasata Film ======" << endl;
        cin >> ime;
        cin >> memorija;
        cin >> kojzanr; // se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
        Film f(ime, memorija, (ZANR)kojzanr);
        f.pecati();
    }
    else if (testCase == 2)
    {
        cout << "===== Testiranje na klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; // se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (ZANR)kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < n; i++)
            (omileno.getFilm(i)).pecati();
    }
    else if (testCase == 3)
    {
        cout << "===== Testiranje na metodot dodadiFilm() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; // se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (ZANR)kojzanr);
            omileno.dodadiFilm(f);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getFilm(i)).pecati();
    }
    else if (testCase == 4)
    {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; // se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (ZANR)kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((ZANR)kojzanr);
    }
    else if (testCase == 5)
    {
        cout << "===== Testiranje na metodot pecatiFilmoviDrugZanr() od klasata DVD ======" << endl;
        DVD omileno(50);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; // se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (ZANR)kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        omileno.pecatiFilmoviDrugZanr((ZANR)kojzanr);
    }
    else if (testCase == 6)
    {
        cout << "===== Testiranje na metodot procentNaMemorijaOdZanr() od klasata DVD =====" << endl;
        DVD omileno(40);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ime;
            cin >> memorija;
            cin >> kojzanr; // se vnesuva 0 za AKCIJA,1 za KOMEDIJA i 2 za DRAMA
            Film f(ime, memorija, (ZANR)kojzanr);
            omileno.dodadiFilm(f);
        }
        cin >> kojzanr;
        cout << "Procent na filmovi od dadeniot zanr iznesuva: " << omileno.procentNaMemorijaOdZanr((ZANR)kojzanr) << "%\n";
    }

    return 0;
}