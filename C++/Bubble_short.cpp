#include <stdlib.h>
#include <iostream>
using namespace std;
void bubbleshort(int *arr, int size)
{
    int temp;
    int isshorted = 0;
    for (int i = 0; i < size - 1; i++)
    {

        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int size;
    cout << "enter size of array : ";
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "shorted array\n ";
    bubbleshort(arr, size);

    return 0;
}