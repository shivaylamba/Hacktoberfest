#include <bits/stdc++.h>
using namespace std ;

int main ()
{
	const int size =20; int l=0;
	cout<<"SPARSE MATRIX"<<endl;
	int A[size][size],B[3][size], R , C,Z,nz;
	cout<<"Enter the no. Rows in  the matrix";
	cin>> R;
	cout<<"Enter the no. columns in  the matrix";
	cin>> C;
	for(int i=0 ;i<R;i++)
	for(int j=0 ;j<C;j++)
	{
		cout<<"Enter Element A["<<i+1<<"]["<<j+1<<"]";
		cin>>A[i][j];
		if(A[i][j]==0) Z++;
		else nz++;
	}
	if(Z>((R*C)/2))
	{    
		for(int i=0;i<R;i++)
		for(int j=0;j<C;j++)
		if(A[i][j]!=0)
		  {
		  	B[0][l]= i;
		  	B[1][l]= j;
		  	B[2][l]= A[i][j];
			l++;
		  }
	}
	   for(int i=0;i<3;i++)
	   {
	    for(int j=0;j<l;j++)
	     cout<<B[i][j]<<"   ";
	     cout<<endl;
	   }
	
	return 0;
}
