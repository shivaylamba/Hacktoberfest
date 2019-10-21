#include<stdio.h>
void main()
{
	int i,j,m,n,l,k;
	int a[5][5],b[5][5],c[5][5];
	printf("enter the no of rows and columns in first array");
	scanf("%d%d",&m,&n);
	printf("enter number of columns in second row");
	scanf("%d",&l);
	printf("enter the first array");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter the second array");
	for(i=0;i<n;i++)
	{
		for(j=0;j<l;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for (i=0;i<m;i++)
	{
	j=0;
		for(j=0;j<l;j++)
		{
			c[i][j]=0;
			for(k=0;k<l;k++)
			{
				c[i][j]=c[i][j]+a[i][k]*b[k][j];
			}
		}
	}
	printf("the product of the matrix is");
	for(i=0;i<m;i++)
	{
		printf("\n");
		for(j=0;j<l;j++)
		{
			printf("\t%d",c[i][j]);
		}
	}
}
