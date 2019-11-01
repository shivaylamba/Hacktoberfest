#include<iostream>
using namespace std;
struct student
{
	unsigned int roll;
	char name[20];
	char addr[20];
}s[100],temp;

void getData(int n)
{
	int i;
	cout<<"\nEnter the records:\n";

		for(i=0;i<n;i++)
		{
			cin>>s[i].roll>>s[i].name>>s[i].addr;
		}
}
void displayData(int n)
{
    int i;
    cout<<"\nRollNo\tName\tAddress\n";
    cout<<"--------------------------------------------------";
    for(i=0;i<n;i++)
	{
		cout<<"\n"<<s[i].roll<<"\t"<<s[i].name<<"\t"<<s[i].addr<<"\n";
	}
	cout<<"--------------------------------------------------";
}
/*INSERT AT THE END
void insertRecord(int n)
{
    //n=n+1 before calling
	cout<<"\nEnter Roll no:\t";
	cin>>s[n-1].roll;
	cout<<"\nEnter the Name:\t";
	cin>>s[n-1].name;
	cout<<"\nEnter the Address:\t";
	cin>>s[n-1].addr;
}*/
int insertRecord(int n)
{
    int i,pos;
    cout<<"\nEnter the position of record";
    cin>>pos;//2
    for(i=n-1;i>=pos-1;i--)//(1,1,--)
    {
        s[i+1]=s[i];
    }
    cout<<"\nRoll no:\t";
    cin>>s[pos-1].roll;
    cout<<"\nName:\t";
    cin>>s[pos-1].name;
    cout<<"\nAddress:\t";
    cin>>s[pos-1].addr;
    return n+1;
}
int deleteRecord(int n)
{
	int pos,i;
	cout<<"\nEnter the position of the element to be deleted";
	cin>>pos;
	for(i=pos-1;i<n-1;i++)
	{
		s[i]=s[i+1];
	}
	n=n-1;
	return n;
}
void updateRecord()
{
	int rno,i=0;
	cout<<"\nEnter the roll number to update the record";
	cin>>rno;
	while(s[i].roll!=rno)
	{
		i++;
	}
	cout<<"\nEnter the new record";
	cin>>s[i].roll>>s[i].name>>s[i].addr;
}
void sortData(int n)
{
	int i,j;
    cout<<"\n------------------Sorted Records-----------------\n";
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(s[j].roll>s[j+1].roll)
			{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
			}
		}
	}
	displayData(n);
}
void searchData(int n)
{
	int begin,end,mid,i,j,rno;
	cout<<"\nEnter the roll number to search the record: ";
	cin>>rno;
	begin=0;
	end=n-1;
	mid=(begin+end)/2;
	while(begin<=end)
    {
        if(s[mid].roll<rno)
        {
            begin=mid+1;
        }
        else if(s[mid].roll==rno)
        {
            cout<<"\n------------------Record found--------------------\n";
            cout<<"\nRollNo\tName\tAddress\n";
            cout<<"--------------------------------------------------";
            cout<<"\n"<<s[mid].roll<<"\t"<<s[mid].name<<"\t"<<s[mid].addr<<"\n";
            cout<<"--------------------------------------------------";
            break;
        }
        else
        {
            end=mid-1;
        }
        mid=(begin+end)/2;
    }
    if(begin>end)
    {
        cout<<"Record not found";
    }
}
int main()
{
	int n,choice;
	cout<<"\nEnter the number of records: ";
	cin>>n;
	getData(n);
	do
	{
	    cout<<"\nEnter Your choice:\t";
        cout<<"\n1-Sort Data\n2-Search Data\n3-Display Data\n4-Insert Record\n5-Delete Record\n6-Update\n";
        cin>>choice;
		switch(choice)
		{
			case 1: sortData(n);
			break;
			case 2: searchData(n);
			break;
			case 3: displayData(n);
			break;
			case 4: n=insertRecord(n);
			break;
			case 5:	n=deleteRecord(n);
					displayData(n);
			break;
			case 6: updateRecord();
					displayData(n);
			break;
			default: cout<<"Wrong Choice!!";
		}
		cout<<"\nPress 1 to continue..\t";
		cin>>choice;
	}while(choice==1);

	return 0;
}
