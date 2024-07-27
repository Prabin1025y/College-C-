// 1.Assume class person stores the Name, Age and ID, class employee stores the designation, basic salary, total overtime(hr) in a month and hourly rate and class computedSalary stores the total salary of the employee. Implement above concept using appropriate inheritance.

#include <iostream>

using namespace std;

class Person
{
    string name;
    int age, id;

public:
    Person(string n = "", int a = 0, int i = 0)
    {
        name = n;
        age = a;
        id = i;
    }

    void input()
    {
        cout << "Enter name, age and ID: ";
        cin >> name >> age >> id;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }
};

class Employee : public Person
{
    string designation;

protected:
    float basicSalary, totalOvertime, hourlyRate;

public:
    Employee(string n = "", int a = 0, int i = 0, string d = "", float b = 0, float t = 0, float h = 0) : Person(n, a, i)
    {
        designation = d;
        basicSalary = b;
        totalOvertime = t;
        hourlyRate = h;
    }

    void input()
    {
        Person::input();
        cout << "Enter designation, basic salary, total overtime and hourly rate: ";
        cin >> designation >> basicSalary >> totalOvertime >> hourlyRate;
    }

    void display()
    {
        Person::display();
        cout << "Designation: " << designation << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Total Overtime: " << totalOvertime << endl;
        cout << "Hourly Rate: " << hourlyRate << endl;
    }
};

class ComputedSalary : public Employee
{
    float totalSalary;

public:
    ComputedSalary(string n = "", int a = 0, int i = 0, string d = "", float b = 0, float t = 0, float h = 0) : Employee(n, a, i, d, b, t, h)
    {}

    void display()
    {
        totalSalary = basicSalary + (totalOvertime * hourlyRate);
        Employee::display();
        cout << "Total Salary: " << totalSalary << endl;
    }
};

int main()
{
    ComputedSalary c;
    c.input();
    c.display();

    return 0;
}