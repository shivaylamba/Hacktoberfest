#include <iostream>
using namespace std;

int main()
{
    int a[100];
    int size, i, j;
    
    // Prompt the user to enter the size of the array.
    cout << "Enter the Size of Array: ";
    cin >> size;
    
    cout << "\nEnter the Elements of Array one by one";
    
    // Loop to input elements into the array.
    for (i = 0; i < size; i++)
    {
        cout << "\nEnter Element at " << i + 1 << " position: ";
        cin >> a[i];
    }

    int item;
    // Prompt the user to enter the item to search for.
    cout << "\nEnter the Item which you want to search: ";
    cin >> item;

    int first = 0;
    int last = size - 1;
    int middle = (first + last) / 2;

    // Binary search algorithm
    while (first <= last)
    {
        if (a[middle] < item)
        {
            first = middle + 1;
        }
        else if (a[middle] == item)
        {
            cout << item << " found in the array at position " << middle + 1 << "\n";
            break;
        }
        else
        {
            last = middle - 1;
        }
        middle = (first + last) / 2;
    }

    // If the item is not found in the array
    if (first > last)
    {
        cout << item << " not found in the array";
    }

    return 0;
}
