#include<iostream>
using names space std;
int main()
{
  int arr[10]={1,2,3,4,5,6,7,8,9,10};
  int a;//number to be searched in the array
  cin>>a;
  bool x=false;//true if number is found in the array
  for(int i=0;i<10;i++)
  {
    if(arr[i]==a)
    {
      cout<<"FOUND " +a+"at index ="+i<<endl;
      x=true;
    }
  }
  if(x==false)
    cout<<"NUMBER NOT FOUND"<<endl;
  return 0;
}
