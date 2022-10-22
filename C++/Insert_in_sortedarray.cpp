#include <iostream>
using namespace std;

int main()
{
    int i, n, index, data, a[100];
    cout << "Enter the limit of array" << endl;
    cin >> n;
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the data to be insert" << endl;
    cin >> data;
    i=n-1;
    while (data<a[i]&&i>=0)
    {
        a[i]=a[i-1];
        i--;
    }
a[i+1]=data;
for (int i = 0; i <n; i++)
{
    cout<<a[i]<<" ";
}
return 0;
}