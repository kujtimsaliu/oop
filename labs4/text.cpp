#include <iostream>
#include <cstring>
using namespace std;

enum Extension
{
	txt,
	pdf,
	exe
};
char enumConv[3][4] = {"pdf", "txt", "exe"};

class File
{
private:
	char *fileName{nullptr}, *ownerName{nullptr};
	Extension ext;
	int fileSize;

public:
	File()
	{
		fileName = nullptr;
		ownerName = nullptr;
	}

	File(char *n, char *o, int s, Extension ext) : File()
	{
		this->fileName = new char[strlen(n) + 1];
		strcpy(this->fileName, n);
		this->ownerName = new char[strlen(o) + 1];
		strcpy(this->ownerName, o);
		this->fileSize = s;
		this->ext = ext;
	}

	File(const File &other) : File()
	{
		if (this != &other)
		{
			delete[] fileName;
			this->fileName = new char[strlen(other.fileName) + 1];
			strcpy(this->fileName, other.fileName);
			delete[] ownerName;
			this->ownerName = new char[strlen(other.ownerName) + 1];
			strcpy(this->ownerName, other.ownerName);
			this->fileSize = other.fileSize;
			this->ext = other.ext;
		}
	}

	File &operator=(const File &other)
	{
		if (this != &other)
		{
			delete[] fileName;
			this->fileName = new char[strlen(other.fileName) + 1];
			strcpy(this->fileName, other.fileName);
			delete[] ownerName;
			this->ownerName = new char[strlen(other.ownerName) + 1];
			strcpy(this->ownerName, other.ownerName);
			this->fileSize = other.fileSize;
			this->ext = other.ext;
		}
		return *this;
	}

	~File()
	{
		delete[] fileName;
		delete[] ownerName;
	}

	void print()
	{
		cout << "File name: " << this->fileName << "." << enumConv[this->ext] << endl
			 << "File owner: " << this->ownerName << endl
			 << "File size: " << this->fileSize << endl;
	}

	bool equals(const File &other)
	{
		if ((strcmp(this->fileName, other.fileName) == 0) && (strcmp(this->ownerName, other.ownerName) == 0) && (this->ext == other.ext))
		{
			return true;
		}
		else
			return false;
	}

	bool equalsType(const File &other)
	{
		if ((strcmp(this->fileName, other.fileName) == 0) && this->ext == other.ext)
		{
			return true;
		}
		else
			return false;
	}
};

class Folder
{
private:
	char *folderName;
	int num;
	File *arr;

public:
	Folder()
	{
		folderName = nullptr;
		this->num = 0;
		arr = nullptr;
	};
	Folder(const char *name)
	{
		this->folderName = new char[strlen(name) + 1];
		strcpy(this->folderName, name);
		this->num = 0;
		this->arr = new File[this->num];
	}
	~Folder()
	{
		delete[] this->folderName;
		delete[] this->arr;
	};

	void print()
	{
		cout << "Folder name: " << this->folderName << endl;
		for (int i = 0; i < this->num; i++)
		{
			this->arr[i].print();
		}
	}

	void remove(File &sub)
	{
		for (int i = 0; i < this->num; i++)
		{
			if (this->arr[i].equals(sub))
			{
				--this->num;
				for (int j = i; j < this->num; j++)
				{
					this->arr[j] = this->arr[j + 1];
				}
				break;
			}
		}
	}

	void add(const File &other)
	{
		File *tmp = new File[num + 1];
		for (int i = 0; i < this->num; i++)
		{
			tmp[i] = this->arr[i];
		}
		tmp[num++] = other;
		delete[] this->arr;
		this->arr = tmp;
	}
};

int main()
{
	char fileName[20], fileOwner[20];
	int ext, fileSize, testCase;
	cin >> testCase;
	if (testCase == 1)
	{
		cout << "======= FILE CONSTRUCTORS AND = OPERATOR =======" << endl;
		cin >> fileName >> fileOwner >> fileSize >> ext;

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
		cout << "======= FILE EQUALS AND EQUALS TYPE =======" << endl;
		cin >> fileName >> fileOwner >> fileSize >> ext;
		File first(fileName, fileOwner, fileSize, (Extension)ext);
		first.print();

		cin >> fileName >> fileOwner >> fileSize >> ext;
		File second(fileName, fileOwner, fileSize, (Extension)ext);
		second.print();

		cin >> fileName >> fileOwner >> fileSize >> ext;
		File third(fileName, fileOwner, fileSize, (Extension)ext);
		third.print();

		bool equals = first.equals(second);
		cout << "FIRST EQUALS SECOND: ";
		if (equals)
		{
			cout << "TRUE" << endl;
		}
		else
		{
			cout << "FALSE" << endl;
		}

		equals = first.equals(third);
		cout << "FIRST EQUALS THIRD: ";
		if (equals)
		{
			cout << "TRUE" << endl;
		}
		else
		{
			cout << "FALSE" << endl;
		}

		bool equalsType = first.equalsType(second);
		cout << "FIRST EQUALS TYPE SECOND: ";
		if (equalsType)
		{
			cout << "TRUE" << endl;
		}
		else
		{
			cout << "FALSE" << endl;
		}

		equalsType = second.equals(third);
		cout << "SECOND EQUALS TYPE THIRD: ";
		if (equalsType)
		{
			cout << "TRUE" << endl;
		}
		else
		{
			cout << "FALSE" << endl;
		}
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
			cin >> fileName >> fileOwner >> fileSize >> ext;
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
			cin >> fileName >> fileOwner >> fileSize >> ext;
			File file(fileName, fileOwner, fileSize, (Extension)ext);
			folder.add(file);
			iter--;
		}
		cin >> fileName >> fileOwner >> fileSize >> ext;
		File file(fileName, fileOwner, fileSize, (Extension)ext);
		folder.remove(file);
		folder.print();
	}
	return 0;
}