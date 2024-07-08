// To write a program to categorize employees based on designation using
// static data members.

#include <iostream>
#include <string>
using namespace std;

class Employee
{

    int empId;
    string empName;
    string designation;

public:
    static int managerCount, engineerCount, employeeCount;
    void DataEntry()
    {
        cout << "Employee Id: ";
        cin >> empId;
        cout << "Employee Name: ";
        cin >> empName;
        cout << "Designation: ";
        cin >> designation;

        if (designation == "manager")
        {
            cout << "Manager" << endl;
            managerCount++;
            employeeCount++;
            
        }
        else if (designation == "engineer")
        {
            cout << "Engineer" << endl;
            engineerCount++;
            employeeCount++;
        }
        else
            employeeCount++;
    }

    static void DisplayCount()
    {
        cout << "Total Employees: " << employeeCount << "\nTotal Managers: " << managerCount << "\nTotal Engineers: " << engineerCount << endl;
    }
};

int Employee::managerCount = 0;
int Employee::employeeCount = 0;
int Employee::engineerCount = 0;

int main()
{
    const int MAX_NUM = 100;
    Employee employees[MAX_NUM];

    int n;
    cout << "How Many Employees are there (max 200) : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        employees[i].DataEntry();
    }

    Employee::DisplayCount();

    return 0;
}