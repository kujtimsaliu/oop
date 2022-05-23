
#include <iostream>
#include <cstring>
using namespace std;

class Book
{
protected:
    char isbn[20];
    char title[50];
    char author[30];
    double price;

public:
    Book(char *isbn, char *title, char *author, double price)
    {
        strcpy(this->isbn, isbn);
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->price = price;
    };
    virtual double bookPrice() = 0;
    bool operator>(Book &book)
    {
        return bookPrice() > book.bookPrice();
    }
    friend ostream &operator<<(ostream &os, Book &b)
    {
        os << b.isbn << ": " << b.title << ", " << b.author << " " << b.bookPrice() << endl;
        ;
        return os;
    }
    void setISBN(char isbn[20])
    {
        strcpy(this->isbn, isbn);
    }
};

class OnlineBook : public Book
{
private:
    char *url;
    int size;

public:
    OnlineBook(char *ISBN, char *title, char *author, double price,
               char *url, int size) : Book(ISBN, title, author, price)
    {
        this->size = size;
        this->url = new char[strlen(url) + 1];
        strcpy(this->url, url);
    }
    double bookPrice()
    {
        return size > 20 ? price * 1.2 : price;
    }
};
class PrintBook : public Book
{
private:
    bool stock;
    double weight;

public:
    PrintBook(char *isbn, char *title, char *author, double price, double weight, bool stock) : Book(isbn, title, author, price)
    {
        this->stock = stock;
        this->weight = weight;
    }

    double bookPrice()
    {
        return weight > 0.7 ? price * 1.15 : price;
    }
};

void mostExpensiveBook(Book **b, int n)
{
    Book *mostExpensive = b[0];
    int nOnline = 0, nPrint = 0;
    for (int i = 0; i < n; i++)
    {
        OnlineBook *casted = dynamic_cast<OnlineBook *>(b[i]);
        if (casted != 0)
        {
            nOnline++;
            // if (casted->bookPrice() > mostExpensive->bookPrice())
            // {
            //     mostExpensive = casted;
            // }
        }
        else
        {
            PrintBook *p = dynamic_cast<PrintBook *>(b[i]);
            if (p != 0)
            {
                nPrint++;
                // if (p->bookPrice() > mostExpensive->bookPrice())
                // {
                //     mostExpensive = p;
                // }
            }
        }
        if (mostExpensive->bookPrice() < b[i]->bookPrice())
        {
            mostExpensive = b[i];
        }
    }
    cout << "FINKI-Education" << endl;
    cout << "Total number of online books: " << nOnline << endl;
    cout << "Total number of print books: " << nPrint << endl;
    cout << "The most expensive book is: " << endl;
    cout << *mostExpensive << endl;
}

int main()
{

    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    Book **books;
    int n;

    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++)
        {
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2)
    {
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;
        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    if (testCase == 3)
    {
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++)
        {
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4)
    {
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++)
        {

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1)
            {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);
            }
            else
            {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i < n; i++)
        delete books[i];
    delete[] books;
    return 0;
}
