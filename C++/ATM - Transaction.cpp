#include<iostream>
using namespace std;
void showMenu()      			// MAIN PRESENTATION
{
	cout<<"**********TRANSACTION MENU**********"<<endl;
	cout<<"1. REMAINING BALANCE  "<<endl;
	cout<<"2. DEPOSIT AMOUNT    "<<endl;
	cout<<"3. WITHDRAW AMOUNT "<<endl;
	cout<<"4. EXIT "<<endl;
	cout<<"************************************"<<endl;
}
int main()
{
	int option; 				//taking options : REMAINING BALANCE, DEPOSIT AMOUNT , WITHDRAW AMOUNT , EXIT
	double balance =1000;		//ENTER THE BALANCE 
	do{							// USING LOOP FUNCTION
		
		showMenu();							//MENU 
		cout<<"option :  "<<endl;
		cin>>option;
		system("cls");					//USED TO CLEAR THE CONSOLE , FOR BETTER DISPLAY
		switch(option)					// USING SWITCH 
		{
		case 1:
			cout<<"YOUR REMAINING BALANCE IS :  "<<balance<<"$"<<endl;				// ADD "$" TO YOUR CURRENCY
			break;
		case 2:
			cout<<"DEPOSIT AMOUNT :  ";
			double depositamount;  						
			cin>>depositamount;
			balance += depositamount;							//  DEPOSIT AMOUNT GETTING ADD TO THE BALANCE ACCOUNT
			break;
		case 3:
			cout<<"WITHDRAW AMOUNT : ";
			double withdrawamount;
			cin>>withdrawamount;					
					if(withdrawamount<=balance)				// WITHDRAW AMOUNT 
			balance -=withdrawamount;											//WITHDRAW AMOUNT IS HIGHER THAN THE MAIN BALANCE 
					else cout<<"NOT HAVE ENOUGH BALANCE"<<endl;				
						 break;
		}
		
	}
			while (option!=4);							//EXIT
			return 0;
}