#include<stdio.h>
#include<string.h>
void encrypt(char[],char[]);
void main()
{
	char ky[50],pt[100],key[50];
	char m[5][5];
	char mat[25];
	char ch='a';
	int i=0,j=0,a=0,b=0,temp1=0;
	int l,temp=0,flag;
	printf("\nEnter key:");
	gets(ky);
	printf("\nEnter plain text:");
	gets(pt);

	//Initialized matrix with 0
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			m[i][j]=0;
		}
	}

	//Removing space from key
	temp=0;
	while(ky[temp]!='\0')
	{
		if(ky[temp]==' ')
		{
			l=strlen(ky);
			temp1=temp;
			while(ky[temp1]!='\0')
			{
				ky[temp1]=ky[temp1+1];
				temp1++;
			}
			l--;
		}
		temp++;
	}

	//Removing equal elements from key and storing new key in key[]
	temp=0;
	temp1=0;
	while(ky[temp]!='\0')
	{
		flag=0;
		for(a=0;a<=temp;a++)
		{
			if(key[a]==ky[temp])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			key[temp1]=ky[temp];
			temp1++;
		}
		temp++;
	}
	key[temp1]='\0';

	//Making i and j element as equal
	temp=0;
	while(key[temp]!='\0')
	{
		if(key[temp]=='i' || key[temp]=='j')
		{
			for(a=0;a<temp;a++)
			{
				if(key[a]=='i' || key[a]=='j')
				{
					temp1=temp;
					while(key[temp1]!='\0')
					{
						key[temp1]=key[temp1+1];
						temp1++;
					}
					key[temp1-1]='\0';
				}
			}
		}
		temp++;
	}

	//Storing key in matrix
	temp=0;
	a=0;
	b=0;
	while(key[temp]!='\0')
	{
		if(b==5)
		{
			b=0;
			a++;
		}
		m[a][b]=key[temp];
		temp++;
		b++;
	}

	//Storing elements in matrix except key elements
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			temp=0;
			flag=0;
			while(key[temp]!='\0')
			{
				if(key[temp]==ch)
				{
					ch++;
					flag=1;
					break;
				}
				if(ch=='i' || ch=='j')
				{
					for(a=0;a<temp;a++)
					{
						if(key[temp]=='i' || key[temp]=='j')
						{
							ch++;
							flag=1;
							break;
						}
					}
				}
				temp++;
			}
			if(flag==0 && m[i][j]==0)
			{
				m[i][j]=ch;
				ch++;
				if(ch=='i')
					ch++;
			}
			if(m[i][j]==0)
				j--;
		}
	}

	//Display matrix
	printf("\n\nMatrix\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("  %c",m[i][j]);
		}
		printf("\n");
	}

	//Creating new char one dimentional array to pass in function
	i=0;
	j=0;
	for(temp=0;temp<25;temp++)
	{
		if(j==5)
		{
			i++;
			j=0;
		}
		mat[temp]=m[i][j];
		j++;
	}

	//Passing new array's two characters in function
	l=strlen(pt);
	ky[2]='\0';
	temp=0;
	printf("\nEncrypted text:");
	while(pt[temp]!='\0')
	{
		i=0;
		while(i!=2)
		{
			if(pt[temp]==pt[temp+1] && i==0)
			{
				l=strlen(pt);
				temp1=l;
				while(temp1!=temp+1)
				{
					pt[temp1]=pt[temp1-1];
					temp1--;
				}
				pt[temp1]='x';
				pt[l+1]='\0';
				l++;
			}
			if(pt[temp]==' ')
			{
				l=strlen(pt);
				temp1=temp;
				while(pt[temp1]!='\0')
				{
					pt[temp1]=pt[temp1+1];
					temp1++;
				}
				l--;
				pt[l]='\0';
			}
			ky[i]=pt[temp];
			i++;
			temp++;
			if(strlen(pt)%2!=0 && temp-strlen(pt)<=2)
			{
				l=strlen(pt);
				pt[l]='x';
				l++;
				pt[l]='\0';
			}
		}
		encrypt(ky,m);

	}

}
void encrypt(char pt[],char mat[])
{
	int i,j;
	char ct[3];
	int r[2],c[2];
	int temp=0;
	char key[5][5];
	ct[2]='\0';
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			key[i][j]=mat[temp];
			temp++;
		}
	}
	temp=0;
	cp:
	if(temp!=2)
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(pt[temp]=='i' || pt[temp]=='j')
				{
					if(key[i][j]=='i' || key[i][j]=='j')
					{
						r[temp]=i;
						c[temp]=j;
						temp++;
						goto cp;				
					}
				}
				else
				{
					if(pt[temp]==key[i][j])
					{
						r[temp]=i;
						c[temp]=j;
						temp++;
						goto cp;
					}
				}
			}
		}
	}
	else
	{
		if(r[0]==r[1])
		{
			ct[0]=key[r[0]][(c[0]+1)%5]-32;
			ct[1]=key[r[1]][(c[1]+1)%5]-32;
		}
		else if(c[0]==c[1])
		{
			ct[0]=key[(r[0]+1)%5][c[0]]-32;
			ct[1]=key[(r[1]+1)%5][c[1]]-32;
		}
		else
		{
			ct[0]=key[r[0]][c[1]]-32;
			ct[1]=key[r[1]][c[0]]-32;			
		}
		printf("%s ",ct);
	}
}


