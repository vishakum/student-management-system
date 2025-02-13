#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
using namespace std;
class student
{
private:
    string Name, stu_id, Course, Number, Email_id, Address;

public:
    void menu();
    void insert();
    void Display();
    void Modify();
    void Search();
    void Delete();
};
void student::menu()
{
menustart:
    int choice;
    char x;
    system("cls");
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\t|       Student Management System        |\n";
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\t1. Enter New Record \n";
    cout << "\t\t\t2. Display Record \n";
    cout << "\t\t\t3. Modify Record \n";
    cout << "\t\t\t4. Search Record \n";
    cout << "\t\t\t5. Delete Record \n";
    cout << "\t\t\t6. Exit \n";
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\tSelect and option[1,2,3,4,5,6]\n";
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\tEnter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "Do you want to add another student(Y/N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        Display();
        break;
    case 3:
        Modify();
        break;
    case 4:
        Search();
        break;
    case 5:
        Delete();
        break;
    case 6:
        exit(0);
    default:
        cout << "\t\t\tInvalid choice.... Please try again\n";
    }
    getch();
    goto menustart;
}
void student::insert()
{
    system("cls");
    fstream file;
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\t|          add Student Details           |\n";
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\tEnter Student Name: ";
    cin >> Name;
    cout << "\t\t\tEnter Student Stu_id: ";
    cin >> stu_id;
    cout << "\t\t\tEnter Student Course: ";
    cin >> Course;
    cout << "\t\t\tEnter Student Contact Number: ";
    cin >> Number;
    cout << "\t\t\tEnter Student Email id: ";
    cin >> Email_id;
    cout << "\t\t\tEnter Student Address: ";
    cin >> Address;
    file.open("studentrecod.xls", ios::app | ios::out);
    file << " " << Name << " " << stu_id << " " << Course << " " << Number << " " << Email_id << " " << Address << "\n";
    file.close();
}
void student::Display()
{
    system("cls");
    fstream file;
    int total = 0;
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\t|         Display Student Details        |\n";
    cout << "\t\t\t------------------------------------------\n";
    file.open("studentrecod.xls", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tStudents Details not available..... ";
        file.close();
    }
    else
    {
        file >> Name >> stu_id >> Course >> Number >> Email_id >> Address;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student No.: " << total++ << endl;
            cout << "\n\n\t\t\t Student Name: " << Name << endl;
            cout << "\n\n\t\t\t Student stu_id: " << stu_id << endl;
            cout << "\n\n\t\t\t Student Course: " << Course << endl;
            cout << "\n\n\t\t\t Student Number: " << Number << endl;
            cout << "\n\n\t\t\t Student Email id.: " << Email_id << endl;
            cout << "\n\n\t\t\t Student Address: " << Address << endl;
            file >> Name >> stu_id >> Course >> Number >> Email_id >> Address;
        }
        if (total == 0)
        {
            cout << "Students Details not available..... ";
        }
    }
    file.close();
}
void student::Modify()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string stuid;
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\t|         Modify Student Details         |\n";
    cout << "\t\t\t------------------------------------------\n";
    file.open("studentrecod.xls", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tStudents Details not available..... ";
        file.close();
    }
    else
    {
        cout << "\n Enter roll Stu id of student which you want to modify: ";
        cin >> stuid;
        file1.open("recod.xls", ios::app | ios::out);
        file >> Name >> stu_id >> Course >> Number >> Email_id >> Address;
        while (!file.eof())
        {
            if (stuid != stu_id)
            {
                file1 << " " << Name << " " << stu_id << " " << Course << " " << Number << " " << Email_id << " " << Address << "\n";
            }
            else
            {
                cout << "\t\t\tEnter Student Name: ";
                cin >> Name;
                cout << "\t\t\tEnter Student Stu_id: ";
                cin >> stu_id;
                cout << "\t\t\tEnter Student Course: ";
                cin >> Course;
                cout << "\t\t\tEnter Student Contact Number: ";
                cin >> Number;
                cout << "\t\t\tEnter Student Email id: ";
                cin >> Email_id;
                cout << "\t\t\tEnter Student Address: ";
                cin >> Address;
                file1 << " " << Name << " " << stu_id << " " << Course << " " << Number << " " << Email_id << " " << Address << "\n";
                found++;
            }
            file >> Name >> stu_id >> Course >> Number >> Email_id >> Address;
            if (found == 0)
            {
                cout << "\n\t\t\t Stu id not found.......";
            }
        }
        file1.close();
        file.close();
        remove("studentrecod.xls");
        rename("recod.xls", "studentrecod.xls");
    }
}
void student::Search()
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentrecod.xls", ios::in);
    if (!file)
    {
        cout << "\t\t\t------------------------------------------\n";
        cout << "\t\t\t|         Search Student Details         |\n";
        cout << "\t\t\t------------------------------------------\n";
        cout << "\n\t\t\tStudents Details not available..... ";
    }
    else
    {
        string stuid;
        cout << "\t\t\t------------------------------------------\n";
        cout << "\t\t\t|         Search Student Details         |\n";
        cout << "\t\t\t------------------------------------------\n";
        cout << "\n Enter Stu id of Student you want to search: ";
        cin >> stuid;
        file >> Name >> stu_id >> Course >> Number >> Email_id >> Address;
        while (!file.eof())
        {
            if (stuid == stu_id)
            {
                cout << "\t\t\tEnter Student Name: " << Name << endl;
                cout << "\t\t\tEnter Student Stu_id: " << stu_id << endl;
                cout << "\t\t\tEnter Student Course: " << Course << endl;
                cout << "\t\t\tEnter Student Contact Number: " << Number << endl;
                cout << "\t\t\tEnter Student Email id: " << Email_id << endl;
                cout << "\t\t\tEnter Student Address: " << Address << endl;
                found++;
            }
            file >> Name >> stu_id >> Course >> Number >> Email_id >> Address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Stu id not found.......";
        }
        file.close();
    }
}
void student::Delete()
{
    system("cls");
    fstream file, file1;
    string stuid;
    int found = 0;
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\t|         Delete Student Record          |\n";
    cout << "\t\t\t------------------------------------------\n";
    file.open("studentrecod.xls", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tStudents Details not available..... ";
    }
    else
    {
        cout << "\n Enter Stu id of Student you want to Delete: ";
        cin >> stuid;
        file1.open("recod.xls", ios::app | ios::out);
        file >> Name >> stu_id >> Course >> Number >> Email_id >> Address;
        while (!file.eof())
        {
            if (stuid != stu_id)
            {
                file1 << " " << Name << " " << stu_id << " " << Course << " " << Number << " " << Email_id << " " << Address << "\n";
            }
            file >> Name >> stu_id >> Course >> Number >> Email_id >> Address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student id is deleted.....";
        }
        file1.close();
        file.close();
        remove("studentrecod.xls");
        rename("recod.xls", "studentrecod.xls");
    }
}

main()
{
    student project;
    project.menu();

    return 0;
}
