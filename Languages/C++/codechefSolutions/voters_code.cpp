#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n1,n2,n3,i,c=0,k=0;
	cin>>n1>>n2>>n3;
	int a1[n1+n2+n3],a2[n1+n2+n3];
	for(i=0;i<n1+n2+n3;i++)
	{
	    cin>>a1[i];
	}
	sort(a1,a1+n1+n2+n3);
	for(i=0;i<n1+n2+n3;i++)
	{
	  if(a1[i]==a1[i+1] && a2[k-1]!=a1[i])
	  {
	      c++;
	      a2[k++]=a1[i];
	  }
	}
	cout<<c<<endl;
	for(i=0;i<k;i++)
	{
	    cout<<a2[i]<<endl;
	}


	return 0;
}
