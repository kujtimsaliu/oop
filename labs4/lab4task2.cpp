#include <iostream>
#include <cstring>

using namespace std;

enum EXTENSION
{
    pdf,
    txt,
    exe
};

class File
{
private:
    char *fileName;
    EXTENSION ext;
    char *fileOwner;
    int fileSize;

public:
    // construktor bez parametri
    File()
    {
        strcpy(this->fileName, "");
        this->ext = (EXTENSION)0;
        strcpy(this->fileOwner, "");
        this->fileSize = 0;
    }
    // constructor with arguments;
    File(char *fileName, char *fileOwner, int fileSize, EXTENSION ext)
    {
        // 1.allocate memory 2.copy content
        this->fileName = new char[strlen(fileName) + 1];
        strcpy(this->fileName, fileName);
        this->fileOwner = new char[strlen(fileOwner) + 1];
        strcpy(this->fileOwner, fileOwner);
        this->fileSize = fileSize;
        this->ext = ext;
    }
    // copy-constructor
    File(const File &copy)
    {
        this->fileName = new char[strlen(copy.fileName) + 1];
        strcpy(this->fileName, copy.fileName);
        this->fileOwner = new char[strlen(copy.fileOwner) + 1];
        strcpy(this->fileOwner, copy.fileOwner);
        this->fileSize = copy.fileSize;
        this->ext = copy.ext;
    }
    // overloading operator =
    File &operator=(const File &fo)
    {
        if (this != &fo)
        {
            delete[] fileName;
            delete[] fileOwner;
            this->fileName = new char[strlen(fo.fileName) + 1];
            strcpy(this->fileName, fo.fileName);
            this->fileOwner = new char[strlen(fo.fileOwner) + 1];
            strcpy(this->fileOwner, fo.fileOwner);
            this->fileSize = fo.fileSize;
            this->ext = fo.ext;
        }
        return *this;
    }

    void eNum()
    {
        switch (ext)
        {
        case txt:
            cout << "txt";
            break;
        case pdf:
            cout << "pdf";
            break;
        case exe:
            cout << "exe";
            break;
        }
    }

    void print()
    {
        cout << "File name: " << this->fileName << ".";
        eNum();
        cout << endl;
        cout << "File owner: " << this->fileOwner << endl;
        cout << "File size: " << this->fileSize << endl;
    }
    // method for checking if two files are equal
    bool equals(const File &that)
    {
        if (strcmp(that.fileName, this->fileName) == 0)
        {
            if (strcmp(that.fileOwner, this->fileOwner) == 0)
            {
                if (that.ext == this->ext)
                {
                    return true;
                }
            }
        }
        else
            return false;
    }
    // method for checking if two files are from the same type
    //т.ш they have same name and ext  r.pdf != r.txt
    bool equalsType(const File &that)
    {
        if (strcmp(this->fileName, that.fileName) == 0)
        {
            if (this->ext == that.ext)
            {
                return true;
            }
        }
        else
            return false;
    }
    ~File()
    {
        delete[] fileName;
        delete[] fileOwner;
    }
};

class Folder
{
private:
    char *folderName;
    int filesNum;
    File *files;

public:
    Folder()
    {
        strcpy(this->folderName, "");
        this->filesNum = 0;
        files = nullptr;
    }
    Folder(const char *name)
    {
        this->folderName = new char[strlen(name) + 1];
        strcpy(this->folderName, name);
        this->filesNum = 0;
        this->files = new File[this->filesNum];
    }

    void print()
    {
        cout << "Folder name: " << this->folderName << endl;
        for (int i = 0; i < this->filesNum; i++)
        {
            this->files[i].print();
        }
    }

    void remove(File &that)
    {
        for (int i = 0; i < this->filesNum; i++)
        {
            if (this->files[i].equals(that))
            {
                --this->filesNum;
                for (int j = i; j < filesNum; j++)
                {
                    this->files[j] = this->files[j + 1];
                }
                break;
            }
        }
    }
    void add(const File &that)
    {
        File *temp = new File[filesNum + 1];
        for (int i = 0; i < this->filesNum; i++)
        {
            temp[i] = this->files[i];
        }
        temp[filesNum++] = that;
        delete[] this->files;
        this->files = temp;
    }

    ~Folder()
    {
        delete[] this->folderName;
        delete[] this->files;
    }
};

int main()
{
    char fileName[20];
    char fileOwner[20];
    int ext;
    int fileSize;

    int testCase;
    cin >> testCase;
    if (testCase == 1)
    {
        cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File created = File(fileName, fileOwner, fileSize, (EXTENSION)ext);
        File copied = File(created);
        File assigned = created;

        cout << "======= CREATED =======" << endl;
        created.print();
        cout << endl;
        cout << "======= COPIED =======" << endl;
        copied.print();
        cout << endl;
        cout << "======= ASSIGNED =======" << endl;
        assigned.print();
    }
    else if (testCase == 2)
    {
        cout << "======= FILE EQUALS AND EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (EXTENSION)ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (EXTENSION)ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (EXTENSION)ext);
        third.print();

        bool equals = first.equals(second);
        cout << "FIRST EQUALS SECOND: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equals = first.equals(third);
        cout << "FIRST EQUALS THIRD: ";
        if (equals)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        bool equalsType = first.equalsType(second);
        cout << "FIRST EQUALS TYPE SECOND: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;

        equalsType = second.equals(third);
        cout << "SECOND EQUALS TYPE THIRD: ";
        if (equalsType)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
    else if (testCase == 3)
    {
        cout << "======= FOLDER CONSTRUCTOR =======" << endl;
        cin >> fileName;
        Folder folder(fileName);
        folder.print();
    }
    else if (testCase == 4)
    {
        cout << "======= ADD FILE IN FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0)
        {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (EXTENSION)ext);
            folder.add(file);
            iter--;
        }
        folder.print();
    }
    else
    {
        cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
        char name[20];
        cin >> name;
        Folder folder(name);

        int iter;
        cin >> iter;

        while (iter > 0)
        {
            cin >> fileName;
            cin >> fileOwner;
            cin >> fileSize;
            cin >> ext;

            File file(fileName, fileOwner, fileSize, (EXTENSION)ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (EXTENSION)ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}