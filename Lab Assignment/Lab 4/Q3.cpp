// Modify Q.2 to add base class sales that holds an array of three floats so that it can record the rupees sales of a particular publication for the last three months. Include getdata() function to get three Sales amount from the user and a putdata() function to display sales figures. Alter the book and tape classes so they are derived from both publication and sales. An object of class book or tape should input and output sales data along with its other data.

#include <iostream>
using namespace std;

class Publication
{
    string title;
    float price;

public:
    void getdata()
    {
        cout << "Enter title and price: ";
        cin >> title >> price;
    }

    void putdata()
    {
        cout << "Title: " << title << endl;
        cout << "Price: Rs." << price << endl;
    }
};

class Sales
{
    float sales[3];

public:
    void getdata()
    {
        cout << "Enter sales for last 3 months: ";
        for (int i = 0; i < 3; i++)
        {
            cin >> sales[i];
        }
    }

    void putdata()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += sales[i];
        }
        cout << "Sales for last 3 months: Rs." << sum << endl;
    }
};

class Book : public Publication, public Sales
{
    int pageCount;

public:
    void getdata()
    {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
        Sales::getdata();
    }

    void putdata()
    {
        Publication::putdata();
        cout << "Page Count: " << pageCount << " pages" << endl;
        Sales::putdata();
    }
};

class Tape : public Publication, public Sales
{
    float playingTime;

public:
    void getdata()
    {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        Sales::getdata();
    }

    void putdata()
    {
        Publication::putdata();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
        Sales::putdata();
    }
};

int main()
{
    Book b;
    Tape t;

    b.getdata();
    t.getdata();

    b.putdata();
    t.putdata();

    return 0;
}
