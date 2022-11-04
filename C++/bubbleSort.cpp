#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void bubble(int arr[], int size)
{
    int flag = 0; // TO make sort adaptive
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag++;
            }
        }
        if (flag == 0)
        {

            break;
        }
    }
}
int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    int arr[size];
    cout << "Enter array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    bubble(arr, size);
    cout << "Sorted array is: ";
    for (int x = 0; x < size; x++)
    {
        cout << arr[x] << " ";
    }
}