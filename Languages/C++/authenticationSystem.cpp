#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void login();
void registr();
void forgot();

main()
{
	int choice;
	cout << "Welcome to Authentication System" << endl;
	cout << "Developed by Ayfolut. 2020" << endl;
	cout << "Loading............................." << endl;
	
	cout << "1. Login" << endl;
	cout << "2. Sign Up" << endl;
	cout << "3. Forgot Credentials" << endl;
	cout << "Select choice: ";
	cin >> choice;
	
	switch(choice)
	{
		case 1:
			login();
			break;
		case 2:
			registr();
			break;
		case 3:
			forgot();
			break;
		case 4:
			cout << "Thanks for using the authentication.";
			break;
		default:
			cout << "Invalid Selection";
			main();
	}
}

void registr()
{
	string reguser, regpass;
	system("cls");
	cout << "Enter Username: ";
	cin >> reguser;
	cout << "Enter Password: ";
	cin >> regpass;
	
	ofstream reg("database.txt", ios::app);
	reg << reguser << " " << regpass << endl;
	system("cls");
	cout << "Registration Success. :)";
	main();
}

void login()
{
	int exist;
	string user, pass, u, p;
	system("cls");
	cout << "Enter Username: ";
	cin >> user;
	cout << "Enter Password: ";
	cin >> pass;
	
	ifstream input("database.txt");
	
	while(input>> u >> p)
	{
		if(u == user && p == pass)
		{
			exist = 1;
		}
	}
	input.close();
	if(exist == 1)
	{
		cout << "Hello " << user << ", welcome to Ayfolut Auth." << endl;
		cin.get();
		cin.get();
		main();
	}else{
		cout << "Auth Failed. Please try again.";
		cin.get();
		cin.get();
		main();
	}
}

void forgot()
{
	int ch;
	system("cls"); 
	cout << "1. Search your account by Username" << endl;
	cout << "2. Search your account by password" << endl;
	cout << "3. Main Menu" << endl;
	
	cout << "Select your choice";
	cin >> ch;
	
	switch(ch)
	{
		case 1:
		{
			int ex = 0;
			string searchuser, su, sp;
			cout << "Enter your last remembered username: ";
			cin >> searchuser;
			
			ifstream searchu("database.txt");
			while(searchu>>su>>sp)
			{
				if(su == searchuser)
				{
					ex = 1;
					break;
				}
			}
			searchu.close();
			if(ex == 1)
			{
				cout << "We have identified your account" << endl;
				cout << "Your password is " << sp << endl;
				cin.get();
				cin.get();
				main();
			}else
			{
				cout << "Sorry, we could not find your account." << endl;
				cin.get();
				cin.get();
				main();
			}
			break;
		}
		
		case 2:
		{
			int exi = 0;
			string searchpass, su2, sp2;
			cout << "Enter the last remembered Password: " << endl;
			cin >> searchpass;
			
			ifstream searchp("database.txt");
			while(searchp>>su2>>sp2)
			{
				if(sp2 == searchpass)
				{
					exi = 1;
					break;
				}
			}
			searchp.close();
	        if(exi == 1)
	        {
	        	cout << "Your Acount has been identified." << endl;
	        	cout << "Your username is " << su2 << endl;
	        	cout << "Your Password is " << sp2 << endl;
	        	cin.get();
	        	cin.get();
	        	main();
			}
			break;
		}
		case 3:
		{
			main();
			break;
		}
		default:
		{
			cout << "You have selected an invalid option, kindly press any key." << endl;
			cin.get();
			cin.get();
			forgot();
		}
	}
}
















