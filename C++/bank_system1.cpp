#include <bits/stdc++.h>

using namespace std;

class Bank{
	string name="N/A", address="N/A";
	double amount=0;
	public:
		void openAccount();
		void withdrawAmount();
		void depositAmount();
		void display();
};

void Bank::openAccount(){
	char y;
	string skip;
	cout << "\n";
	cout << "Enter your Name:" << endl;
	getline(cin, skip);
	getline(cin, name);
	cout << "Enter Address: " << endl;
	getline(cin, address);
	cout << "Do you want to enter amount ? (y/n)" << endl;
	cin >> y;
	if(y == 'y'){
		cout << "Enter amount: " << endl;
		cin >> amount;
	}
	
}
void Bank::withdrawAmount(){
	double a;
	cout << '\n';
	cout << "Enter amount to be withdrawn: " << endl;
	cin >> a; 
	if(a <= amount){
		amount -= a;
	}else{
		cout << "Amount exceeded" << endl ;
	}
	cout << "Amount left: " ; 
	cout << amount << endl;
	
}
void Bank::depositAmount(){
	double damount;
	cout << "Enter amount to deposit: " << endl;
	cin >> damount;
	amount += damount;
	cout << "Total Amount: " << amount << endl;
	 
}
void Bank::display(){
	cout << "\n";
	cout << "account name: " << name << endl;
	cout << "address: " << address << endl;
	cout << "Amount: " << amount << endl;
	cout << "\n";
	
}

int main(void){
	int c = 1, option;
	Bank obj;
	while(c){
		cout << '\n';
		cout << "Welcome to Local Bank! Please input, how can we help ?" << endl;
		cout << "1) Open a new account." << endl;
		cout << "2) Withdraw Money" << endl;
		cout << "3) Deposit Money" << endl;
		cout << "4) Display Amount" << endl;
		cout << "5) Exit" << endl;
		
		cin >> option;
		switch(option){
			case 1: obj.openAccount();
			break;
			case 2:obj.withdrawAmount();
			break;
			case 3:obj.depositAmount();
			break;
			case 4:obj.display();
			break;
			case 5:c = 0;
			break;
			default: cout << "\n\t INVALID INPUT" << endl;
			
		}
	}
	
	
	
	
	return 0;
}
