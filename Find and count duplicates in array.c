#include <stdio.h>
#include <stdlib.h>

void findncount(int A[],int n)
{
	int lastDuplicate = 0,i,j;
	for(i=0;i<n;i++)
	{
		if(A[i]==A[i+1]&&A[i]!=lastDuplicate)
		{
			printf("%d\n",A[i]);
			lastDuplicate = A[i];
		}
	}
	for(i=0;i<n-1;i++)
	{
		if(A[i]==A[i+1])
		{
			j=i+1;
			while(A[j]==A[i])j++;

			printf("\n%d is appearing %d times",A[i],j-i);
			i=j-1;
		}
	}
}
int main()
{
	int A[] ={3,6,8,8,10,12,15,15,15,20},n;
	n=sizeof(A)/sizeof(A[0]);
	findncount(A,n);
	return 0;
}
