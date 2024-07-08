//write a c++ program to swap two private data members using friend functions.

#include <iostream>
using namespace std;

class Numbers
{
    int num;

public:
    void input()
    {
        cout << "Enter the number" << endl;
        cin >> num;
    }

    void output()
    {
        cout << "The number is " << num << endl;
    }

    friend void swap(Numbers &n1, Numbers &n2);
};

void swap(Numbers &n1, Numbers &n2)
{
    int temp = n1.num;
    n1.num = n2.num;
    n2.num = temp;
}

int main()
{
    Numbers n1, n2;

    n1.input();
    n2.input();
    swap(n1, n2);
    n1.output();
    n2.output();

    return 0;
}