//    1
//   232
//  34543
// 4567654
#include <iostream>
using namespace std;

int main()
{

    int n, i = 1;
    cout << "Enter n:";
    cin >> n;
    while (i <= n)
    {
        int spaces = 1;
        while (spaces <= n - i)
        {
            cout << ' ';
            spaces = spaces + 1;
        }
        int j = 1;
        while (j <= i)
        {
            cout << i + j - 1;
            j = j + 1;
        }
        int p = i - 1;
        while (p >= 1)
        {
            cout << i + p - 1;
            p = p - 1;
        }
        cout << endl;
        i = i + 1;
    }
    return 0;
}
