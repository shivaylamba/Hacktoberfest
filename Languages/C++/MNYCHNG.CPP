#include <iostream>

using namespace std;

int money_change(int m){
    int note_10 = m/10;
    int rem1 = m%10;
    int note_5 = rem1/5;
    int rem2 = m%5;
    int note_1 = rem2/1;
    return note_10+note_5+note_1;
}

int main()
{
    int m;
    cin>>m;
    cout<<money_change(m);

    return 0;
}
