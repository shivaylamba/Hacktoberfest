#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int start, int end)
{
    int x = a[start], i = start, k = start + 1, temp;
    for (; k <= end; k++)
    {
        if (a[k] <x)   // change sign here for ascending/descending(it will sort in ascending order by default)
        {
            i++;
            temp = a[i];
            a[i] = a[k];
            a[k] = temp;
        }
    }
    a[start] = a[i];
    a[i] = x;
    return i;
}
void quick_sort(int a[], int start, int end)
{
    if (start >= end)
        return;
    int i = partition(a, start, end);

    quick_sort(a, start, i);
    quick_sort(a, i + 1, end);
}
int main()
{
    int a[] = {4, 1, 3, 9, 7};
    int size = sizeof(a) / sizeof(a[0]);
    quick_sort(a, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
       cout<<a[i]<<" ";
    }

    return 0;
}