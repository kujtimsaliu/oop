#include <cstring>
#include <iostream>
using namespace std;

// Your Code goes here

class Pizza
{
protected:
    char ime[20];
    char ingredients[100];
    float startingPrice;

public:
    Pizza(char *ime, char *ingredients, float startingPrice)
    {
        strcpy(this->ime, ime);
        strcpy(this->ingredients, ingredients);
        //??????
        this->ingredients[49] = '\0';
        this->startingPrice = startingPrice;
    }
    virtual double price() = 0;
    bool operator<(Pizza &p)
    {
        return this->price() < p.price();
    }
};

enum Size
{
    mala,
    golema,
    familjarna
};

class FlatPizza : public Pizza
{
private:
    Size size;

public:
    FlatPizza(char *ime, char *ingredients, float startingPrice, Size size)
        : Pizza(ime, ingredients, startingPrice)
    {
        this->size = size;
    }
    FlatPizza(char *ime, char *ingredients, float startingPrice)
        : Pizza(ime, ingredients, startingPrice)
    {
        this->size = (Size)0;
    }
    double price()
    {
        if (size == mala)
            return startingPrice * 1.1;
        if (size == golema)
            return startingPrice * 1.5;
        if (size == familjarna)
            return startingPrice * 1.3;
    }
    void sizePrint(Size size)
    {
        switch (size)
        {
        case 0:
            cout << "small";
            break;
        case 1:
            cout << "big";
            break;
        case 2:
            cout << "family";
            break;
        }
    }
    friend ostream &operator<<(ostream &os, FlatPizza &f)
    {
        os << f.ime << ": " << f.ingredients << ", ";
        f.sizePrint(f.size);
        os << " - ";
        os << f.price();
        os << endl;
        return os;
    }
};

class FoldedPizza : public Pizza
{
private:
    bool isWhite;

public:
    FoldedPizza(char *ime, char *ingredients, float startingPrice, bool isWhite)
        : Pizza(ime, ingredients, startingPrice)
    {
        this->isWhite = isWhite;
    }
    FoldedPizza(char name[20], char ingredients[20], double price) : Pizza(name, ingredients, price)
    {
        isWhite = true;
    }
    double price()
    {
        return isWhite ? startingPrice * 1.1 : startingPrice * 1.3;
    }
    friend ostream &operator<<(ostream &os, FoldedPizza &f)
    {
        os << f.ime << ": " << f.ingredients << ", ";
        f.isWhite ? os << "wf" : os << "nwf";
        os << " - " << f.price() << endl;
        return os;
    }
    void setWhiteFlour(bool c)
    {
        this->isWhite = c;
    }
};

void expensivePizza(Pizza **niza, int n)
{
    Pizza *mostExpensive = niza[0];
    for (int i = 0; i < n; i++)
    {
        // if (mostExpensive->price() < niza[i]->price())
        if (*mostExpensive < *niza[i])
        {
            mostExpensive = niza[i];
        }
    }

    FlatPizza *casted = dynamic_cast<FlatPizza *>(mostExpensive);
    if (casted != 0)
    {
        cout << *casted;
    }
    else
    {
        FoldedPizza *foldedCasted = dynamic_cast<FoldedPizza *>(mostExpensive);
        cout << *foldedCasted;
    }
}

// Testing

int main()
{
    int test_case;
    char name[20];
    char ingredients[100];
    float inPrice;
    Size size;
    bool whiteFlour;

    cin >> test_case;
    if (test_case == 1)
    {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FlatPizza fp(name, ingredients, inPrice);
        cout << fp;
    }
    else if (test_case == 2)
    {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        int s;
        cin >> s;
        FlatPizza fp(name, ingredients, inPrice, (Size)s);
        cout << fp;
    }
    else if (test_case == 3)
    {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        cout << fp;
    }
    else if (test_case == 4)
    {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        fp.setWhiteFlour(false);
        cout << fp;
    }
    else if (test_case == 5)
    {
        // Test Cast - operator <, price
        int s;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        cin >> s;
        FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << *fp1;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        cin >> s;
        FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size)s);
        cout << *fp2;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
        cout << *fp3;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
        fp4->setWhiteFlour(false);
        cout << *fp4;

        cout << "Lower price: " << endl;
        if (*fp1 < *fp2)
            cout << fp1->price() << endl;
        else
            cout << fp2->price() << endl;

        if (*fp1 < *fp3)
            cout << fp1->price() << endl;
        else
            cout << fp3->price() << endl;

        if (*fp4 < *fp2)
            cout << fp4->price() << endl;
        else
            cout << fp2->price() << endl;

        if (*fp3 < *fp4)
            cout << fp3->price() << endl;
        else
            cout << fp4->price() << endl;
    }
    else if (test_case == 6)
    {
        // Test Cast - expensivePizza
        int num_p;
        int pizza_type;

        cin >> num_p;
        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j)
        {

            cin >> pizza_type;
            if (pizza_type == 1)
            {
                cin.get();
                cin.getline(name, 20);

                cin.getline(ingredients, 100);
                cin >> inPrice;
                int s;
                cin >> s;
                FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
                cout << (*fp);
                pi[j] = fp;
            }
            if (pizza_type == 2)
            {

                cin.get();
                cin.getline(name, 20);
                cin.getline(ingredients, 100);
                cin >> inPrice;
                FoldedPizza *fp =
                    new FoldedPizza(name, ingredients, inPrice);
                if (j % 2)
                    (*fp).setWhiteFlour(false);
                cout << (*fp);
                pi[j] = fp;
            }
        }

        cout << endl;
        cout << "The most expensive pizza:\n";
        expensivePizza(pi, num_p);
    }
    return 0;
}
