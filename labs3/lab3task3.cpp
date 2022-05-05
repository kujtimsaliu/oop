#include <iostream>
#include <cstring>
using namespace std;

// all classes should have print() method
class Category
{
private:
    char name[20]; // unnamed - initial value
public:
    Category() { strcpy(name, "unnamed"); }
    Category(char *name)
    {
        strcpy(this->name, name);
    }
    void print()
    {
        cout << "Category: " << name << endl;
    }
};

class NewsArticle
{
private:
    Category category;
    char title[30]; // initial value = untitled
public:
    NewsArticle()
    {
        strcpy(title, "untitled");
    }
    // NewsArticle article(category);
    NewsArticle(Category ct)
    {
        strcpy(title, "untitled");
        category = ct;
    }
    NewsArticle(Category _ctg, char *title)
    {
        category = _ctg;
        strcpy(this->title, title);
    }
    // print method
    void print()
    {
        cout << "Article title: " << title << endl;
        category.print();
    }
};

class FrontPage
{
private:
    NewsArticle NA;
    float price = 0;       // initial value =0;
    int editionNumber = 0; // initial value =0;

public:
    FrontPage()
    {
        price = 0.0;
        editionNumber = 0;
    }
    // FrontPage frontPage(article, price);
    FrontPage(NewsArticle arct, float _price)
    {
        NA = arct;
        price = _price;
    }

    FrontPage(NewsArticle _n, float price, int eNumber)
    {
        NA = _n;
        this->price = price;
        editionNumber = eNumber;
    }
    void print()
    {
        cout << "Price: " << price << ", ";
        cout << "Edition number: " << editionNumber << endl;
        NA.print();
    }
};

int main()
{
    char categoryName[20];
    char articleTitle[30];
    float price;
    int editionNumber;

    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        int iter;
        cin >> iter;
        while (iter > 0)
        {
            cin >> categoryName;
            cin >> articleTitle;
            cin >> price;
            cin >> editionNumber;
            Category category(categoryName);
            NewsArticle article(category, articleTitle);
            FrontPage frontPage(article, price, editionNumber);
            frontPage.print();
            iter--;
        }
    }
    else if (testCase == 2)
    {
        cin >> categoryName;
        cin >> price;
        cin >> editionNumber;
        Category category(categoryName);
        NewsArticle article(category);
        FrontPage frontPage(article, price, editionNumber);
        frontPage.print();
    } // test case 3
    else if (testCase == 3)
    {
        cin >> categoryName;
        cin >> articleTitle;
        cin >> price;
        Category category(categoryName);
        NewsArticle article(category, articleTitle);
        FrontPage frontPage(article, price);
        frontPage.print();
    }
    else
    {
        FrontPage frontPage = FrontPage();
        frontPage.print();
    }
    return 0;
}