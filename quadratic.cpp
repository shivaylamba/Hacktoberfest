#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter the coefficient of x^2: ";
    cin >> a;
    cout << "Enter the coefficient of x: ";
    cin >> b;
    cout << "Enter the constant: ";
    cin >> c;

    float dis = (b * b - 4 * a * c);
    float root1 = 0, root2 = 0;

    if (dis < 0)
    {
        cout << "No roots exist";
    }
    else
    {
        root1 = (-b + sqrt(dis)) / (2.0 * a);
        root2 = (-b - sqrt(dis)) / (2.0 * a);

        cout << "First root is " << root1 << endl;
        cout << "Second root is " << root2 << endl;
    }
    return 0;
}
