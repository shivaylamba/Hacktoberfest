#include<iostream>
using namespace std;
  merge(int arr[],int left,int mid,int right )
  {
      int n1 = mid-left+1;
      int n2=right-mid;
      int new1[n1];
      int new2[n2];
      for(int i=0;i<n1;i++)
      {
          new1[i]=arr[left+i];
      }
      for(int j=0;j<n2;j++)
      {
          new2[j]=arr[mid+1+j];
      }
      int i=0;
      int j=0;
      int k=left;
      while(i<n1 && j<n2)
      {
          if(new1[i]<=new2[i])
          {
              arr[k]=new1[i];
              i++;
              k++;
          }
          else{
            arr[k]=new2[j];
            k++;
            j++;
          }
      }
      while(i<n1)
      {
          arr[k]=new1[i];
          i++;
          k++;

      }
      while(j<n2)
      {
          arr[k]=new2[j];
          j++;
          k++;
      }
  }
mergesort(int arr[],int left,int right)
{   if(left<right)
    {
        int mid;
        mid = (int)(left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }


}


int main()
{
  cout<<"Enter the length of the array"<<endl;
  int length;
  cin>>length;
  int arr[length];
  cout<<"Enter the element of the array"<<endl;
  for(int i=0;i<length;i++)
  {
      cin>>arr[i];
  }
  cout<<"Entered array is :"<<endl;
  for(int i=0;i<length;i++)
  {
      cout<<arr[i]<<"\t";
  }
  cout<<endl;
  mergesort(arr,0,length-1);
  cout<<"Sorted array is :"<<endl;
  for(int i=0;i<length;i++)
  {
      cout<<arr[i]<<"\t";
  }
}
