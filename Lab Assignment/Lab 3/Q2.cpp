// Program to convert Polar Coordinate to Cartesian.

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
    void input()
    {
        cout << "Enter radius: ";
        cin >> radius;
        cout << "Enter angle: ";
        cin >> angle;
    }
    void display()
    {
        cout << "Polar Coordinates: (" << radius << ", " << angle << ")" << endl;
    }
    float getRadius()
    {
        return radius;
    }
    float getAngle()
    {
        return angle;
    }
};

class Cartesian
{
    float x, y;

public:
    void display()
    {
        cout << "Cartesian Coordinates: (" << x << ", " << y << ")" << endl;
    }

    Cartesian(Polar p)
    {
        x = p.getRadius() * cos(p.getAngle());
        y = p.getRadius() * sin(p.getAngle());
    }
};

int main()
{
    Polar p1;
    p1.input();
    Cartesian c1 = p1;
    p1.display();
    c1.display();
    return 0;
}