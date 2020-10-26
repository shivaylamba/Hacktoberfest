#include <iostream> 
using namespace std; 

int main() 
{ 
	int a[100];
    int size, i, j;
    cout<<"Enter the Size of Array: ";
    cin>>size;
    cout<<"\nEnter the Elements of Array one by one";
    for(i=0; i<size; i++)
    {
        cout<<"\nEnter Element as "<<i+1<<" position: ";
        cin>>a[i];
    }

    int item;
    cout<<"\nEnter the Item which you want to search: ";
    cin>>item;

    int first = 0;
	int last = size-1;
	int middle = (first+last)/2;
	while (first <= last)
	{
	   if(a[middle] < item)
	   {
		first = middle + 1;

	   }
	   else if(a[middle] == item)
	   {
		cout<<item<<" found in the array at the location "<<middle+1<<"\n"; 
                break; 
           } 
           else { 
                last = middle - 1; 
           } 
           middle = (first + last)/2; 
        } 
        if(first > last)
	{
	   cout<<item<<" not found in the array";
	}

	 
	return 0; 
} 
