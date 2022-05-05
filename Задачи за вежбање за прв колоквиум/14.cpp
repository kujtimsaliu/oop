#include <iostream>
#include <cstring>

using namespace std;
enum Extension
{
    pdf,
    txt,
    exe
};
class File
{
private:
    char *fileName;
    Extension type;
    char *fileOwner;
    int fileSize;
    void copy(const File &other)
    {
        this->fileName = new char[strlen(other.fileName) + 1];
        strcpy(this->fileName, other.fileName);
        this->fileOwner = new char[strlen(other.fileOwner) + 1];
        strcpy(this->fileOwner, other.fileOwner);
        this->fileSize = other.fileSize;
        this->type = other.type;
    }

public:
    File()
    {
        fileSize = 0;
        type = (Extension)0;
    }
    File(char *fileName, char *fileOwner, int fileSize, Extension ext)
    {
        this->fileName = new char[strlen(fileName) + 1];
        strcpy(this->fileName, fileName);
        this->fileOwner = new char[strlen(fileOwner) + 1];
        strcpy(this->fileOwner, fileOwner);
        this->fileSize = fileSize;
        this->type = ext;
    }
    File(const File &f)
    {
        copy(f);
    }
    File &operator=(const File &f)
    {
        if (this != &f)
        {
            delete[] fileName;
            delete[] fileOwner;
            copy(f);
        }
        return *this;
    }
    ~File()
    {
        delete[] fileName;
        delete[] fileOwner;
    }
    void print()
    {
        cout << "File name: " << fileName << ".";
        switch (type)
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
        cout << endl;
        cout << "File owner: " << fileOwner << endl;
        cout << "File size: " << fileSize << endl;
    }
    bool equals(const File &that)
    {
        return ((strcmp(this->fileName, that.fileName) == 0) && (strcmp(this->fileOwner, that.fileOwner) == 0) && (this->type == that.type));
    }
    bool equalsType(const File &that)
    {
        return ((strcmp(this->fileName, that.fileName) == 0) && (this->type == that.type));
    }
};

class Folder
{
private:
    char *folderName;
    int numberofFiles; // starting at 0
    File *files;

public:
    // Folder()
    // {
    //     // this->folderName="";
    //     this->numberofFiles = 0;
    //     this->files = new File[0];
    // }
    Folder(const char *folderName)
    {
        this->folderName = new char[strlen(folderName) + 1];
        strcpy(this->folderName, folderName);
        this->numberofFiles = 0;
        this->files = new File[0];
    }
    ~Folder()
    {
        delete[] files;
        delete[] folderName;
    }
    void print()
    {
        cout << "Folder name: " << folderName << endl;
        for (int i = 0; i < numberofFiles; i++)
        {
            files[i].print();
        }
    }
    void remove(const File &file)
    {
        bool flag = false;
        File *tmp = new File[numberofFiles];
        for (int i = 0; i < numberofFiles; i++)
        {
            if (!(files[i].equals(file)))
            {
                // remove the file somehow u dumb bitch
                tmp[i] = files[i];
            }
            else
            {
                flag = true;
            }
        }
        delete[] files;
        files = tmp;
        if (flag)
        {
            numberofFiles--;
        }
    }
    void add(const File &file)
    {
        File *tmp = new File[numberofFiles + 1];
        for (int i = 0; i < numberofFiles; i++)
        {
            tmp[i] = this->files[i];
        }
        tmp[numberofFiles++] = file;
        delete[] files;
        files = tmp;
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

        File created = File(fileName, fileOwner, fileSize, (Extension)ext);
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
        cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File first(fileName, fileOwner, fileSize, (Extension)ext);
        first.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File second(fileName, fileOwner, fileSize, (Extension)ext);
        second.print();

        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File third(fileName, fileOwner, fileSize, (Extension)ext);
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

            File file(fileName, fileOwner, fileSize, (Extension)ext);
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

            File file(fileName, fileOwner, fileSize, (Extension)ext);
            folder.add(file);
            iter--;
        }
        cin >> fileName;
        cin >> fileOwner;
        cin >> fileSize;
        cin >> ext;

        File file(fileName, fileOwner, fileSize, (Extension)ext);
        folder.remove(file);
        folder.print();
    }
    return 0;
}
