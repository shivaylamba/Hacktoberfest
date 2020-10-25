// September 30, 2020
/* 

This Program will save a student's information at a school and print it out

The Program will save the number of students in the system, the student's name, 
the number of tests each student has taken, and the scores they got for each test
(Even if the number of tests each student has taken differs from each other the 
program will be able to save the scores and output it correctly)

The Program will output all the data entered by the user in the following format:

There are (# of students) students in the system
   
Name of student #1: SAMPLE NAME
Grades of student #1: 99 99 99 99
   
Name of student #2: SAMPLE2 NAME2
Grades of student #2: 99 99 99 99
   
etc....

*/
#include <iostream>
#include <string>
using namespace std;

int inputData(string*&, double**&);
void displayData(string*, double**, int);
void cleanHeap(string*, double**, int);

int main() {

	string* name;					//Holds string pointer for student names
	double** testScores;			//Holds double pointer for student test scores and assigns it to null				
	int numStudents = inputData(name, testScores); //Holds int value for number of Students
															 //It's value is returned from inputData function
	displayData(name, testScores, numStudents);	//Calls to displayData function
	cleanHeap(name, testScores, numStudents);					//Calls to cleanHeap function
}

/*================================================================================
	InputData
	This function will take in all input data and will pass by reference all values
	via pointers
===================================================================================*/

int inputData(string*& name, double**& score) {

	int numStudents; //holds int value for number of students *Will be the value returned at end of function*

	cout << "How many students do you wish to enter?: " << endl;	//prompts user to enter # of students
	cin >> numStudents;
	while(numStudents < 0) {	//checks for validity of input *Will keep on iterating until a positive value is entered*
		cout << "INVALID INPUT! You must enter a positive value! Try again!" << endl;
		cout << "How many students do you wish to enter?: " << endl;
		cin >> numStudents;
	}
	cin.ignore();

	name = new string[numStudents];		//creates an array for student names in heap
	score = new double* [numStudents];	//creates an array of pointers for student scores
										//^This allows us to creates a makeshift 2D array later on

	string tempName;
	double tempScore;	//these variables will temporarily hold the values of user input
	int tempNumTests;	//after the values are inputted they are then transferred into the corresponding array

	for (int i = 0; i < numStudents; i++) {

		cout << "Enter the name of student #" << i + 1 << ": " << endl;
		getline(cin, tempName);
		name[i] = tempName; //sets the element in name[i] = to the name input by user 
							//Ex. i = 0 | student #1 name = Ferdz Duterte | name[i] = name[0] = Ferdz Duterte | 

		cout << "How many tests did " << name[i] << " take?: " << endl; //Prompts user to enter # of tests the current student took
		cin >> tempNumTests;
		while (tempNumTests < 0) { //checks for validity of input *Will keep on iterating until a positive value is entered*
			cout << "INVALID INPUT! You must enter a positive value! Try again!" << endl;
			cout << "How many tests did " << name[i] << " take?: " << endl;
			cin >> tempNumTests;
		}

		score[i] = new double[tempNumTests+1]; //creates a 2D array for student scores
		score[i][0] = tempNumTests;			//Since the value of tempNumTests varies each iteration it will
											 //create an array with different # columns per student

		for (int j = 1; j < tempNumTests + 1; j++) {
			cout << "Enter grade #" << j << ": " << endl; //prompts user to enter grades
			cin >> tempScore;
			while (tempScore < 0 || tempScore > 100) { //checks for validity of input *Will keep on iterating until a positive value is entered*
				cout << "INVALID INPUT! You must enter a value between 0-100! Try again!" << endl;
				cout << "Enter grade #" << j << ": " << endl;
				cin >> tempScore;
			}
			score[i][j] = tempScore; //sets the scores for each student = score input by user
									 //The row corresponds to the student # (student i+1)
									 //On each column the score will be inputted
		}
		cin.ignore();
	}
	return numStudents;	//returns the # of students to main
}
/*=====================================================================================
	displayData
	This function will display all the data input by the user in the following format
	STUDENTNAME: (SCORE1) (SCORE2) (SCORE3) ...
  ======================================================================================*/
void displayData(string* name, double** score, int numStudents) {
	
	cout << "\nThere are " << numStudents << " students in the system\n" << endl; //Prints total number of students inputted
	for (int i = 0; i < numStudents; i++) {
		cout << "Name of student #" << i + 1 << ": " << name[i] << endl;//Prints the name of the current student for the iteration
		cout << "Grades for student #" << i + 1 << ": ";
		for (int j = 1; j < score[i][0] + 1; j++) {		//Loop will keep iterating until the all test scores for the
			cout << score[i][j] << " ";				//current student has been printed
		}
		cout << endl << endl;	//Moves to next line for the next student once all scores for the current student have been printed
	}
}

/*==============================================================
	cleanHeap
	This function will clean all the dynamic allocated memory
	stored in heap
================================================================*/
void cleanHeap(string* name, double** score, int numStudents){
	
	delete[] name; //Deletes the array of student names
	for(int i = 0; i < numStudents; i++){ //Loop will delete the array of doubles the array of pointers are pointing to.
	delete[] score[i];
	}
	delete[] score; //deletes array of pointers
}
/*========================================================================================
  ~~~~~~~~~~~~~~ S A M P L E -------- R U N --------- S T A R T ~~~~~~~~~~~~~~~~~~~~~~~~~~
  ========================================================================================
  
How many students do you wish to enter?:
-2
INVALID INPUT! You must enter a positive value! Try again!
How many students do you wish to enter?:
2
Enter the name of student #1:
Ferdz Duterte
How many tests did Ferdz Duterte take?:
3
Enter grade #1:
-100
INVALID INPUT! You must enter a value between 0-100! Try again!
Enter grade #1:
101
INVALID INPUT! You must enter a value between 0-100! Try again!
Enter grade #1:
100
Enter grade #2:
100.00
Enter grade #3:
-1
INVALID INPUT! You must enter a value between 0-100! Try again!
Enter grade #3:
0
Enter the name of student #2:
Clide Aquino
How many tests did Clide Aquino take?:
2
Enter grade #1:
101
INVALID INPUT! You must enter a value between 0-100! Try again!
Enter grade #1:
87.43
Enter grade #2:
69.69

There are 2 students in the system

Name of student #1: Ferdz Duterte
Grades for student #1: 100 100 0

Name of student #2: Clide Aquino
Grades for student #2: 87.43 69.69

C:\Users\ferdz\source\repos\Assign2 v2.0\Debug\Assign2 v2.0.exe (process 10436) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

========================================================================================
~~~~~~~~~~~~~~~~ S A M P L E -------- R U N --------- E N D ~~~~~~~~~~~~~~~~~~~~~~~~~~~~
========================================================================================
*/