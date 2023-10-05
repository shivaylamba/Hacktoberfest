#include <iostream>
using namespace std;

int partition(int arr[] , int start ,int end){

    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1 ; i <= end; i++)
    {
        if (arr[i] < pivot)
        {
            count++;
        }   
    }

    int pivotIndex = start + count ;

    swap(arr[start] , arr[pivotIndex]);
    int i = start ;  int j = end ;

    while ( i < pivotIndex && j > pivotIndex )
    {        
        while ( arr[i] < pivot ) { i++ ; } ;        //If pivot > arr[i] then i++  
        
        while ( arr[j] > pivot ) { j-- ; } ;       //If pivot < arr[j] then j--  
        
        if ( i < pivotIndex && j > pivotIndex )
        {
            swap( arr[i] , arr[j] ) ;
            i++ ;  j-- ;
        }   
    }
}

void quickSort(int arr[] , int start , int end){

    if ( start >= end)
    {
       return ;
    }
    
    int p = partition(arr,start,end) ;

    // left vale k leye sort kar
    quickSort(arr,start,p - 1);

    // right vale k leye sort kar
    quickSort(arr,p+1,end);
}

int main(){
    int arr[7] = {8,7,6,1,0,9,2};
    int start = 0 ;
    int end = 7 ;

    quickSort(arr,start,end -1);

    for (int i = 0; i < end; i++)
    {
        cout << arr[i] << " " ;
    }
    


    return 0;
}