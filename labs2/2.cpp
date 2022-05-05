#include <iostream>
using namespace std;

class Krug
{
public:
    float radius;
    float pi;
    Krug(float r)
    {
        radius = r;
        pi = 3.14;
    }
    float perimetar()
    {
        return 2 * pi * radius;
    }
    float plostina()
    {
        return pi * (radius * radius);
    }
    int ednakvi()
    {
        float sum1 = 2 * pi * radius;
        float sum2 = pi * (radius * radius);
        if (sum1 == sum2)
        {
            return 1;
        }
        else
            return 0;
    }
};

int main()
{
    float r;
    cin >> r;
    // instanciraj objekt od klasata Krug cij radius e vrednosta procitana od tastatura
    Krug k = Krug(r);
    k.radius = r;
    cout << k.perimetar() << endl;
    cout << k.plostina() << endl;
    cout << k.ednakvi() << endl;
    // instanciraj objekt od klasata Krug cij radius ne e definiran
    return 0;
}