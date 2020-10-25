
// September 30, 2020

/*We will be creating a program that simulates a simple memory game.In this memory game, a grid of face
down cards is created.Every element of the grid has a matching pair.The user's goal is to find the
location of all pairs.For example,
1 4 3
2 3 1
4 2 5
6 6 5
For every iteration of a loop, the grid is displayed, and the user is prompted to enter two coordinates; x
and y.where x is for rowand y is for column.
For example, the coordinates could be(row, column) and start at 0.
(0, 0) (0, 1) (0, 2)
(1, 0) (1, 1) (1, 2)
(2, 0) (2, 1) (2, 2)
(3, 0) (3, 1) (3, 2)
Once the coordinates are entered, the two cards at the corresponding coordinates will be compared to each
other
1) If the cards match each other, the user has found a pair, so we keep them flipped over
2) If the cards do not match, we temporarily show the user the values of the cards at the coordinates,
and then we flip the cards over again
This loop should continue until the user finds all the pairs, or until they choose to quit.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

const int LENGTH = 4;
using namespace std;

// Function prototypes

void InitializeCards(int cards[][LENGTH]);
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH]);
void winCondition(bool faceup[][LENGTH], bool win);
void MatchCheck(int cards[][LENGTH], bool faceup[][LENGTH], int row1, int row2, int col1, int col2);
// you may have more function prototypes
// ======================
// InitializeCards
// Places pairs of numbers in the 2D array and then
// randomly shuffles them.
// ======================
//Notice that when you pass a 2D-array to a function, you MUST specify the number of columns
void InitializeCards(int cards[][LENGTH])
{
	//seed rand() - remember to always do this before using rand()
	// also make sure to include the <time.h> library.
	srand(time(NULL));
	int x1, y1, x2, y2;
	int i;
	int temp;

	// Place pairs in known locations -   this is how our array looks like after
	cards[0][0] = 1; cards[0][1] = 1;//   1  1  2  2
	cards[0][2] = 2; cards[0][3] = 2;
	cards[1][0] = 3; cards[1][1] = 3;//   3  3  4  4
	cards[1][2] = 4; cards[1][3] = 4;
	cards[2][0] = 5; cards[2][1] = 5;//   5  5  6   6
	cards[2][2] = 6; cards[2][3] = 6;
	cards[3][0] = 7; cards[3][1] = 7;//   7  7  8   8
	cards[3][2] = 8; cards[3][3] = 8;

	// Now that 2D has been initialized with 8 pairs, we want to shuffle the board so
	// that the pairs aren't right next to each other
	for (int i = 0; i < 30; i++) {
		//Get set of random coordinates and swap
		//First random coordinate on our 2d "grid"
		y1 = rand() % LENGTH;
		x1 = rand() % LENGTH;
		//Second random coordinate of our 2d "grid"
		y2 = rand() % LENGTH;
		x2 = rand() % LENGTH;

		//Now we swap value at (x1, y1) with value at(x2, y2)
		temp = cards[x1][y1];
		cards[x1][y1] = cards[x2][y2];
		cards[x2][y2] = temp;
		//Note: just like with 1D arrays, modifying an n-dimensional array inside
		// a function will change the array itself
	}
}



// ======================
//     main function
// ======================
int main()
{
	// 1) Welcome the user and ask him to enter his full name.

	cout << "Hello User! Please enter your name: ";	// add your code here

	string username;
	getline(cin, username); //Read user input: full name



	// 2) Create a two 2D array that will hold the number for each card. Pass it to 
	// 	  InitializeCards function. 

	int cardNumber[LENGTH][LENGTH];
	InitializeCards(cardNumber);	// add your code here

	// 3) Create the 2D array of Booleans that represents whether or not the card is matched. 
	// 	  This should be initialized to all FALSE at first. 

	bool match[LENGTH][LENGTH];
	for (int i = 0; i < LENGTH; ++i) {
		for (int j = 0; j < LENGTH; ++j) {
			match[i][j] = false;
		}
	}// add your code here

	// 4) while the game is not over :

	int row1 = 0;
	int row2 = 0;		//holds user input for coordinates
	int col1 = 0;
	int col2 = 0;
	// Display the current state of the game board. Remember that non-matched pairs should be "facedown"
	// and that matched pairs should be "faceup"

	cout << "Greetings, " << username << endl;
	cout << "Welcome to the Matching Pair game!" << endl;
	cout << "Note: You will be given an option to continue the game or not after you enter the coordinates" << endl << endl;

	// add your code here

	char quitVal = 'Y';
	int turns = 0; //holds the value for how many turns the user takes
	bool win = false; //holds the boolean value if the user has won the game. If the value changes to true that means the user has won

	ShowCards(cardNumber, match);
	cout << endl << endl;

	while (quitVal != 'N' && quitVal != 'n') {
		{

			cout << "Please enter the row of the first coordinate: ";// Prompt the user to enter the coordinates of two cards
			cin >> row1;
			while(row1 >= 4 || row1 < 0){
					cout << "INVALID INPUT! Please enter coordinates between 0 to 3" << endl;
					cout << "Please enter the row of the first coordinate: ";
					cin >> row1;
			}
			cout << "Please enter the column of the first coordinate: ";
			cin >> col1;
			while (col1 >= 4 || col1 < 0) {
				cout << "INVALID INPUT! Please enter coordinates between 0 to 3" << endl;
				cout << "Please enter the column of the first coordinate: ";
				cin >> col1;
			}

			cout << "Please enter the row of the second coordinate: ";
			cin >> row2;
			while (row2 >= 4 || row2 < 0) {
				cout << "INVALID INPUT! Please enter coordinates between 0 to 3" << endl;
				cout << "Please enter the row of the second coordinate: ";
				cin >> row2;
			}
			cout << "Please enter the column of the second coordinate: ";
			cin >> col2;
			while (col2 >= 4 || col2 < 0) {
				cout << "INVALID INPUT! Please enter coordinates between 0 to 3" << endl;
				cout << "Please enter the column of the second coordinate: ";
				cin >> col2;
			}

			turns++;
			MatchCheck(cardNumber, match, row1, row2, col1, col2);//Checks if values in the coordinates match. if they do match will be set to true.
			winCondition(match, win); //Prints out the table. a " * " will be printed out if (match = false) and the values in the coordinates if (match = true)

		}
		cout << "\n\nEnter 'n' or 'N' to quit or enter 'Y' to continue..." << endl;
		cin >> quitVal; //Lets the user choose to continue or quit the game
		if (quitVal != 'n' && quitVal != 'N')
		{
			cout << "Flipping cards over...\n" << endl;
			ShowCards(cardNumber, match);
			cout << endl << endl;
		}

	}// Note: user can choose to quit

	// 5) Save the user’s name and how many turns it took to win the game into an output text file. If he quits
	// before winning save “Don’t give up” message in the file.

	ofstream userFile; //creates an object called userFile for data to be inputted in
	userFile.open("userFile.txt"); //creates a file in the directory called "userFile.txt"

	userFile << username << endl << "Turns taken: " << turns << endl; //prints into the file the name of the user and how many turns they took
	if (win == false)												  //prints into the file "Don't give up" if the user exits before winning
		userFile << "Don't give up" << endl;
	else if (win == true)											  //prints into the file a congratulations message if the user wins the game
		userFile << "Congratulations! You won the Matching pair game!" << endl;
	userFile.close();
	// add your code here
}

// ======================
// ShowCards
// Generates a display on the screen.  If faceup=false,
// an * is output, otherwise the card in that slot is output.
// ======================
void ShowCards(int cards[][LENGTH], bool faceup[][LENGTH]) {

	cout << "     0  1  2  3  " << endl; //Creates header
	cout << "==================" << endl;
	for (int i = 0; i < LENGTH; ++i) {
		cout << i << " | "; //Creates border on the left side for each row 
		for (int j = 0; j < LENGTH; ++j) {
			if (faceup[i][j] == false) //Shows unmatched "facedown" cards
				cout << " * ";
			else if (faceup[i][j] == true) //Shows matched "faceup" cards.
				cout << " " << cards[i][j] << " ";
		}
		cout << " | " << endl; //Creates border on the right side for each row
	}// add your code here
}

// ======================
// MatchCheck
// This function will check if the coordinates inputted by the user have matching values.
// This function will also check the validity of the user's input.
// If the values dont match the cards will only be temporarily "flipped over"
// ======================

void MatchCheck(int cards[][LENGTH], bool faceup[][LENGTH], int row1, int row2, int col1, int col2) {
	if (row1 == row2 && col1 == col2) // Prevents the card being flipped over when the user enters the same coordinates twice
	{
		cout << "INVALID INPUT! You entered the same coordinate twice! Please try again!" << endl;
		faceup[row1][col1] = false;
	}
	else if (cards[row1][col1] == cards[row2][col2])
	{
		cout << "Match found!" << endl; // If the values of the two coordinates match :
										// say that a match has been found and flip the cards over forever
		faceup[row1][col1] = true;		// add your code here
		faceup[row2][col2] = true;
	}
	else if (faceup[row1][col1] == true && faceup[row2][col2] == false)	//Prevents matched cards from being facedown again due to user input
	{
		cout << "INVALID INPUT! You entered a coordinate that is already matched! Please try again!" << endl;
		faceup[row1][col1] = true;
	}
	else if (faceup[row1][col1] == false && faceup[row2][col2] == true) //Prevents matched cards from being facedown again due to user input
	{
		cout << "INVALID INPUT! You entered a coordinate that is already matched! Please try again!" << endl;
		faceup[row2][col2] = true;
	}
	else if (cards[row1][col1] != cards[row2][col2])
	{
		cout << "\n\nMismatch! Please try again!" << endl;
		faceup[row1][col1] = true; //Flips cards "open" or "faceup"
		faceup[row2][col2] = true; //
		cout << "     0  1  2  3  " << endl;
		cout << "==================" << endl;
		for (int i = 0; i < LENGTH; ++i) {
			cout << i << " | "; //Creates border on the left side for each row 
			for (int j = 0; j < LENGTH; ++j) {
				if (faceup[i][j] == false)	//Prints out "*" for cards not selected by user
					cout << " * ";
				else if (faceup[i][j] == true) //Flips over (faceup) cards selected by user
					cout << " " << cards[i][j] << " ";
			}
			cout << " | " << endl; //Creates border on the right side for each row
		}
		faceup[row1][col1] = false; //Flips cards "close" or "facedown" after revealing values to user
		faceup[row2][col2] = false; //
	}

}

// ======================
// winCondition
// This function will keep track of the users progress within the game and will let them know if he/she has won.
// 
// ======================

void winCondition(bool faceup[][LENGTH], bool win) {
	int i = 0;
	int j = 0;
	int trueCounter = 0;

	while (i < LENGTH && j < LENGTH)
	{
		for (i = 0; i < LENGTH; ++i)
		{
			for (j = 0; j < LENGTH; ++j)
			{
				if (faceup[i][j] == true)
					trueCounter++;
			}
		}
	}

	int pairCounter = trueCounter / 2;

	if (trueCounter == 8) {
		cout << "Congratulations! You have won the game!" << endl;
		win = true;
	}
	else if (trueCounter < 8)
		cout << "\n\nIt's alright! Keep going you'll get there soon! You have " << pairCounter << " out of 8 matched pairs so far!" << endl;


}
/* START OF SAMPLE RUN
Hello User! Please enter your name: Ferdz Duterte
Greetings, Ferdz Duterte
Welcome to the Matching Pair game!
Note: You will be given an option to continue the game or not after you enter the coordinates

	 0  1  2  3
==================
0 |  *  *  *  *  |
1 |  *  *  *  *  |
2 |  *  *  *  *  |
3 |  *  *  *  *  |


Please enter the row of the first coordinate: 0
Please enter the column of the first coordinate: 0
Please enter the row of the second coordinate: 1
Please enter the column of the second coordinate: 1


Mismatch! Please try again!
	 0  1  2  3
==================
0 |  3  *  *  *  |
1 |  *  1  *  *  |
2 |  *  *  *  *  |
3 |  *  *  *  *  |


It's alright! Keep going you'll get there soon! You have 0 out of 8 matched pairs so far!


Enter 'n' or 'N' to quit or enter 'Y' to continue...
Y
Flipping cards over...

	 0  1  2  3
==================
0 |  *  *  *  *  |
1 |  *  *  *  *  |
2 |  *  *  *  *  |
3 |  *  *  *  *  |


Please enter the row of the first coordinate: -2
INVALID INPUT! Please enter coordinates between 0 to 3
Please enter the row of the first coordinate: 1
Please enter the column of the first coordinate: -2
INVALID INPUT! Please enter coordinates between 0 to 3
Please enter the column of the first coordinate: 3
Please enter the row of the second coordinate: 1
Please enter the column of the second coordinate: 4
INVALID INPUT! Please enter coordinates between 0 to 3
Please enter the column of the second coordinate: 1


Mismatch! Please try again!
	 0  1  2  3
==================
0 |  *  *  *  *  |
1 |  *  1  *  4  |
2 |  *  *  *  *  |
3 |  *  *  *  *  |


It's alright! Keep going you'll get there soon! You have 0 out of 8 matched pairs so far!


Enter 'n' or 'N' to quit or enter 'Y' to continue...
Y
Flipping cards over...

	 0  1  2  3
==================
0 |  *  *  *  *  |
1 |  *  *  *  *  |
2 |  *  *  *  *  |
3 |  *  *  *  *  |


Please enter the row of the first coordinate: 3
Please enter the column of the first coordinate: 1
Please enter the row of the second coordinate: 2
Please enter the column of the second coordinate: 2


Mismatch! Please try again!
	 0  1  2  3
==================
0 |  *  *  *  *  |
1 |  *  *  *  *  |
2 |  *  *  5  *  |
3 |  *  6  *  *  |


It's alright! Keep going you'll get there soon! You have 0 out of 8 matched pairs so far!


Enter 'n' or 'N' to quit or enter 'Y' to continue...
Y
Flipping cards over...

	 0  1  2  3
==================
0 |  *  *  *  *  |
1 |  *  *  *  *  |
2 |  *  *  *  *  |
3 |  *  *  *  *  |


Please enter the row of the first coordinate: 2
Please enter the column of the first coordinate: 1
Please enter the row of the second coordinate: 0
Please enter the column of the second coordinate: 2


Mismatch! Please try again!
	 0  1  2  3
==================
0 |  *  *  1  *  |
1 |  *  *  *  *  |
2 |  *  4  *  *  |
3 |  *  *  *  *  |


It's alright! Keep going you'll get there soon! You have 0 out of 8 matched pairs so far!


Enter 'n' or 'N' to quit or enter 'Y' to continue...
n

C:\Users\ferdz\source\repos\Assign1\Debug\Assign1.exe (process 15808) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

END OF SAMPLE RUN
*/