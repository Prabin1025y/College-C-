// Program: Given that an EMPLOYEE class contains following members:
// data members: Employee number, Employee name, Basic, DA, IT, Net Salary
// and print data members. Write a C++ program to read the data of N employee
// and compute Net salary of each employee (DA=52% of Basic and Income Tax
// (IT) =30% of the gross salary) .

#include <iostream>
using namespace std;

class Employee
{
    int empNum;
    char empName[100];
    float basicSalary, dailyAllowance, incomeTax, netSalary;

public:
    void DataEntry()
    {
        cout << "Employee number: ";
        cin >> empNum;
        cout << "Name: ";
        cin >> empName;
        cout << "Basic Salary: ";
        cin >> basicSalary;

        dailyAllowance = 0.52 * basicSalary;
        incomeTax = 0.3 * (basicSalary + dailyAllowance);

        netSalary = basicSalary + dailyAllowance - incomeTax;
    }

    void Display()
    {
        cout << "The net sallary of employee number " << empNum << " is " << netSalary << endl;
    }
};

int main()
{
    const int MAX_NUM = 100;
    Employee employees[MAX_NUM];

    int n;
    cout << "How many employees are there (Max 100)";
    cin >> n;

    cout << "Enter the details of employees: ";
    for (int i = 0; i < n; i++)
    {
        employees[i].DataEntry();
    }

    for (int i = 0; i < n; i++)
    {
        employees[i].Display();
    }

    return 0;
}
