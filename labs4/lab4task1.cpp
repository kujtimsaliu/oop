#include <iostream>
#include <cstring>
using namespace std;

class List
{
private:
    int *broevi;
    int nBroevi;

public:
    // default c and constructor with arguments
    List(int *broevi = 0, int nBroevi = 0)
    {
        this->nBroevi = nBroevi;
        this->broevi = new int[nBroevi];
        // this->broevi = broevi; for loop dummie
        for (int i = 0; i < nBroevi; i++)
        {
            this->broevi[i] = broevi[i];
        }
    }

    // Copy Constructor
    List(const List &list)
    {
        this->nBroevi = list.nBroevi;
        this->broevi = new int[list.nBroevi];
        for (int i = 0; i < nBroevi; i++)
        {
            this->broevi[i] = list.broevi[i];
        }
    }
    List &operator=(const List &l)
    {
        if (this != &l)
        {
            delete[] broevi;
            this->nBroevi = l.nBroevi;
            this->broevi = new int[nBroevi];
            for (int i = 0; i < nBroevi; i++)
            {
                this->broevi[i] = l.broevi[i];
            }
        }
        return *this;
    }

    void pecati()
    {
        cout << nBroevi << ": ";
        for (int i : broevi)
        {
            cout << i << " ";
        }
        cout << "sum: " << sum();
        cout << " average: " << average() << endl;
    }
    // method to return the sum of elements in the list
    int sum()
    {
        int res = 0;
        for (int i = 0; i < nBroevi; i++)
        {
            res += broevi[i];
        }
        return res;
    }
    int getBrojBroevi()
    {
        return nBroevi;
    }

    // return the average of all the elements in the list
    double average()
    {
        int x = sum();
        return (double)x / nBroevi;
    }

    ~List() { delete[] broevi; }
};

class ListContainer
{
private:
    List *listi;
    int listBroevi;
    int obidi;

public:
    // 2in1 constructor
    ListContainer(List *list = 0, int listBroevi = 0, int obidi = 0)
    {
        this->listBroevi = listBroevi;
        this->obidi = obidi;
        this->listi = new List[listBroevi];
        for (int i = 0; i < this->listBroevi; i++)
        {
            this->listi[i] = list[i];
        }
    }
    // copy-constructor
    ListContainer(const ListContainer &listC)
    {
        this->listBroevi = listC.listBroevi;
        this->obidi = listC.obidi;
        this->listi = new List[listC.listBroevi];
        for (int i = 0; i < listC.listBroevi; i++)
        {
            this->listi[i] = listC.listi[i];
        }
    }

    ListContainer &operator=(const ListContainer &lc)
    {
        if (this != &lc)
        {
            delete[] listi;
            this->listBroevi = lc.listBroevi;
            this->obidi = lc.obidi;
            this->listi = new List[lc.listBroevi];
            for (int i = 0; i < lc.listBroevi; i++)
            {
                this->listi[i] = lc.listi[i];
            }
        }
        return *this;
    }

    void print()
    {
        if (listBroevi == 0)
        {
            cout << "The list is empty" << endl;
        }
        else
        {
            // for (int i = 0; i <= listBroevi; i++)
            for (int i = 1; i <= listBroevi; i++)
            {
                cout << "List number: " << i << " ";
                cout << "List info: ";
                listi[i - 1].pecati();
            }
            cout << "Sum: " << sum() << " Average: " << average() << endl;
            cout << "Successful attempts: " << listBroevi << " Failed attempts: " << obidi << endl;
        }
    }

    double average()
    {
        int brojBroevi = 0;
        for (int i = 0; i < listBroevi; i++)
        {
            brojBroevi += listi[i].getBrojBroevi();
        }
        return sum() / (double)brojBroevi;
    }

    int sum()
    {
        int sum = 0;
        for (int i = 0; i < listBroevi; i++)
        {
            sum += listi[i].sum();
        }
        return sum;
    }

    void addNewList(List l)
    {
        bool same = false;
        for (int i = 0; i < listBroevi; i++)
        {
            if (listi[i].sum() == l.sum())
            {
                same = true;
            }
        }
        if (!same)
        {
            List *newList = new List[listBroevi + 1];
            for (int i = 0; i < listBroevi; i++)
            {
                newList[i] = listi[i];
            }
            newList[listBroevi++] = l;
            delete[] listi;
            listi = newList;
        }
        else
        {
            obidi++;
        }
    }

    // Destrucotr
    ~ListContainer() { delete[] listi; }
};

int main()
{

    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int n;
        int niza[100];

        cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> niza[j];
        }

        List l = List(niza, n);

        lc.addNewList(l);
    }

    int testCase;
    cin >> testCase;

    if (testCase == 1)
    {
        cout << "Test case for operator =" << endl;
        ListContainer lc1;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1 = lc;
        lc1.print();
        cout << lc1.sum() << " " << lc.sum() << endl;
        lc1.sum();
        lc1.average();
    }
    else
    {
        lc.print();
    }
}