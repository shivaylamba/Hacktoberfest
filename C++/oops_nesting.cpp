#include <iostream>
#include <string>
using namespace std;
class binary
{

    string st;

public:
    void input(void);
    void check(void);
    void reverse(void);
};

void binary ::input(void)
{
    cout << "Enter a number " << endl;
    cin >> st;
}
void binary ::check(void)
{
    for (int i = 0; i < st.length(); i++)
    {
        if ((st.at(i) != '1') && (st.at(i) != '0'))
        {

            cout << "It is not a binary number ";
            exit(0);
        }
    }
}
void binary ::reverse(void)
{
    cout << "Ones complement is " << endl; 
    for (int i = 0; i < st.length(); i++)
    {
        if (st.at(i) == '1')
        {
            cout << "0";
        }
        else if (st.at(i) == '0')
        {
            cout << "1";
        }
    }
}

int main()
{
    binary checker;
    checker.input();
    checker.check();
    checker.reverse();

    return 0;
}
