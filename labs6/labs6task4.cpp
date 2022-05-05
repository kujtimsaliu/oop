
#include <iostream>
#include <cstring>

using namespace std;

class Nedviznina
{
protected:
    char *address;
    int area;
    int price;

public:
    Nedviznina()
    {
        address = new char[100];
        area = 0;
        price = 0;
    }

    ~Nedviznina()
    {
        delete[] address;
    }

    friend istream &operator>>(istream &in, Nedviznina &n)
    {
        in >> n.address >> n.area >> n.price;

        return in;
    }

    int cena()
    {
        return area * price;
    }

    double danokNaImot()
    {
        return 0.05 * cena();
    }

    char *getAdresa()
    {
        return address;
    }

    void pecati()
    {
        cout << address << ", Kvadratura: " << area << ", Cena po Kvadrat: " << price << endl;
    }
};

class Vila : public Nedviznina
{
private:
    int danok;

public:
    Vila(int danok = 0) : Nedviznina()
    {
        this->danok = danok;
    }

    friend istream &operator>>(istream &in, Vila &v)
    {
        in >> v.address >> v.area >> v.price >> v.danok;

        return in;
    }

    double danokNaImot()
    {
        return cena() * (danok + 5) / 100.0;
    };

    void pecati()
    {
        cout << address << ", Kvadratura: " << area << ", Cena po Kvadrat: " << price << ", Danok na luksuz: " << danok
             << endl;
    }
};

int main()
{
    Nedviznina n;
    Vila v;
    cin >> n;
    cin >> v;
    n.pecati();
    cout << "Danok za: " << n.getAdresa() << ", e: " << n.danokNaImot() << endl;
    v.pecati();
    cout << "Danok za: " << v.getAdresa() << ", e: " << v.danokNaImot() << endl;
    return 0;
}