// Program to convert Nepalese Currency (Rupees and Paisa) to US Currency (Dollar and Cents). (Rs. 98.51=1$)

#include <iostream>
#include <cmath>
#include <cstring>
#define USD_TO_NPR 98.51
using namespace std;

class USCurrency
{
    int dollar, cents;

public:
    USCurrency(int d = 0, int c = 0)
    {
        dollar = d;
        cents = c;

        if (cents >= 100)
        {
            dollar += cents / 100;
            cents %= 100;
        }
    }

    void display()
    {
        cout << "US Currency: $" << dollar << "." << cents << endl;
    }
};

class NepCurrency
{
    int rupees, paisa;

public:
    NepCurrency(int rp = 0, int ps = 0)
    {
        rupees = rp;
        paisa = ps;

        if (rupees < 0 || paisa < 0)
        {
            cout << "currency cannot be negative";
            exit(1);
        }

        if (paisa >= 100)
        {
            rupees += paisa / 100;
            paisa %= 100;
        }
    }

    void input()
    {
        cout << "Enter Rupees: ";
        cin >> rupees;
        cout << "Enter Paisa: ";
        cin >> paisa;

        if (rupees < 0 || paisa < 0)
        {
            cout << "currency cannot be negative";
            exit(1);
        }

        if (paisa >= 100)
        {
            rupees += paisa / 100;
            paisa %= 100;
        }
    }

    operator USCurrency()
    {
        int dollar = rupees / USD_TO_NPR;
        int tempPaisa = paisa;
        tempPaisa += (rupees - USD_TO_NPR * dollar) * 100;
        int cents = tempPaisa / USD_TO_NPR;
        return USCurrency(dollar, cents);
    }

    void display()
    {
        cout << "Nepalese Currency: Rs." << rupees << "." << paisa << endl;
    }
};

int main()
{
    NepCurrency n1;
    n1.input();
    USCurrency u1 = n1;
    n1.display();
    u1.display();
    return 0;
}
