#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter any three numbers: " << endl;
    cin >> a >> b >> c;
    if (a > b && a > c)
    {
        cout << a << " is greatest ";
        if (b < c)
            cout << " and " << b << " is smallest ";
        else
            cout << " and " << c << " is smallest ";
    }
    else if (b > a && b > c)
    {
        cout << b << " is greatest ";
        if (a < c)
            cout << " and " << a << " is smallest ";
        else
            cout << " and " << c << " is smallest ";
    }
    else
    {
        cout << c << " is greatest ";
        if (b < a)
            cout << " and " << b << " is smallest ";
        else
            cout << " and " << a << " is smallest ";
    }
    return 0;
}