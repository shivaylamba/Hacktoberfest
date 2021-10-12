#include <stdio.h>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <string.h>
//#include <process.h>

using namespace std;


class Book
{
	private :
		int bookId;
		char title[20];
		float price;

	public :
		Book()
		{
			bookId= 0;
			strcpy(title,"no name");
			price = 0;
		}
		void getBookData()
		{
			cout<<"\nEnter Book Id : ";
			cin>>bookId;
			cin.ignore();
			cout<<"Enter Book Name : ";
			cin.getline(title,20);
			cout<<"Enter Book Cost : ";
			cin>>price;
		}
		void showBookData()
		{
			cout<<"\n\nBook Id : "<<bookId<<"\nBook Title : "<<title<<"\nBook Price : "<<price;
		}
		void storeBook(void);
		void viewAllBook(void);
		void searchBook(char *);
		void delBook(char *);
		void updateBook(char *);
};

void Book :: storeBook(void)
{
	if (bookId == 0 && price == 0)
	{
		cout<<"\nInvalid Details";
	}
	else
	{
		ofstream fout;
		fout.open("book.dat", ios::app|ios::binary);
		fout.write((char *)this, sizeof(*this));
		fout.close();
	}
}
void Book:: viewAllBook(void)
{
	ifstream fin;
	fin.open("book.dat", ios::in|ios::binary);
	if(!fin)
		cout<<"\nfile not found";
	else
	{
		fin.read((char *)this, sizeof(*this));
		while(!fin.eof())
		{
			showBookData();
			fin.read((char *)this, sizeof(*this));
		}
	}
	fin.close();
}
void Book:: searchBook(char *t)
{
	ifstream fin;
	fin.open("book.dat", ios::in|ios::binary);
	if(!fin)
		cout<<"\nfile not found";
	else
	{
		fin.read((char *)this, sizeof(*this));
		while(!fin.eof())
		{
			if(!strcmp(t,title))
				showBookData();
			fin.read((char *)this, sizeof(*this));
		}
	}
	fin.close();
}

void Book:: delBook(char *t)
{
	ifstream fin;
	ofstream fout;

	fin.open("book.dat", ios::in|ios::binary);
	if(!fin)
		cout<<"\nfile not found";
	else
	{
		fout.open("temp.dat",ios::out|ios::binary);
		fin.read((char *)this, sizeof(*this));
		while(!fin.eof())
		{
			if(strcmp(t,title))
			{
				showBookData();
				fout.write((char *)this, sizeof(*this));
			}
			fin.read((char *)this, sizeof(*this));
		}
	}
	fin.close();
	fout.close();
	remove("book.dat");
	rename("temp.dat","book.dat");
	viewAllBook();
}

void Book:: updateBook(char *t)
{
	fstream f;

	f.open("book.dat", ios::in|ios::out|ios::ate|ios::binary);
	if(!f)
		cout<<"\nfile not found";
	else
	{
		f.seekg(0);
		f.read((char *)this, sizeof(*this));
		while(!f.eof())
		{
			if(!strcmp(t,title))
			{
				showBookData();
				getBookData();
				f.seekp(f.tellp()- (sizeof(*this)));
				f.write((char *)this, sizeof(*this));
			}
			f.read((char *)this, sizeof(*this));
		}
	}
	f.close();
	viewAllBook();
}

void main()
{
	clrscr();
	Book b1;
	int ch;
	char cont='y';
	char bb[20];

	while(cont=='y' || cont=='Y')
	{
		clrscr();
		cout<<"\nMain Menu";
		cout<<"\n1. Add Book Details";
		cout<<"\n2. View Book Details";
		cout<<"\n3. View All Book Details";
		cout<<"\n4. Update Book Details";
		cout<<"\n5. Remove Book";
		cout<<"\n6. ...e X i t...";
		cout<<"\n Enter your choice";
		cin>>ch;

		switch(ch)
		{
			case 1:
				b1.getBookData();
				b1.storeBook();
				break;
			case 2:
				b1.viewAllBook();
				cin.ignore();
				cout<<"\n\nEnter Book Name : ";
				cin.getline(bb,20);
				b1.searchBook(bb);
				break;
			case 3:
				b1.viewAllBook();
				break;
			case 4:
				b1.viewAllBook();
				cin.ignore();
				cout<<"\n\nEnter Book Name : ";
				cin.getline(bb,20);
				b1.updateBook(bb);
				break;
			case 5:
				b1.viewAllBook();
				cin.ignore();
				cout<<"\n\nEnter Book Name : ";
				cin.getline(bb,20);
				b1.delBook(bb);
				break;
			case 6:
			       cout<<"\nThanks for visiting ...";
			       getch();
			       exit(0);
			default:
				cout<<"\nInvalid Choice....";
		}
		cout<<"\n\nWant to continue...(y/n)...";
		cin>>cont;

	}
	getch();
}
