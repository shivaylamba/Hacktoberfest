#include <iostream>
using namespace std;
class Base
{
    int data1; // private by default and is not inheritable
public:
    int data2;
    void setdata();
    int getadata1();
    int getadata2();
};
void Base ::setdata()
{
    data1 = 10;
    data2 = 20;
}
int Base ::getadata1()
{
    return data1;
}
int Base ::getadata2()
{
    return data2;
}
class Derived : public Base
{
    int data3;

public:
    void process();
    void display();
};
void Derived ::process()
{
    data3 = data2 * getadata1();
}
void Derived::display()
{
    cout << "vallue of data 1 is " << getadata1() << endl;
    cout << "vallue of data 2 is " << data2 << endl;
    cout << "vallue of data 3 is " << data3 << endl;
}
int main()
{
    Derived der;
    der.setdata();
    der.process();
    der.display();
    return 0;
}
