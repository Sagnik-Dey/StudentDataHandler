#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class StudentDataManager
{
private:
    int rollNo;
    string name;
    char section;

public:
    StudentDataManager() {}
    StudentDataManager(int, string, char);
    void setData(int, string, char);
    void fetchData();
};

StudentDataManager::StudentDataManager(int rollNo, string name, char section)
{
    this->rollNo = rollNo;
    this->name = name;
    this->section = section;

    ofstream dataWriteFile;

    dataWriteFile.open("data.txt", ios_base::app);

    if (dataWriteFile.is_open())
    {
        dataWriteFile << this->rollNo << ", " << this->name << ", " << this->section << endl;
    }
    else
    {
        cout << "File is not open";
        return;
    }

    dataWriteFile.close();
}

void StudentDataManager ::setData(int rollNo, string name, char section)
{
    StudentDataManager *student = new StudentDataManager(rollNo, name, section);
}

void StudentDataManager::fetchData()
{
    ifstream dataReadFile;
    string dataString;

    dataReadFile.open("data.txt");

    if (dataReadFile.is_open())
    {
        while (dataReadFile.eof() == 0)
        {
            getline(dataReadFile, dataString);

            cout << dataString << endl;
        }
    }
    else
    {
        cout << "File is not open";
        return;
    }

    dataReadFile.close();
}

int main()
{
    StudentDataManager *student = new StudentDataManager();

    int rollNo, inputNum;
    string name;
    char section;

    while (true)
    {
        cout << "Welcome to Student Manager" << endl
             << "----------------------------" << endl
             << "Press 1 to set Student Data: " << endl
             << "Press 2 to fetch Student Data: " << endl
             << "Press 3 to exit: " << endl;

        cin >> inputNum;

        if (inputNum == 1)
        {
            cout << "Enter the Roll No: ";
            cin >> rollNo;

            cout << "Enter the Name: ";
            cin >> name;

            cout << "Enter the Section: ";
            cin >> section;

            student->setData(rollNo, name, section);

            cout << "Data added successfully...." << endl
                 << endl;
        }
        else if (inputNum == 2)
        {
            student->fetchData();
        }
        else if (inputNum == 3)
        {
            break;
        }
    }

    return 0;
}
