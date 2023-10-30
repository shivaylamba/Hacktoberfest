#include <iostream>
using namespace std;
void toh(int n, char s, char h, char d)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " from rod " << s << " to rod " << d << endl;
        return;
    }
    toh(n - 1, s, d, h);
    cout << "Move disk " << n << " from rod " << s << " to rod " << d << endl;
    toh(n - 1, h, s, d);
}

int main()
{
    cout << "enter number of disks = " << endl;
    int n;
    cin >> n;
    toh(n, 'A', 'B', 'C');
    return 0;
}
