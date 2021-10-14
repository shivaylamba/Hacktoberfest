#include<fstream>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
class criminal
{
int cidno,age,firno;
char gen,name[20],address[35];
char date[11];
char imark[20];
public: void input();
	void output();
	void modname(){gets(name);}
	void modage(){cin>>age;}
	void modadd(){gets(address);}
	void moddate(){gets(date);}
	int retidno()
	    {return cidno;}
	criminal()
	{cidno=0;
	 age=0;
	 firno=0;
	 gen='-';
	 strcpy(name,"null");
	 strcpy(address,"null");
	 strcpy(date,"null");
	 strcpy(imark,"null");
	}
       ~criminal()
       {}
};

void criminal::input()
{

cout<<"Enter criminal id:";
cin>>cidno;
cout<<"\n";;
cout<<"Enter criminal name:";
fflush(stdin);
gets(name);
cout<<"\n";
cout<<"Enter criminal age:";
cin>>age;
cout<<"\n";
cout<<"Enter criminal gender(M/F):";
fflush(stdin);
cin>>gen;
cout<<"\n";
cout<<"Enter criminal address:";
fflush(stdin);
gets(address);
cout<<"\n";
cout<<"Enter FIR no.:";
cin>>firno;
cout<<"\n";
cout<<"Enter special identification mark (mandatory field):";
fflush(stdin);
gets(imark);
cout<<"\n";
cout<<"Enter date of record entry (dd/mm/yyyy):";
fflush(stdin);
gets(date);
cout<<"\n";
getch();

}

void criminal::output()
{
cout<<"ID:"<<cidno<<endl;
cout<<"Name:"<<name<<endl;
cout<<"Age:"<<age<<endl;
cout<<"Gender:"<<gen<<endl;
cout<<"Address:"<<address<<endl;
cout<<"FIR no.:"<<firno<<endl;
cout<<"Special identification mark:"<<imark<<endl;
cout<<"Date of record entry:"<<date<<endl;
cout<<"\n";
}

void modify(char*a)
{
char t1[20];
strcpy(t1,a);
criminal C;
int x,ch;
char q,conf;
int flag=0;
fstream f1;
f1.open(t1,ios::in|ios::out|ios::binary);
f1.seekg(0);
cout<<"Enter ID no. whose record is to be modified\n";
cin>>x;
while(f1)
{
f1.read((char*)&C,sizeof(C));
if(x==C.retidno())
  {
   int c=f1.tellg()-sizeof(C);
   f1.seekg(c);
   flag=1;
   cout<<"Unedited details:\n";
   C.output();
   cout<<"Enter New details\n";
   C.input();
   f1.write((char*)&C,sizeof(C));
   break;
   }
 }
if(flag!=1)
{cout<<"No such ID no. exists\n";
cout<<"Return to menu to retry\n";}
getch();
f1.close();
}

void delrec(char*a)
{
char t3[20];
strcpy(t3,a);
criminal C;
int x;
char ch,w;
int flag=0;
ofstream f1;
ifstream f2;
f2.open(t3,ios::binary);
if(!f2)
{cout<<"File cannot be opened\n";return;}
f1.open("temp.dat",ios::binary);
if(!f1)
{cout<<"file cannot be opened\n";return;}
do{cout<<"Enter ID no. of criminal whose record is to be deleted\n";
   cin>>x;
   f2.seekg(0);
   while(f2.read((char*)&C,sizeof(C)))
	{
	if(x!=C.retidno())
	  {
	  cout<<"File has been deleted\n";
	  f1.write((char*)&C,sizeof(C));
	  }
	}
   f1.close();
   f2.close();
   remove(t3);
   rename("temp.dat",t3);
   cout<<"Continue deletion of records?\n";
   cin>>ch;
  }while(ch=='Y'||ch=='y');
}

void sort(char*a)
{
int i,j;
char t8[20];
strcpy(t8,a);
int n;
criminal C1,C2[100],temp;
int k=0;
ifstream f4;
ofstream f5;
f4.open(t8,ios::binary|ios::in);
if(!f4)
{cout<<"File cannot be read\n";}
f4.seekg(0);
while(f4)
     {
     f4.read((char*)&C1,sizeof(C1));
     C2[k++]=C1;
     }
     f4.close();
     n=k;
     for(i=0;i<n;i++)
	{
	for(j=0;j<n-1-i;j++)
	   {
	   if(C2[j].retidno()>C2[j+1].retidno())
	     {
	     temp=C2[j];
	     C2[j]=C2[j+1];
	     C2[j+1]=temp;
	     }
	   }
	}
f5.open(t8,ios::binary|ios::out);
if(!f5)
{cout<<"File cannot be written on\n";return;}
f5.seekp(0);
for(i=0;i<n;i++)
   {
   f5.write((char*)&C2[i],sizeof(C2));
   }
f5.close();
cout<<"\t\tSuccess!\n\t\tFile has been sorted\n\t\tTo view sorted file goto menu and hit 'Display all records'\n";
getch();
}

void create(char*a)
{
char t6[20];
strcpy(t6,a);
criminal C;
char ch;
ofstream f;
f.open(t6,ios::binary|ios::app);
do{C.input();
   f.write((char*)&C,sizeof(C));
   cout<<"Continue adding records\n";
   cin>>ch;
  }while(ch=='y'||ch=='Y');
	f.close();
getch();
}

int main()
{
system("cls");
criminal C;
char tempo[20];
int z;
char ch;
system("cls");
cout<<"\n\n\n\n\n\t\t@@@@@@@@@@@@@@@@@ WELCOME TO @@@@@@@@@@@@@@@@@@@@\n\t\t\t\tCRIMINAL DATABASE SYSTEM\n\n\n";
cout<<"Enter name of file\n";
gets(strcat(tempo,".dat"));
system("cls");
cout<<"Let's get started\n";
do{cout<<"Choose operation to be performed\n\t\t1.Add records \n\t\t2.Display all records\n\t\t3.Delete record\n\t\t4.Modify a record\n\t\t5.Sort all records\n\t\t";
cin>>z;
switch(z)
{
case 1:create(tempo);
       break;
case 2:{ifstream g;
       g.open(tempo,ios::binary|ios::app);
       if(!g)
       {cout<<"File cannot be read\n";return 0;}
       g.seekg(0);
       while(g.read((char*)&C,sizeof(C)))
       {C.output();}
       g.close();
       break;}
case 3:delrec(tempo);
       break;
case 4:modify(tempo);
       break;
case 5:sort(tempo);
       break;
default: cout<<"Invalid choice \n";
}
cout<<"Continue operations?\n";
cin>>ch;
system("cls");
}while(ch=='y'||ch=='Y');
cout<<"\n\n\n\n\n\t\t\tThank You for using our software\n";
getch();
return 0;
}
