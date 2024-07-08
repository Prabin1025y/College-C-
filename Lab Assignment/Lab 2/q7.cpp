// Overload >> and << operators to input and display time.

#include <iostream>
using namespace std;

class TIME
{
private:
    int hours;
    int minutes;
    int seconds;

    void calculate() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

public:
    TIME() : hours(0), minutes(0), seconds(0) {}

    TIME(int h, int m, int s) : hours(h), minutes(m), seconds(s) {
        calculate();
    }

    // Overload << operator for output
    friend ostream &operator<<(ostream &os, TIME &t);

    // Overload >> operator for input
    friend istream &operator>>(istream &is, TIME &t);
};

ostream &operator<<(ostream &os, TIME &t)
{
    os << t.hours << ":" << t.minutes << ":" << t.seconds;
    return os;
}

istream &operator>>(istream &is, TIME &t)
{
    is >> t.hours >> t.minutes >> t.seconds;
    t.calculate();
    return is;
}

int main()
{
    TIME t1, t2;

    cout << "Enter the first time (HH:MM:SS): ";
    cin >> t1;

    cout << "Enter the second time (HH:MM:SS): ";
    cin >> t2;

    cout << "First time: " << t1 << endl;
    cout << "Second time: " << t2 << endl;

    return 0;
}
