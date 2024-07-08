// To write a C++ program to overload all relational operators to compare
// US currency with Nepalese currency. Use conversion rate $1=NRs
// 101.36(Note: make two classes to represent each currency)

#include <iostream>
using namespace std;
#define USD_RATE 101.36

class NRP
{
    float amount;

public:
    NRP(float amt = 0) { amount = amt; }

    void inputAmount()
    {
        cout << "Enter nrp amount: " << endl;
        cin >> amount;
    }

    float getAmount() { return amount; }
};

class USD
{
    float amount;

public:
    USD(float amt = 0) { amount = amt; }

    void inputAmount()
    {
        cout << "Enter usd amount: " << endl;
        cin >> amount;
    }

    int operator==(NRP n1)
    {
        // cout << (n1.getAmount() == (amount * USD_RATE));
        if (n1.getAmount() == amount * USD_RATE)
            return 1;
        else
            return 0;
    }

    int operator>(NRP n1)
    {
        if (amount * USD_RATE > n1.getAmount())
            return 1;
        else
            return 0;
    }

    int operator>=(NRP n1)
    {
        if (amount * USD_RATE >= n1.getAmount())
            return 1;
        else
            return 0;
    }

    int operator<(NRP n1)
    {
        if (amount * USD_RATE < n1.getAmount())
            return 1;
        else
            return 0;
    }

    int operator<=(NRP n1)
    {
        if (amount * USD_RATE <= n1.getAmount())
            return 1;
        else
            return 0;
    }

    int operator!=(NRP n1)
    {
        if (amount * USD_RATE != n1.getAmount())
            return 1;
        else
            return 0;
    }
};

int main()
{
    NRP n1(101.36);
    USD u1(0.5);

    if (u1 >= n1)
        cout << "USD is greater than npr";
    else
        cout << "npr is greaer than usd";
    

    return 0;
}
