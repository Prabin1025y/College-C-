// 2.Create a class publication that stores the title and price of a publication. From this class derive two classes:book, which adds a page count and tape, which adds a playing time in minutes. Each of these three classes should have getdata() function to get its data from the user at the keyboard and putdata() function to display its data.

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

class Book : public Publication
{
    int pageCount;

    public:
    void getdata()
    {
        Publication::getdata();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void putdata()
    {
        Publication::putdata();
        cout << "Page Count: " << pageCount <<" pages"<< endl;
    }
};

class Tape : public Publication
{
    float playingTime;

    public:
    void getdata()
    {
        Publication::getdata();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
    }

    void putdata()
    {
        Publication::putdata();
        cout << "Playing Time: " << playingTime <<" minutes"<< endl;
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