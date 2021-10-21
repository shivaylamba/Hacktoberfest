#include<iostream>
using namespace std;
int main()
{
    int n;  
    cin >> n; // taking input of the length of array


    int arr[n], i;
    cout<<"Enter "<<n<<" Array Elements: ";
    for(i=0; i<n; i++)
        cin>>arr[i]; // the original array elements
    cout<<"\nThe Original Array is:\n";


    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";  // print the original array elements
        

    cout<<"\n\nThe Reverse of Given Array is:\n";
    for(i=(n-1); i>=0; i--) //iterate backwards
        cout<<arr[i]<<" ";  // the reverse of the original array elements
    cout<<endl;
    return 0;
}