#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int i = 1;
    int el;
    vector<int> v;
    do
    {
        cin >> el;
        v.push_back(el);
        cout << "Enter more (0/1): ";
        cin >> i;
    } while (i!=0);
    cout << "\nEnter element to be searched : ";
    cin >> el;
    for(int j = 0 ; j < v.size() ; j++)
    {
        if(v[j]==el)
        {
            cout << "Element found at index " << j;
            break;
        }
    }
    return 0;
}