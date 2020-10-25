/* 
10/19/2020
simulates a simple vending machine that sellschips, candy, and soda. Each of 
these snacks has a different price and will have a different amount in stock. 
When the program is running, the current contents of the vending machine will
be displayed to the user, and then a prompt to enter a number of quarters will
appear. After the user enters a number, the amount of money they entered will 
appear in dollars and cents. For example, if the user entered 7 quarters, $1.75
would be displayed. Next, the user will be prompted to make a selection from 
the vending machine. If they have entered enough money and the snack is 
in-stock, the item will be dispensed, and the number in-stock will decrease by
one. If the user entered more money than necessary to make the purchase, a 
message will be displayed indicated that the appropriate amount of change has
been returned.
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
using namespace std;

/*
Snack
This is basically the body of the code defining everything
The public members are mostly functions that are setters and getters 
for the private members. I also added in a print function so that there
will be less code in main*/
class Snack {

	public:

		Snack(); //default constructor
		Snack(string, double, int); //overloaded constructor

		//inlined setters since they are short
		void SetName(string nameToSet) { snackName = nameToSet; }
		void SetPrice(double priceToSet) { snackPrice = priceToSet; }

		//decided to define the function here since it was not too long
		void SetQuantity(int quantityToSet) {
			snackInStock = quantityToSet;
			timePtr = new string[quantityToSet]; //set values for timePtr here
		}									//since it was impossible to do so
											//in the default constructor

		//inlined getters
		string GetName() const { return snackName; } 
		double GetPrice() const { return snackPrice; }
		int GetQuantity() const { return snackInStock; }
		int GetSold() const { return snackSold; }
		bool buyItem(double&);
		void Print() const;
		string GetCurrentTime(); //provided function
		~Snack();

	private:
		
		string* timePtr;
		string snackName;
		double snackPrice;
		int snackInStock;
		int snackSold;
};

//function declarations
void displayVendingMachine(const Snack[], int);
int getQuarters();
void userBuyItem(Snack[], int);
bool promptToContinue();

Snack::Snack() {//default constructor

	snackName = "";
	snackPrice = 0;
	snackInStock = 0;
	snackSold = 0;
}

//overloaded construct, has parameters
Snack::Snack(string nameToSet, double priceToSet, int quantityToSet) {
	
	snackName = nameToSet;
	snackPrice = priceToSet;
	snackInStock = quantityToSet;
	snackSold = 0;
	timePtr = new string[snackInStock];
}

/*
Snack::buyItem
Checks whether money is enough and item is available
will then return a bool value (true/false).
Returns true if money is enough and decrements the quantity
of snacks in stock and increments the # of snacks sold.
Returns false if money is insufficient or item is sold out
Also displays the change dispensed to user
*/
bool Snack::buyItem(double& moneyEntered) {

	if (snackInStock <= 0) {
		cout << "ERROR: Item is sold out" << endl;
		snackInStock = 0;
		cout << "$" << moneyEntered << " dispensed below." << endl;
		return false;
	}

	else if (moneyEntered >= snackPrice){
		moneyEntered = moneyEntered - snackPrice;
		snackInStock--;
		snackSold++;
		timePtr[snackInStock] = GetCurrentTime();
		cout << snackName << " has been dispensed" << endl;
		if (moneyEntered != 0) {
			cout << "$" << moneyEntered << " dispensed below." << endl;
			}
		return true;
	}

	else if(moneyEntered < snackPrice){
		cout << "You don't have enough money for that!" << endl;
		return false;
	}

}

//prints a line containing name of snack, snack price, and # of snacks
void Snack::Print() const {

	cout << left << setw(15) << snackName
		<< left << setw(15) << fixed << setprecision(2) << snackPrice
		<< left << setw(15) << snackInStock << endl;

}

//displays the table for the vending machine
void displayVendingMachine(const Snack SnackArr[], int SIZE) {

	cout << left << setw(15) << "Item #"
		<< left << setw(15) << "Item Name"
		<< left << setw(15) << "Price"
		<< left << setw(15) << "# in-stock" << endl;

	cout << left << setfill('=') << setw(59) << "=" << endl;

	//prints 3 lines of snacks(Chips, Candy, Soda)
	for (int i = 0; i < SIZE; i++) {

		cout << left << setfill(' ') << setw(15) << i + 1;
		SnackArr[i].Print();
	}
}

//gets number of quarters user has, loops until valid input is entered 
int getQuarters() {

	int quarterCount = -1;

	while (quarterCount <= 0) {
		cout << "\nEnter a number of quarters: ";
		cin >> quarterCount;

		if (quarterCount <= 0) {
			cout << "Please enter a number greater than 0" << endl;
		}
	}
	return quarterCount;
}

//displays the vending machine table and let's the user select which snack
//selection will keep looping until valid input (1, 2, 3) is entered
//also converts quarters to dollars and cents
void userBuyItem(Snack SnackArr[], int SIZE) {

	displayVendingMachine(SnackArr, SIZE);
	int quarters = getQuarters();
	double totalMoney = quarters * 0.25;

	cout << "Amount Entered: $" << totalMoney << endl;

	int snackSel = -1;

	while (snackSel > 3 || snackSel < 1) {
		cout << "\nEnter a number between 1 and 3 to make your selection : ";
		cin >> snackSel;
		if (snackSel > 3 || snackSel < 1)
			cout << "INVALID INPUT" << endl;
	}
	SnackArr[snackSel - 1].buyItem(totalMoney);
}

//asks if the user wants to continue using the vending machine
bool promptToContinue() {

	char choice;

	cout << "\nContinue? (Y/N): ";
	cin >> choice;

	if (choice == 'Y' || choice == 'y') {
		return true;
	}

	else {
		return false;
	}
}

//provided function
string Snack::GetCurrentTime() {

	time_t t = time(0);
	struct tm ts;
	char buff[10];
	ts = *localtime(&t);
	strftime(buff, sizeof(buff), "%X", &ts);
	return buff;

}

//destructor
//will print closing info and profit once main is exited
Snack::~Snack() {

	cout << "\nClosing info for " << GetName() << endl
		<< right << setw(15) << GetQuantity() << " in stock" << endl
		<< right << setw(15) << GetSold() << " sold for a profit of $"
		<< GetSold() * GetPrice() << endl;

	int initStock = (snackInStock + snackSold);
	int i = initStock - 1;
	if (timePtr[i].length() != 0) {//prints if the string contains something
		cout << "\nTransactions occured at:" << endl;
		while (i >= snackInStock) {//prints transaction times
			cout << right << setw(22) << timePtr[i] << endl;
			i--;
		}
	}
delete[] timePtr;
}

//driver code
int main() {

	const int SIZE = 3;
	Snack SnackArr[SIZE] = { 
		Snack(), //initialized by default constructor
		Snack("Candy", 1.25, 5), //initialized by overloaded constructor
		Snack("Soda", 1.00, 2) //initialized by overloaded constructor
	};

	//setters that will changed the initial values set by default constructor
	SnackArr[0].SetName("Chips");
	SnackArr[0].SetPrice(1.75);
	SnackArr[0].SetQuantity(3);

	bool run = true; //sentinel value to keep the program running

	while (run) { //loops as long as run == true
		userBuyItem(SnackArr, SIZE); 
		run = promptToContinue(); //checks if user wants to continue
		cout << endl;			//loop exits if user chooses N/n
	}
}

/* SAMPLE RUN 
Item #         Item Name      Price          # in-stock
===========================================================
1              Chips          1.75           3
2              Candy          1.25           5
3              Soda           1.00           2

Enter a number of quarters: -1
Please enter a number greater than 0

Enter a number of quarters: 12
Amount Entered: $3.00

Enter a number between 1 and 3 to make your selection : 0
INVALID INPUT

Enter a number between 1 and 3 to make your selection : -1
INVALID INPUT

Enter a number between 1 and 3 to make your selection : 4
INVALID INPUT

Enter a number between 1 and 3 to make your selection : 3
Soda has been dispensed
$2.00 dispensed below.

Continue? (Y/N): y

Item #         Item Name      Price          # in-stock
===========================================================
1              Chips          1.75           3
2              Candy          1.25           5
3              Soda           1.00           1

Enter a number of quarters: 12
Amount Entered: $3.00

Enter a number between 1 and 3 to make your selection : 3
Soda has been dispensed
$2.00 dispensed below.

Continue? (Y/N): y

Item #         Item Name      Price          # in-stock
===========================================================
1              Chips          1.75           3
2              Candy          1.25           5
3              Soda           1.00           0

Enter a number of quarters: 3
Amount Entered: $0.75

Enter a number between 1 and 3 to make your selection : 2
You don't have enough money for that!

Continue? (Y/N): y

Item #         Item Name      Price          # in-stock
===========================================================
1              Chips          1.75           3
2              Candy          1.25           5
3              Soda           1.00           0

Enter a number of quarters: 12
Amount Entered: $3.00

Enter a number between 1 and 3 to make your selection : 3
ERROR: Item is sold out
$3.00 dispensed below.

Continue? (Y/N): y

Item #         Item Name      Price          # in-stock
===========================================================
1              Chips          1.75           3
2              Candy          1.25           5
3              Soda           1.00           0

Enter a number of quarters: 12
Amount Entered: $3.00

Enter a number between 1 and 3 to make your selection : 2
Candy has been dispensed
$1.75 dispensed below.

Continue? (Y/N): y

Item #         Item Name      Price          # in-stock
===========================================================
1              Chips          1.75           3
2              Candy          1.25           4
3              Soda           1.00           0

Enter a number of quarters: 12
Amount Entered: $3.00

Enter a number between 1 and 3 to make your selection : 2
Candy has been dispensed
$1.75 dispensed below.

Continue? (Y/N): y

Item #         Item Name      Price          # in-stock
===========================================================
1              Chips          1.75           3
2              Candy          1.25           3
3              Soda           1.00           0

Enter a number of quarters: 12
Amount Entered: $3.00

Enter a number between 1 and 3 to make your selection : 1
Chips has been dispensed
$1.25 dispensed below.

Continue? (Y/N): n


Closing info for Soda
							0 in stock
							2 sold for a profit of $2.00

Transactions occured at:
							23:50:24
							23:50:31

Closing info for Candy
							3 in stock
							2 sold for a profit of $2.50

Transactions occured at:
							23:51:21
							23:51:30

Closing info for Chips
							2 in stock
							1 sold for a profit of $1.75

Transactions occured at:
							23:51:32
*/

