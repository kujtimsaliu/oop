#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50

enum Kupuvac
{
    standard,
    loyal,
    vip
};

class UserExistsException
{
public:
    void message()
    {
        cout << "The user already exists in the list!" << endl;
    }
};
class Customer
{
private:
    char ime[50];
    char adresa[50];
    Kupuvac k;
    static int popust;
    static const int dopolnitelenPopust = 20;
    int brojKupeniProizvodi;

public:
    Customer(const char *ime = "", const char *adresa = "", Kupuvac k = standard, int brojKupeniProizvodi = 0)
    {
        strcpy(this->ime, ime);
        strcpy(this->adresa, adresa);
        this->k = (Kupuvac)k;
        this->brojKupeniProizvodi = brojKupeniProizvodi;
    }
    static void setDiscount1(int number)
    {
        popust = number;
    }
    friend ostream &operator<<(ostream &out, Customer &c)
    {
        out << c.ime << endl;
        out << c.adresa << endl;
        out << c.brojKupeniProizvodi << endl;
        if (c.k == 0)
        {
            out << "standard 0" << endl;
        }
        if (c.k == 1)
        {
            out << "loyal " << c.popust << endl;
        }
        else if (c.k == 2)
        {
            out << "vip " << c.dopolnitelenPopust + c.popust << endl;
        }
        return out;
    }
    bool operator==(const Customer &c)
    {
        return strcmp(adresa, c.adresa);
    }
    int getKupeni()
    {
        return brojKupeniProizvodi;
    }
    int typeKupuvac()
    {
        return k;
    }
    void setKupuvac(Kupuvac k2)
    {
        k = (Kupuvac)k2;
    }
};
int Customer::popust = 10;

// class Customer
// {
// protected:
//     char name[50];
//     char email[50];
//     Kupuvac type;
//     static int basicDiscount;
//     static const int additionalDiscount = 20;
//     int numProducts;

// public:
//     // TODO try a two in one constructor
//     Customer(const char *name = "", const char *email = "", typeC type = (typeC)0, int numProducts = 0)
//     {
//         strcpy(this->name, name);
//         strcpy(this->email, email);
//         this->type = type;
//         this->numProducts = numProducts;
//     }
//     static void setDiscount1(int n)
//     {
//         basicDiscount = n;
//     }
//     void discountPrint(typeC t, Customer &c)
//     {
//         switch (t)
//         {
//         case 0:
//             cout << "standard 0" << endl;
//             break;
//         case 2:
//             cout << "loyal " << basicDiscount << endl;
//             break;
//         case 1:
//             cout << "vip " << basicDiscount + additionalDiscount << endl;
//             break;
//         }
//     }
//     friend ostream &operator<<(ostream &os, Customer &c)
//     {
//         os << c.name << endl
//            << c.email << endl
//            << c.numProducts << endl;
//         // c.discountPrint(c.type, c); // might have messed it up !!TODO fix it dumbass
//         if (c.type == 0)
//         {
//             os << "standard 0" << endl;
//         }
//         if (c.type == 1)
//         {
//             os << "loyal " << c.basicDiscount << endl;
//         }
//         else if (c.type == 2)
//         {
//             os << "vip " << c.additionalDiscount + c.basicDiscount << endl;
//         }
//         return os;
//     }
//     bool operator==(const Customer &c)
//     {
//         return strcmp(this->email, c.email);
//     }
//     // TODO write the fucntions getType() , getNumProducts() and setType((typeC)num)
//     typeC getType()
//     {
//         return type;
//     }
//     int getNumProducts()
//     {
//         return numProducts;
//     }
//     void setType(typeC t)
//     {
//         type = (typeC)t;
//     }
// };
// int Customer::basicDiscount = 20;

// class FINKI_bookstore
// {
// private:
//     Customer *niza;
//     int count;
//     void copy(const FINKI_bookstore &f)
//     {
//         this->count = f.count;
//         this->niza = new Customer[count + 1];
//         for (int i = 0; i < count; i++)
//         {
//             this->niza[i] = f.niza[i];
//         }
//     }

// public:
//     FINKI_bookstore()
//     {
//         niza = new Customer[0];
//         count = 0;
//     }
//     FINKI_bookstore(const FINKI_bookstore &f)
//     {
//         copy(f);
//     }
//     FINKI_bookstore &operator=(const FINKI_bookstore &f)
//     {
//         if (this != &f)
//         {
//             delete[] niza;
//             copy(f);
//         }
//         return *this;
//     }
//     // ~FINKI_bookstore() { delete[] niza; }

//     // operator+=
//     FINKI_bookstore &operator+=(const Customer &c)
//     {
//         for (int i = 0; i < count; i++)
//         {
//             if ((niza[i] == c) == 0)
//             {
//                 throw UserExistsException();
//             }
//         }
//         Customer *tmp = new Customer[count + 1];
//         for (int i = 0; i < count; i++)
//         {
//             tmp[i] = niza[i];
//         }
//         tmp[count++] = c;
//         delete[] niza;
//         tmp = niza;
//         return *this;
//     }
//     // Update function with which all standard customers with purchased more than 5
//     // products become loyal, and all loyal customers with more than 10 purchased products,
//     // become VIP (5 points).

//     void setCustomers(Customer *arr, int n)
//     {
//         delete[] niza;
//         niza = new Customer[n];
//         for (int i = 0; i < n; i++)
//             niza[i] = arr[i];
//         count = n;
//     }

//     void update()
//     {
//         for (int i = 0; i < count; i++)
//         { // TODO write the fucntions getType() , getNumProducts() and setType((typeC)num)
//             if (niza[i].getType() == 0 && niza[i].getNumProducts() > 5)
//             {
//                 niza[i].setType((typeC)1);
//             }
//             else if (niza[i].getType() == 1 && niza[i].getNumProducts() > 10)
//             {
//                 niza[i].setType((typeC)2);
//             }
//         }
//     }
//     // TODO operator <<
//     friend ostream &operator<<(ostream &os, const FINKI_bookstore &f)
//     {
//         for (int i = 0; i < f.count; i++)
//         {
//             os << f.niza[i];
//         }
//         return os;
//     }
// };
class FINKI_bookstore
{
private:
    Customer *niza;
    int broj;
    void copy(const FINKI_bookstore &fb)
    {
        niza = new Customer[fb.broj + 1];
        for (int i = 0; i < fb.broj; i++)
        {
            niza[i] = fb.niza[i];
        }
        broj = fb.broj;
    }

public:
    FINKI_bookstore()
    {
        niza = new Customer[0];
        broj = 0;
    }
    FINKI_bookstore(const FINKI_bookstore &fb)
    {
        copy(fb);
    }
    FINKI_bookstore &operator=(const FINKI_bookstore &fb)
    {
        if (this != &fb)
        {
            delete[] niza;
            copy(fb);
        }
        return *this;
    }
    ~FINKI_bookstore()
    {
        delete[] niza;
    }
    FINKI_bookstore &operator+=(const Customer &c)
    {
        for (int i = 0; i < broj; i++)
        {
            if ((niza[i] == c) == 0)
            {
                throw UserExistsException();
            }
        }
        Customer *temp = new Customer[broj + 1];
        for (int i = 0; i < broj; i++)
        {
            temp[i] = niza[i];
        }
        temp[broj++] = c;
        delete[] niza;
        niza = temp;
        return *this;
    }
    void setCustomers(Customer *array, int n)
    {
        delete[] niza;
        niza = new Customer[n];
        for (int i = 0; i < n; i++)
        {
            niza[i] = array[i];
        }
        broj = n;
    }
    void update()
    {
        for (int i = 0; i < broj; i++)
        {
            if (niza[i].typeKupuvac() == 0 && niza[i].getKupeni() > 5)
            {
                niza[i].setKupuvac(Kupuvac(1));
            }
            else if (niza[i].typeKupuvac() == 1 && niza[i].getKupeni() > 10)
            {
                niza[i].setKupuvac(Kupuvac(2));
            }
        }
    }
    friend ostream &operator<<(ostream &out, const FINKI_bookstore &fe)
    {
        for (int i = 0; i < fe.broj; i++)
        {
            out << fe.niza[i];
        }
        return out;
    }
};
int main()
{
    int testCase;
    cin >> testCase;

    char name[MAX];
    char email[MAX];
    int tC;
    int discount;
    int numProducts;

    if (testCase == 1)
    {
        cout << "===== Test Case - Customer Class ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (Kupuvac)tC, numProducts);
        cout << c;
    }

    if (testCase == 2)
    {
        cout << "===== Test Case - Static Members ======" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        cout << "===== CONSTRUCTOR ======" << endl;
        Customer c(name, email, (Kupuvac)tC, numProducts);
        cout << c;

        c.setDiscount1(5);

        cout << c;
    }

    if (testCase == 3)
    {
        cout << "===== Test Case - FINKI-bookstore ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i)
        {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (Kupuvac)tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << fc << endl;
    }

    if (testCase == 4)
    {
        cout << "===== Test Case - operator+= ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i)
        {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (Kupuvac)tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        Customer c(name, email, (Kupuvac)tC, numProducts);
        fc += c;

        cout << fc;
    }

    if (testCase == 5)
    {
        cout << "===== Test Case - operator+= (exception) ======" << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        Customer temp;
        for (int i = 0; i < n; ++i)
        {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (Kupuvac)tC, numProducts);
            customers[i] = c;
            temp = c;
        }

        fc.setCustomers(customers, n);
        cout << "OPERATOR +=" << endl;
        cin.get();
        cin.getline(name, MAX);
        cin.getline(email, MAX);
        cin >> tC;
        cin >> numProducts;
        try
        {

            fc += temp;
        }
        catch (UserExistsException &e)
        {
            e.message();
        }
        cout << fc;
    }

    if (testCase == 6)
    {
        cout << "===== Test Case - update method  ======" << endl
             << endl;
        FINKI_bookstore fc;
        int n;
        cin >> n;
        Customer customers[MAX];
        for (int i = 0; i < n; ++i)
        {
            cin.get();
            cin.getline(name, MAX);
            cin.getline(email, MAX);
            cin >> tC;
            cin >> numProducts;
            Customer c(name, email, (Kupuvac)tC, numProducts);
            customers[i] = c;
        }

        fc.setCustomers(customers, n);

        cout << "Update:" << endl;
        fc.update();
        cout << fc;
    }
    return 0;
}
