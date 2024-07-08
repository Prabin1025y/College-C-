// To write a C++ program to manipulate complex numbers using operator overloading. (addition,subtraction,multiplication,division)

#include <iostream>
using namespace std;

class Complex
{
    int real;
    int img;

public:
    Complex(int rl = 0, int im = 0) : real(rl), img(im) {}

    void display()
    {
        cout << real << "+" << img << "i" << endl;
    }

    Complex operator+(Complex other)
    {
        return Complex(real + other.real, img + other.img);
    }

    Complex operator-(Complex other)
    {
        return Complex(real - other.real, img - other.img);
    }

    Complex operator*(Complex other)
    {
        return Complex(real * other.real - img * other.img, real * other.img + img * other.real);
    }

    Complex operator/(Complex other)
    {
        double denominator = other.real * other.real + other.img * other.img;
        return Complex((real * other.real - img * other.img) / denominator, (real * other.img + img * other.real) / denominator);
    }
};

int main()
{

    Complex c1(5, 2), c2(3, 2);
    c1.display();
    c2.display();
    Complex ca = c1 + c2;
    ca.display();
    Complex cs = c1 - c2;
    cs.display();
    Complex cm = c1 * c2;
    cm.display();
    Complex cd = c1 / c2;
    cd.display();

    return 0;
}
