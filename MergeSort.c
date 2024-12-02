#include <iostream>
using namespace std;


void merge(int *arr,int s,int e){
    int len1= mid-s+1;
    int len2= e-mid;

    int *first=new int(len1);
    int *second=new int(len2);

//copy values into new array
    int mainArrayIndex=s;
    for (int i = 0; i < len1; i++)
    {
        first[i]=arr[k++];
    }

    int mainArrayIndex = mid+1;
    for (int i = 0; i < len2; i++)
    {
        second[i]=arr[k++];

    }
    //merge both the sorted arrays into final array
    int index1=0;
    int index2=0;
     mainArrayIndex=0;

    while(index1 < len1 && index2 < len2){
        if(first(index1) < second(index2)){
            arr[mainArrayIndex++]=frist[index1++];
        }
        else
        {
            arr[mainArrayIndex++]=second[index2++];

        }
        
    }
    //adding the remaining elements of the first array into the final output array

    while (index1 < len1){
        arr[mainArrayIndex++]=first[index1++];

    }
   //adding the remaining elements of the second array into the final output array
   
    while (index2<len2)
    {
        arr[mainArrayIndex++]= second[index2++];
    }
    
    

}

void mergeSort(int *arr,int s,int e){
    //base case
    if(s>e)
    return ;
    int mid=(s+e)/2;


    //sort left part
    mergeSort(arr,s,mid);

    //right part sorting
    mergeSort(arr,mid+1,e);

    //merge the two sub-divided arrays
    merge(arr,s,e);
    

}

int main(int argc, char const *argv[])
{
    int arr[5]={1,24,2,35,23};
    int n=5;

    mergeSort(arr,0,n-1);
    return 0;
}
