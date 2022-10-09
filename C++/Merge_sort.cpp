#include<iostream>
using namespace std;

void mergeSort(int[],int,int); 
void merge(int[],int,int,int);

void printArray(int arr[], int size){
    int i;
    for(i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{
    int array[]= {8, 4, 5, 1, 3, 9, 0, 2, 7, 6};
    int i; 

    int size = sizeof(array)/sizeof(array[0]);
    printArray(array, size);

    mergeSort(array, 0, size-1); 
    printArray(array, size);
}

void mergeSort(int a[], int left, int right)
{
    int mid;
    if(left < right)
    {
        
        mid = (left + right)/2;
        
        // recursive calls to sort first half and second half subarrays
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
   
    int L[n1], R[n2];
     
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
        
    i = 0; // Starting index of L[i]
    j = 0; // Starting index of R[i]
    k = left; // Starting index of merged subarray
    
    while (i < n1 && j < n2) 
    {
    if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
