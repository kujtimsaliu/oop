#include <iostream>
#include <string.h>
using namespace std;

class PlDrustvo
{
private:
    char *ime;
    int turi;
    int clenovi;

public:
    PlDrustvo()
    {
        this->turi = 0;
        this->clenovi = 0;
    }
    PlDrustvo(int clenovi)
    {
        this->clenovi = clenovi;
    }
    PlDrustvo(char *ime, int turi, int clenovi)
    {
        this->turi = turi;
        this->clenovi = clenovi;
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
    }
    PlDrustvo operator+(PlDrustvo &drustvo)
    {

        if (this->clenovi > drustvo.clenovi)
        {
            PlDrustvo dr(this->ime, this->turi, this->clenovi + drustvo.clenovi);
            return dr;
        }
        PlDrustvo dr(drustvo.ime, drustvo.turi, this->clenovi + drustvo.clenovi);
        return dr;
    }
    bool operator>(PlDrustvo &drustvo)
    {
        return this->clenovi > drustvo.clenovi;
    }
    bool operator<(PlDrustvo &drustvo)
    {
        return this->clenovi < drustvo.clenovi;
    }
    friend ostream &operator<<(ostream &o, PlDrustvo &drustvo)
    {
        o << "Ime: " << drustvo.ime << " Turi: " << drustvo.turi << " Clenovi: " << drustvo.clenovi << endl;
        return o;
    }
};
void najmnoguClenovi(PlDrustvo *drustva, int broj)
{
    PlDrustvo maks(0);
    int maksi = 0;
    for (int i = 0; i < broj; i++)
    {
        if (drustva[i] > maks)
        {
            maks = drustva[i];
            maksi = i;
        }
    }
    cout << "Najmnogu clenovi ima planinarskoto drustvo: " << drustva[maksi] << endl;
}

int main()
{
    PlDrustvo drustva[3];
    PlDrustvo pl;
    for (int i = 0; i < 3; i++)
    {
        char ime[100];
        int brTuri;
        int brClenovi;
        cin >> ime;
        cin >> brTuri;
        cin >> brClenovi;
        PlDrustvo p(ime, brTuri, brClenovi);
        drustva[i] = p;
    }

    pl = drustva[0] + drustva[1];
    cout << pl;

    najmnoguClenovi(drustva, 3);

    return 0;
}
