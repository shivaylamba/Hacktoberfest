#include <iostream>
#include <math.h>
using namespace std;
int heapSize;

void buildMaxHeap(int[],int);

void maxHeapify(int ptr[], int i, int s)
{
    int l = 2*i + 1;
	int r = 2*i + 2;
    int largest = i;
    if((ptr[l]>ptr[largest]) && l<s)
        largest = l;

    if((ptr[r]>ptr[largest]) && r<s)
        largest = r;

    if(largest != i)
    {
        swap(ptr[i], ptr[largest]);
        maxHeapify(ptr, largest, s);
    }
}

void buildMaxHeap(int ptr[], int s)
{
    for(int i=(s/2)-1; i>=0; i--)
        maxHeapify(ptr, i, s);

    for (int i=s-1; i>=0; i--)
	{
		swap(ptr[0], ptr[i]);
		maxHeapify(ptr, 0, i);
	}
}

void heapSort(int ptr[], int s)
{
    buildMaxHeap(ptr, s);
}

int main()
{
    int * ptr, n;
    cout << "Enter the size of the Array: ";
    cin >> n;
    ptr = new int[n];
    if(ptr == NULL)
    {
        cout << "Insufficient Memory.";
    }
    cout<< "Enter the elements:\n";
    for(int i=0; i<n; i++)
    {
        cout<<"["<<i<<"]:";
        cin >> ptr[i];
    }
    heapSort(ptr, n);
    cout << "\nSorted Array: \n";
    for(int i=0; i<n; i++)
    {
        cout << ptr[i] << " ";
    }
    return 0;
}
