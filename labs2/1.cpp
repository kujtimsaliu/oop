#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Agol
{
public:
    int stepeni;
    int minuti;
    int sekundi;
    // Agol(int )
    void set_stepeni(int deg)
    {
        stepeni = deg;
    }
    void set_minuti(int min)
    {
        minuti = min;
    }
    void set_sekundi(int sec)
    {
        sekundi = sec;
    }
    int getSekundi()
    {
        return sekundi;
    }
    int to_sekundi()
    {
        int zbir = (((stepeni * 60) + minuti) * 60) + sekundi;
        return zbir;
    }
} a1;

int proveri(int stepeni, int minuti, int sekundi)
{
    if ((stepeni > 0 && stepeni < 361) && (minuti > 0 && minuti < 61) && (sekundi >= 0 && sekundi < 61))
    {
        return 1;
    }
    return 0;
}

bool changeOfSeconds(Agol a, int sec)
{
    return a.getSekundi() != sec;
}

int main()
{

    // da se instancira objekt od klasata Agol
    int deg, min, sec;
    cin >> deg >> min >> sec;

    if (proveri(deg, min, sec))
    {

        a1.set_stepeni(deg);
        a1.set_minuti(min);
        a1.set_sekundi(sec);
        cout << a1.to_sekundi();
        if (changeOfSeconds(a1, sec))
            cout << "Ne smeete da gi menuvate sekundite vo ramkite na klasata!" << endl;
    }
    else
        cout << "Nevalidni vrednosti za agol" << endl;

    return 0;
}
