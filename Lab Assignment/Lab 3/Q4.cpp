// 4.Program to convert time (hour, minute and second) in 24-hr format to 12-hr format.

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

    int getHour()
    {
        return hour;
    }

    int getMinute()
    {
        return minute;
    }

    int getSecond()
    {
        return second;
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
    Time12(int h = 0, int m = 0, int s = 0, char *a = "am")
    {
        hour = h;
        minute = m;
        second = s;
        am = (a == "am") ? true : false;

        if (h > 12 || m > 59 || s > 59 || h < 0 || m < 0 || s < 0)
        {
            cout << "Invalid time." << endl;
            exit(1);
        }
    }

    Time12(Time24 t24)
    {
        if (t24.getHour() > 12)
        {
            hour = t24.getHour() - 12;
            am = false;
        }
        else if (t24.getHour() == 0)
        {
            hour = 12;
            am = true;
        }
        else
        {
            hour = t24.getHour();
            am = true;
        }

        minute = t24.getMinute();
        second = t24.getSecond();
    }

    void input()
    {
        cout << "Enter time in 12-hr format (hh:mm:ss am?true/false): ";
        cin >> hour >> minute >> second >> am;
    }

    void display()
    {
        cout << "Time in 12-hr format: " << hour << ":" << minute << ":" << second << " " << (am ? "AM" : "PM") << endl;
    }
};

int main()
{
    Time24 t24;
    t24.input();
    Time12 t12 = t24;
    t24.display();
    t12.display();
    return 0;
}
