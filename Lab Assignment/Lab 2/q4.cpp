// Create a class called 'TIME' that has
// - three integer data members for hours, minutes and seconds
// - constructor to initialize the object to zero
// - constructor to initialize the object to some constant value
// - overload +,- to add and subtract two TIME objects
// - overload > function to compare two time
// - member function to display time in HH:MM:SS format

#include <iostream>
using namespace std;

class TIME
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    TIME() : hours(0), minutes(0), seconds(0) {}

    TIME(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void display() 
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }

    TIME operator+( TIME t)
    {
        int totalSeconds = (hours + t.hours) * 3600 + (minutes + t.minutes) * 60 + (seconds + t.seconds);
        int h = totalSeconds / 3600;
        totalSeconds %= 3600;
        int m = totalSeconds / 60;
        int s = totalSeconds % 60;
        return TIME(h, m, s);
    }

    TIME operator-(TIME t)
    {
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = t.hours * 3600 + t.minutes * 60 + t.seconds;
        int diffSeconds = totalSeconds1 - totalSeconds2;

        int h = diffSeconds / 3600;
        diffSeconds %= 3600;
        int m = diffSeconds / 60;
        int s = diffSeconds % 60;
        return TIME(h, m, s);
    }

    bool operator>(const TIME &t) const
    {
        if (hours > t.hours)
            return true;
        if (hours == t.hours && minutes > t.minutes)
            return true;
        if (hours == t.hours && minutes == t.minutes && seconds > t.seconds)
            return true;
        return false;
    }
};

int main()
{
    TIME t1(2, 30, 45);
    TIME t2(1, 45, 30);

    TIME t3 = t1 + t2;
    TIME t4 = t1 - t2;

    cout << "Time t1: ";
    t1.display();
    cout << "Time t2: ";
    t2.display();
    cout << "Time t1 + t2: ";
    t3.display();
    cout << "Time t1 - t2: ";
    t4.display();

    if (t1 > t2)
    {
        cout << "Time t1 is greater than t2" << endl;
    }
    else
    {
        cout << "Time t1 is not greater than t2" << endl;
    }

    return 0;
}
