#include<bits/stdc++.h>

using namespace std;

int Merge(int arr[], int aux[], int low, int mid, int high)
{
    int i = low, j = mid + 1;
    int k = low;
    int inversionCount = 0;

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            aux[k++] = arr[i++];
        }
        else{
            aux[k++] = arr[j++];
            inversionCount += (mid - i + 1);
        }
    }

    while(i <= mid)
    {
        aux[k++] = arr[i++];
    }

    for(int i = low;i <= high;i++)
    {
        arr[i] = aux[i];
    }

    return inversionCount;
}

int mergeSort(int arr[], int aux[], int low, int high)
{
    if(low == high)
        return 0;

    int mid = (low + high) / 2;
    int inversionCount = 0;

    inversionCount += mergeSort(arr, aux, low, mid);
    inversionCount += mergeSort(arr, aux, mid + 1, high);
    inversionCount += Merge(arr, aux, low, mid, high);

    return inversionCount;
}

int main()
{
    int len;
    cout<<"Enter the size of array: ";
    cin>>len;

    int arr[len];
    int aux[len];

    cout<<"Enter elements of array: "<<endl;
    for(int i = 0;i < len;i++)
    {
        cin>>arr[i];
        aux[i] = arr[i];
    }

    int inversion_count = mergeSort(arr, aux, 0, len - 1);
    cout<<"Inversion Count is: "<<inversion_count<<endl;

    return 0;
}
