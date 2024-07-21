// Program to convert Cartesian coordinate to Polar.

#include <iostream>
#include <cmath>
using namespace std;

class Polar
{
    float radius, angle;

public:
    Polar(float rad = 0, float ang = 0)
    {
        radius = rad;
        angle = ang;
    }

    void display()
    {
        cout << "Polar Coordinates: (" << radius << ", " << angle << ")" << endl;
    }
};

class Cartesian
{
    float x, y;

public:
    Cartesian(int x1 = 0, int y1 = 0)
    {
        x = x1;
        y = y1;
    }

    void input()
    {
        cout << "Enter x: ";
        cin >> x;
        cout << "Enter y: ";
        cin >> y;
    }

    operator Polar()
    {
        float radius = sqrt(x * x + y * y);
        float angleRad = atan2(y, x);
        float angle = angleRad * 180 / 3.14159;
        return Polar(radius, angle);
    }

    void display()
    {
        cout << "Cartesian Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Cartesian c1;
    c1.input();
    Polar p1 = c1;
    c1.display();
    p1.display();
    return 0;
}