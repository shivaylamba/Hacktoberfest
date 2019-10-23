#include<stdio.h>

int main()
{
	int a[10],n,x,b[10],i;

	printf("\nEnter number of elements in your array: ");
	scanf("%d", &n);

	printf("\nStart entering your array\n");
	
	for(i=0;i<n;i++)
	{

		printf("Enter element %d: ", i+1);
		scanf("%d", &a[i]);
	}
	
	printf("\nEnter the element to be deleted: "); 
	scanf("%d", &x);

	int k=0;

	for(i=0;i<n;i++)
	{
		if(a[i]!=x)
		{
			b[k++]=a[i];
		}
	}

	printf("New Array: \n");
	
	for(i=0;i<n-1;i++)
	{
		printf("%d  ", b[i]);
	}
}
