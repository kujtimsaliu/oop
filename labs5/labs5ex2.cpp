#include <iostream>
#include <cmath>
using namespace std;

class ComplexNumber
{

private:
    double real, imaginary;
    void copy(const ComplexNumber &other)
    {
        this->real = other.real;
        this->imaginary = other.imaginary;
    }

public:
    void setReal(float r)
    {
        this->real = r;
    }
    void setImaginary(float i)
    {
        this->imaginary = i;
    }
    ComplexNumber()
    {
        real = 0;
        imaginary = 0;
    }
    ComplexNumber(double real, double imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    double module()
    {
        return sqrt(pow(real, 2) + pow(imaginary, 2));
    }
    ComplexNumber &operator=(const ComplexNumber &c)
    {
        if (this != &c)
            copy(c);
        return *this;
    }
    friend ostream &operator<<(ostream &out, ComplexNumber &c)
    {
        if (c.real)
            out << c.real;
        if (c.real && c.imaginary)
            out << "+";
        if (c.imaginary)
            out << c.imaginary << "i" << endl;
        return out;
    }
    ComplexNumber &operator+(ComplexNumber &c)
    {
        this->real += c.real;
        this->imaginary += c.imaginary;
        return *this;
    }
    ComplexNumber &operator-(ComplexNumber &c)
    {
        this->real -= c.real;
        this->imaginary -= c.imaginary;
        return *this;
    }
    ComplexNumber &operator*(ComplexNumber &c)
    {
        this->real *= c.real;
        this->imaginary *= c.imaginary;
        return *this;
    }
    ComplexNumber &operator/(ComplexNumber &c)
    {
        this->real /= c.real;
        this->imaginary /= c.imaginary;
        return *this;
    }
    bool operator==(ComplexNumber &c)
    {
        return (c.real == this->real) && (c.imaginary == this->imaginary);
    }
    bool operator>(ComplexNumber &c)
    {
        if (this->real > c.real)
            return true;
        else if (this->real < c.real)
            return false;
        return this->imaginary > c.imaginary;
    }
    bool operator<(ComplexNumber &c)
    {
        if (this->real < c.real)
            return true;
        else if (this->real > c.real)
            return false;
        return this->imaginary < c.imaginary;
    }
};

class Equation
{
private:
    ComplexNumber *nums;
    char *operators;

public:
    friend istream &operator>>(istream &is, Equation &eq)
    {
        char znak = 't';
        float num;
        int index = 0;
        while (znak != '=')
        {
            ComplexNumber *temp = new ComplexNumber[index + 1];
            char *opTemp = new char[index + 1];
            for (int i = 0; i < index; i++)
            {
                temp[i] = eq.nums[i];
                opTemp[i] = eq.operators[i];
            }

            is >> num;
            temp[index].setReal(num);
            is >> num;
            temp[index].setImaginary(num);
            is >> znak;
            opTemp[index] = znak;
            index++;

            eq.nums = temp;
            eq.operators = opTemp;
        }
        return is;
    }
    ComplexNumber result()
    {
        int index = 0;
        ComplexNumber result = this->nums[0];
        while (this->operators[index] != '=')
        {
            switch (this->operators[index])
            {
            case '+':
                result = result + this->nums[index + 1];
                break;
            case '-':
                result = result - this->nums[index + 1];
                break;
            case '*':
                result = result * this->nums[index + 1];
                break;
            case '/':
                result = result / this->nums[index + 1];
                break;
            }
            index++;
        }
        return result;
    }
    double sumModules()
    {
        double sum = 0;
        sum += this->nums[0].module();
        for (int i = 0; this->operators[i] != '='; i++)
        {
            sum += this->nums[i + 1].module();
        }
        return sum;
    }
};

// Не го менувајте main методот.

int main()
{
    int testCase;
    double real, imaginary;
    ComplexNumber first, second, result;

    cin >> testCase;

    if (testCase <= 8)
    {
        cin >> real;
        cin >> imaginary;
        first = ComplexNumber(real, imaginary);
        cin >> real;
        cin >> imaginary;
        second = ComplexNumber(real, imaginary);
    }

    if (testCase == 1)
    {
        cout << "===== OPERATOR + =====" << endl;
        result = first + second;
        cout << result;
    }
    else if (testCase == 2)
    {
        cout << "===== OPERATOR - =====" << endl;
        result = first - second;
        cout << result;
    }
    else if (testCase == 3)
    {
        cout << "===== OPERATOR * =====" << endl;
        result = first * second;
        cout << result;
    }
    else if (testCase == 4)
    {
        cout << "===== OPERATOR / =====" << endl;
        result = first / second;
        cout << result;
    }
    else if (testCase == 5)
    {
        cout << "===== OPERATOR == =====" << endl;
        cout << first;
        cout << second;
        if (first == second)
            cout << "EQUAL" << endl;
        else
            cout << "NOT EQUAL" << endl;
    }
    else if (testCase == 6)
    {
        cout << "===== OPERATOR > =====" << endl;
        cout << first;
        cout << second;
        if (first > second)
            cout << "FIRST GREATER THAN SECOND" << endl;
        else
            cout << "FIRST LESSER THAN SECOND" << endl;
    }
    else if (testCase == 7)
    {
        cout << "===== OPERATOR < =====" << endl;
        cout << first;
        cout << second;
        if (first < second)
            cout << "FIRST LESSER THAN SECOND" << endl;
        else
            cout << "FIRST GREATER THAN SECOND" << endl;
    }
    else if (testCase == 8)
    {
        cout << "===== MODULE =====" << endl;
        double module = first.module();
        cout << first;
        cout << "Module: " << module << endl;
        cout << second;
        module = second.module();
        cout << "Module: " << module << endl;
    }
    else if (testCase == 9)
    {
        cout << "===== OPERATOR >> & SUM OF MODULES =====" << endl;
        Equation equation;
        cin >> equation;
        cout << equation.sumModules();
    }
    else if (testCase == 10)
    {
        cout << "===== EQUATION RESULT =====" << endl;
        Equation equation;
        cin >> equation;
        result = equation.result();
        cout << result;
    }
    return 0;
}