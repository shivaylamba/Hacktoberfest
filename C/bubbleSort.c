#include<stdio.h>
void printarray(int *a ,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("\n");
}
void bubblesort(int *a,int n){
	int t,i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
}
int main()
{
	int n=5;
	int a[5],i;
	printf("enter the elements of array:");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	printarray(a,n);
	bubblesort(a,n);
	printarray(a,n);
	return 0;
}
	  
