#include <iostream>
using namespace std;

class Shop
{
    int id;
    float price;

public:
    void setdata(int a, float b)
    {
        id = a;
        price = b;
    }
    void getdata()
    {
        cout << "Code of this item is" << id << endl;
        cout << "price of this item is" << price << endl;
    }
};

// 1   2   3
// ^
// |
// |
// ptr
// ptrtemp
int main()
{
    int size = 3;
    // int *ptr=&size;
    // int *ptr=new int [30];
    Shop *ptr = new Shop[size];
    Shop *ptrItem = ptr;

    int p;
    float q;
    for (int i = 0; i < size; i++)
    {
        cout << "ID and price of item " << i + 1;
        cin >> p >> q;
        // (*ptr).setdata(p,q);
        ptr->setdata(p, q);
        ptr++;
    }
    for (int i = 0; i < size; i++)
    {
        cout << "Item number:" << i + 1 << endl;
        ptrItem->getdata();
        ptrItem++;
    }
    return 0;
}
