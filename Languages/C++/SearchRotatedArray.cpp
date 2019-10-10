//Array is sorted and rotated. Find a particular element.
#include<iostream>
using namespace std;

int searchIn(int a[],int s,int e,int key)
{
    //Base case
    if(s>e){
    //if element noy found -1 is returned
        return -1;
    }
    //Rec case
    int mid=(s+e)/2;

    if(a[mid]==key){
        return mid;
    }
    //mid lies in the left part
    if(a[s]<=a[mid]){
            if(key>=a[s]&&key<=a[mid]){
            return searchIn(a,s,mid-1,key);
            }
            else{
            return searchIn(a,mid+1,e,key);
            }
    }
    //mid lies in right part
    if(key>=a[mid]&&key<=a[e]){
        return searchIn(a,mid+1,e,key);
    }
    return searchIn(a,s,mid-1,key);
}
int main()
{
    //Enter a sorted and rotated array
    int a[]={9,10,11,5,6,7,8};
    int key;
    cout<<"Enter the element to be searched for : ";
    cin>>key;
    cout<<"Element found at index "<<searchIn(a,0,6,key);
    return 0;
}
