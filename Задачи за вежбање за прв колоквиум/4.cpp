#include <iostream>
#include <cstring>

using namespace std;

#include <iostream>
#include <cstring>
using namespace std;

class Patnik
{

private:
    char ime[40];
    Voz niza[100];
    int celbroj; // 1 ili 2
    bool velosiped;

public:
};

class Voz
{

private:
public:
};

int main()
{
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    // cout<<v<<endl;
    for (int i = 0; i < n; i++)
    {
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        // cout<<p<<endl;
        v += p;
    }
    cout << v;
    coutt << patnik << std::endl;
    std::cout << patnik.biggie << std::endl;
    v.patniciNemaMesto();

    return 0;
}
