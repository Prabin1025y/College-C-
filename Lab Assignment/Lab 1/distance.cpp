#include <iostream>
using namespace std;

class Distance
{
    int feet, inches;

public:
    Distance()
    {
        feet = 0;
        inches = 0;
    }

    void inputDistance()
    {
        cout << "Enter feet ";
        cin >> feet;
        cout << "Enter inches ";
        cin >> inches;
        if (inches >= 12)
        {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    void outputDistance()
    {

        cout << feet << " feet " << inches << " inches" << endl;
    }

    Distance addDistance(Distance d2)
    {
        Distance t;
        t.feet = feet + d2.feet;
        t.inches = inches + d2.inches;
        // cout << feet << d2.feet << inches << d2.inches;

        if (t.inches >= 12)
        {
            t.feet += t.inches / 12;
            t.inches = t.inches % 12;
        }

        return t;
    }
};

int main()
{
    Distance d1, d2, d3;
    d1.inputDistance();
    d2.inputDistance();
    // d1.outputDistance();
    // d2.outputDistance();
    d3 = d1.addDistance(d2);
    d3.outputDistance();
    return 0;
}