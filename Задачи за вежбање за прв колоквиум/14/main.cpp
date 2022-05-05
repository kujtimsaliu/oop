#include<iostream>
#include<cstring>

using namespace std;

enum Extension
{
    txt,pdf,exe
};

class File
{
private:
    char *fileName;
    Extension ext;
    char *fileOwner;
    int fileSize;
    void copy(cont File &other){
        this->fileName = new char[strlen(other.fileName)+1];
        this->fileOwner = new char[strlen(other.fileOwner)+1];
        strcpy(this->fileName, other.fileName);
        strcpy(this->fileOwner, other.fileOwner);
        this->ext = other.ext;
        this->fileSize = other.fileSize;
    }
public:
    File()
    {
        strcpy(fileName, "NONE");
        ext = 0;
        strcpy(fileOwner, "NONE");
        fileSize=0;
    }
    File(char *fileName, char *fileOwner, int fileSize, Extension ext)
    {
        this->fileName = new char[strlen(fileName)+1];
        this->fileOwner = new char[strlen(fileOwner)+1];
        strcpy(this->fileName, fileName);
        strcpy(this->fileOwner, fileOwner);
        this->ext = ext;
        this->fileSize = fileSize;
    }
    File(const File &other){ copy(other); }
    File &operator = (const File & other){
        if(this!=&other){
            delete[]fileName; delete[]fileOwner;
            copy(other);
        } return *this; }
    ~File(){ delete[]fileOwner; delete[]fileName; }
    void print(){
        //cout << "Folder name: " << fileName << endl;
        cout << "File name: " << fileName << "." << ext;
        cout << endl;
        cout << "File owner: " << fileOwner << endl;
        cout <<"File size: " <<fileSize << endl;

    }

};

int main() {
	char fileName[20];
	char fileOwner[20];
	int ext;
	int fileSize;

	int testCase;
	cin >> testCase;
	if (testCase == 1) {
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File created = File(fileName, fileOwner, fileSize, (Extension) ext);
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
	else if (testCase == 2) {
		cout << "======= FILE EQUALS & EQUALS TYPE =======" << endl;
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File first(fileName, fileOwner, fileSize, (Extension) ext);
		first.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File second(fileName, fileOwner, fileSize, (Extension) ext);
		second.print();

		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File third(fileName, fileOwner, fileSize, (Extension) ext);
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
	else if (testCase == 3) {
		cout << "======= FOLDER CONSTRUCTOR =======" << endl;
		cin >> fileName;
		Folder folder(fileName);
		folder.print();

	}
	else if (testCase == 4) {
		cout << "======= ADD FILE IN FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		folder.print();
	}
	else {
		cout << "======= REMOVE FILE FROM FOLDER =======" << endl;
		char name[20];
		cin >> name;
		Folder folder(name);

		int iter;
		cin >> iter;

		while (iter > 0) {
			cin >> fileName;
			cin >> fileOwner;
			cin >> fileSize;
			cin >> ext;

			File file(fileName, fileOwner, fileSize, (Extension) ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName;
		cin >> fileOwner;
		cin >> fileSize;
		cin >> ext;

		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.remove(file);
		folder.print();
	}
	return 0;
}
