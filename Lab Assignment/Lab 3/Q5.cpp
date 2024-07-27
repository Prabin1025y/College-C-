// Program to convert time (hour, minute and second) in 12-hr format to 24-hr format.

#include <iostream>
using namespace std;

class Time24
{
    int hour, minute, second;

public:
    Time24(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        minute = m;
        second = s;

        if (h > 23 || m > 59 || s > 59 || h < 0 || m < 0 || s < 0)
        {
            cout << "Invalid time." << endl;
            exit(1);
        }
    }

    void input()
    {
        cout << "Enter time in 24-hr format (hh:mm:ss): ";
        cin >> hour >> minute >> second;

        if (hour > 23 || minute > 59 || second > 59 || hour < 0 || minute < 0 || second < 0)
        {
            cout << "Invalid time." << endl;
            exit(1);
        }
    }

    void display()
    {
        cout << "Time in 24-hr format: " << hour << ":" << minute << ":" << second << endl;
    }
};

class Time12
{
    int hour, minute, second;
    bool am;

public:
    Time12(int h = 1, int m = 0, int s = 0, bool a = true)
    {
        hour = h;
        minute = m;
        second = s;
        am = a;

        if (h > 12 || m > 59 || s > 59 || h <= 0 || m < 0 || s < 0)
        {
            cout << "Invalid time." << endl;
            exit(1);
        }
    }

    operator Time24()
    {
        if (am == false)
        {
            if (hour == 12)
            {
                return Time24(hour, minute, second);
            }
            return Time24(hour + 12, minute, second);
        }
        else if (am == true && hour == 12)
        {
            return Time24(0, minute, second);
        }
        return Time24(hour, minute, second);
    }

    void input()
    {
        cout << "Enter time in 12-hr format (hh:mm:ss) (1 for am | 0 for pm): ";
        cin >> hour >> minute >> second >> am;

        if (hour > 12 || minute > 59 || second > 59 || hour <= 0 || minute < 0 || second < 0)
        {
            cout << "Invalid time." << endl;
            exit(1);
        }
    }

    void display()
    {
        cout << "Time in 12-hr format: " << hour << ":" << minute << ":" << second << " " << (am ? "AM" : "PM") << endl;
    }
};

int main()
{
    Time12 t1;
    t1.input();
    Time24 t2 = t1;
    t1.display();
    t2.display();
    return 0;
}
