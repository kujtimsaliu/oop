// vashiot kod ovde

#include <iostream>
#include <cstring>
using namespace std;

class Matrica
{
private:
    float matrica[10][10];
    int broj;

public:
    Matrica(int num)
    {
        this->broj = 10;
        for (int i = 0; i < broj; i++)
        {
            for (int j = 0; j < broj; j++)
            {
                this->matrica[i][j] = num;
            }
        }
    }
    Matrica() { this->broj = 0; }
    Matrica &operator+(const Matrica &m)
    {
        for (int i = 0; i < broj; i++)
        {
            for (int j = 0; j < broj; j++)
            {
                this->matrica[i][j] += m.matrica[i][j];
            }
        }
        return *this;
    }
    Matrica &operator-(const Matrica &m)
    {
        for (int i = 0; i < broj; i++)
        {
            for (int j = 0; j < broj; j++)
            {
                this->matrica[i][j] -= m.matrica[i][j];
            }
        }
        return *this;
    }
    Matrica &operator*(const Matrica &m)
    {
        float temp[broj][broj];
        for (int i = 0; i < broj; i++)
        {
            for (int j = 0; j < broj; j++)
            {
                int zbir = 0;
                for (int k = 0; k < broj; k++)
                {

                    zbir += (this->matrica[i][k] * m.matrica[k][j]);
                }
                temp[i][j] = zbir;
            }
        }
        for (int i = 0; i < broj; i++)
        {
            for (int j = 0; j < broj; j++)
            {
                this->matrica[i][j] = temp[i][j];
            }
        }
        return *this;
    }
    friend istream &operator>>(istream &in, Matrica &m)
    {
        int br;
        in >> br;
        in >> br;
        m.broj = br;
        float temp;
        for (int i = 0; i < br; i++)
        {
            for (int j = 0; j < br; j++)
            {
                in >> temp;
                m.matrica[i][j] = temp;
            }
        }
        return in;
    }
    friend ostream &operator<<(ostream &out, Matrica &m)
    {
        for (int i = 0; i < m.broj; i++)
        {
            for (int j = 0; j < m.broj; j++)
            {
                out << m.matrica[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }
};

int main()
{
    Matrica A, B, C;
    cin >> A >> B >> C;
    Matrica D = B * C;
    Matrica R = A - D + 2;
    cout << R;
}