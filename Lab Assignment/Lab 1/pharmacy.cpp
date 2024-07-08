#include <iostream>
using namespace std;

int main()
{
    int storeQuantity, orderQuantity;

    cout << "Enter Store Quantity: ";
    cin >> storeQuantity;
    cout << "Enter order Quantity: ";
    cin >> orderQuantity;

    if (orderQuantity > storeQuantity)
        cout << "No enough quantity";
    else if (orderQuantity < storeQuantity)
        if (orderQuantity > 16 && storeQuantity <= 40)
            cout << "You cannot order more than 16 item";
        else
            cout << "Your order is accepted ";

    return 0;
}