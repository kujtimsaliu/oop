#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char firstName[20];
    char lastName[20];

public:
    Person()
    {
        strcpy(firstName, "");
        strcpy(lastName, "");
    }
    Person(char *_firstName, char *_lastName)
    {
        strcpy(firstName, _firstName);
        strcpy(lastName, _lastName);
    }
    void print()
    {
        cout << firstName << " " << lastName << endl;
    }
};

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 1900;
    }
    Date(int _year, int _month, int _day)
    {
        day = _day;
        month = _month;
        year = _year;
    }
    // copy const
    Date(const Date &other)
    {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    // print method
    void print()
    {
        cout << year << "." << month << "." << day << endl;
    }
};

class Car
{
private:
    Person owner;
    Date date;
    float price;

public:
    Car()
    {
        price = 0;
    }
    Car(Person _owner, Date _date, float _p)
    {
        owner = _owner;
        date = _date;
        price = _p;
    }
    void print()
    {
        owner.print();
        date.print();
        cout << "Price: " << price << endl;
    }
    float getPrice()
    {
        return price;
    }
};

void cheaperThan(Car *cars, int numCars, float priceLimit)
{
    for (int i = 0; i < numCars; i++)
    {
        if (priceLimit > cars[i].getPrice())
        {
            cars[i].print();
        }
    }
}

int main()
{
    char name[20];
    char lastName[20];
    int year;
    int month;
    int day;
    float price;

    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(year, month, day);

        cin >> price;
        Car car(lik, date, price);

        car.print();
    }
    else if (testCase == 2)
    {
        cin >> name;
        cin >> lastName;
        Person lik(name, lastName);

        cin >> year;
        cin >> month;
        cin >> day;
        Date date(Date(year, month, day));

        cin >> price;
        Car car(lik, date, price);
        car.print();
    }
    else
    {
        int numCars;
        cin >> numCars;

        Car cars[10];
        for (int i = 0; i < numCars; i++)
        {
            cin >> name;
            cin >> lastName;
            Person lik(name, lastName);

            cin >> year;
            cin >> month;
            cin >> day;
            Date date(year, month, day);

            cin >> price;
            cars[i] = Car(lik, date, price);
        }
        float priceLimit;
        cin >> priceLimit;
        cheaperThan(cars, numCars, priceLimit);
    }

    return 0;
}