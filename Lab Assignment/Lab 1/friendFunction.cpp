// To write a C++ program to add two private data members using friend functions.

#include <iostream>
using namespace std;

class Complex
{
    int real, img;

public:
    Complex(int rl = 0,int  im = 0)
    {
        real = rl;
        img = im;
    }

    friend Complex AddNumbers(Complex c1, Complex c2);

    void ShowNumber()
    {
        cout << real << "+" << img << "i" << endl;
    }
};

Complex AddNumbers(Complex c1, Complex c2)
{
    Complex t;
    t.real = c1.real + c2.real;
    t.img = c1.img + c2.img;
    return t;
}

int main()
{

    Complex c1(2, 4), c2(3, 6), c3;
    c1.ShowNumber();
    c2.ShowNumber();
    c3 = AddNumbers(c1, c2);
    c3.ShowNumber();
    return 0;
}