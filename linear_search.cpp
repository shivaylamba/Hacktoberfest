#include<bits/stdc++.h>
using namespace std;

/**
 * Algorithm implementation
 * \param [in] array array to search in
 * \param [in] size length of array
 * \param [in] key key value to search for
 * \returns index where the key-value occurs in the array
 * \returns -1 if key-value not found
 */
int main()
{
    vector <int> v;
    int key,size;
    int flag = 0;

    // Input array
    cout<<"Enter number of elements\n";
    cin>>size;
    cout << "\nEnter elements of the Array to be searched which is to be searched";
    for (int i = 0; i < size; i++)
    {
        cin >> key;
        v.push_back(key);
    }

    cout << "\nEnter the number to be searched : ";
    cin >> key;
    
    for(int i = 0;i<v.size();i++)
    {
        if(v[i] == key)
        {
            flag = 1;
            cout<<"Found at position: "<<i + 1<<"\n";
            break;
        }
    }
    
    if (flag == 0)
        cout << "Number not found\n";
    return 0;
}
