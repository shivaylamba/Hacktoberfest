// Bubble Sort in "increasing order" in c++
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "How Many number You Want To Enter:";
    cin >> n;
    int arr[n];
    cout << "enter the no:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Your Entered Number is:-";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    // sorting the array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            if (arr[j] > arr[j + 1]) // swap the number
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\n\nthe sorted array is :-"; // printing the sorted array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
