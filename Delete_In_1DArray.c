#include<stdio.h>

int main()
{
	int a[10],n,x,b[10],i,nd,d[10];

	printf("\nEnter number of elements in your array: ");
	scanf("%d", &n);

	printf("\nStart entering your array\n");
	
	for(i=0;i<n;i++)
	{

		printf("Enter element %d: ", i+1);
		scanf("%d", &a[i]);
	}
	
	printf("\nEnter the no.elements to be deleted: "); 
	scanf("%d", &nd);

	if(nd>n){
	printf("Not possible!")
	}

	else{
		printf("\nEnter the elements to be deleted\n"); 
		
		for(i=0;i<nd;i++)
	{

		printf("Enter element %d: ", i+1);
		scanf("%d", &d[i]);
	}
		int k=0;

	for(i=0;i<n;i++)
	{
	for(int j=0;j<nd;j++){
		if(a[i]!=d[j])
		{
			b[k++]=a[i];
		}
	}
	}

	printf("New Array: \n");
	
	for(i=0;i<n-1;i++)
	{
		printf("%d  ", b[i]);
	}
	}
}
