/* 10/13/2020 
The program will read a file database for movies and store all the info
into a dynamically allocated struct

It will then allow the user to search for a movie within the database
the search will not be case sensitive

If the movie is found it will be displayed and will prompt the user
if they want to save it. If they choose to save it will be saved into
a file called favorites.txt. After all of this the user will be prompted
if they want to continue with the program.

If the movie was not found, an error message will be displayed.*/
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

struct Movie {//Movie struct that will hold data for each movie

	string title; //string representing the movie title
	string director; //a string for the director’s name
	string release; //a string for the release date
	int runtime; //an int for the movie’s runtime
	double gross; //a double representing the gross total for the movie
};

int numberOfLines(ifstream&);
void populateMovieFromFile(ifstream&, Movie&);
void displayMovie(const Movie&);
Movie* createDatabase(int&);
bool caseInsensitiveCmp(string, string);
void findMovie(Movie*, int);
void saveToFile(const Movie&);
bool promptToContinue();
void displayFavorites();

/**/
int main() {

	int lineCount; //int for the number of lines in the file
				   //Note: this is uninitialized because the
				   //value will be passed by reference
				   //from the createDatabase function
	
	Movie* moviePtr = createDatabase(lineCount); //value will be return from createDatabase func
	findMovie(moviePtr, lineCount); //calls find movie func

	bool run = promptToContinue(); //creates a bool that will keep the program running if true

	while (run) { //will keep iterating through loop if run = true
		findMovie(moviePtr, lineCount); //calls find movie func
		run = promptToContinue(); //checks if user wants to continue the program
								  //if user chooses to exit, the loop will stop
								  //since run = false
	}

	displayFavorites(); //displays saved favorites each time the program ends
	delete[] moviePtr; //cleans the heap
}

/*
This function accepts an input file and returns an integer representing the number of
lines in the file
*/
int numberOfLines(ifstream& inFile){

	string line;
	int count = 0;

	if(inFile){
		while (getline(inFile, line))
		count++;
	}

	inFile.clear();
	inFile.seekg(0, inFile.beg);
	return count;
}

/*This function accepts an input file and a Movie object. Inside the function, a single line
should be read in from the current read position of the input file. Once the line has been
read in, it will be parsed and stored in the Movie object that was passed to the function. */
void populateMovieFromFile(ifstream& inFile, Movie& movieList) {
	
	//Note: each inFile.ignore() clears the file buffer so that there will be no
	//unexpected errors while reading data from file

	getline(inFile, movieList.title, ','); //reads title string and stops at ','
	inFile.ignore();

	inFile >> movieList.gross; //reads double for movie gross
	inFile.ignore();

	getline(inFile, movieList.director, ','); //reads director string and stops at ','
	inFile.ignore();

	getline(inFile, movieList.release, ','); //reads date string and stops at ','
	inFile.ignore();

	inFile >> movieList.runtime; //reads int for movie runtime
	inFile.ignore();

}

/*This function accepts a Movie object passed by constant reference and displays the
contents of that object in a formatted fashion
Note: this function is similar to saveToFile except instead of cout the output will be
the file itself*/
void displayMovie(const Movie& movieList) {

	cout << endl << setw(20) << "Title: " << movieList.title << endl;
	cout << setw(20) << "Gross: " << movieList.gross << " billion dollars" << endl;
	cout << setw(19) << "Director:" << movieList.director << endl;
	cout << setw(20) << "Relase Date: " << movieList.release << endl;
	cout << setw(20) << "Runtime: " << movieList.runtime << " minutes" << endl;
}

/* this function will be responsible for creating your movie database
(which is just a dynamically-allocated array of Movie objects). The integer argument
passed by reference to the function represents the number of movies in the database. It
will not be initialized when you call the function, meaning its value will be set inside the
body of the function*/
Movie* createDatabase(int& lineCount) {

	string filename;
	Movie movieList; //temporary holds all data read from file

	cout << "Please enter filename: ";
	cin >> filename;

	ifstream inFile;
	inFile.open(filename);

	while (!inFile.is_open()) {
		cout << "\nERROR: the file '" << filename << "' cannot be found " << endl;
		cout << "\nPlease enter filename: ";
		cin >> filename;
		inFile.open(filename);
	}

	if (inFile.is_open()) {
		cout << "\nthe file '" << filename << "' has been successfully opened!" << endl;
	}

	lineCount = numberOfLines(inFile); //counts number of lines in the file
	//tells file pointer to start at 0 chars from
								 //the beginning of file

	Movie* moviePtr = new Movie[lineCount]; //creates a dynamically allocated array
											//of movie pointers

	for (int i = 0; i < lineCount; i++) {//for loop will store movie information into
										 //each moviePtr

			populateMovieFromFile(inFile, movieList); 
			moviePtr[i] = movieList;		
	}

	return moviePtr; //returns moviePtr to main
	inFile.close();	
}

/*This function accepts two strings and performs a noncase-sensitive comparison on the
two. If the two strings are the same, the function should return true; otherwise, it should
return false. For example, if I pass the strings “skyfall” and “SKYFALL” to this function, it
should return true*/
bool caseInsensitiveCmp(string str1, string str2) {
	
	//the two for loops will convert all strings to lowercase
	for (int i = 0; i < str1.length(); i++) {
		str1[i] = tolower(str1[i]);
	}

	for (int j = 0; j < str2.length(); j++) {
		str2[j] = tolower(str2[j]);
	}

	if (str2.find(str1) != string::npos)//searches for user input string inside the movie title
		return true; //if found returns true
	else
		return false; //if not found return false
}

/*This function accepts a pointer to an array of Movie objects (your database), and the
number of Movies (which is the same thing as the number of elements in the array).*/
void findMovie(Movie* moviePtr, int lineCount) { 

	string findMovie; //Holds the user input for the movie to search for
	string tempMovie; //will temporarily hold the dynamically allocated movie title in order
					  //to pass it into the function
	Movie userMovie;  //Struct that temporarily holds the information of the matched movie 
	bool movieFound = false; //bool that checks if a movie was found/not found
	char choice; //Holds user input to save or not save the movie
	static bool savedMov = false; //this static bool will keep track if a movie was saved or not
						   //if this remains false it means no movie has been saved
	ofstream outFile;

	cout << "\nEnter a movie title to search for: ";
	cin.ignore();
	getline(cin,findMovie);

	for (int i = 0; i < lineCount; i++) { //for loop will iterate through all movie titles
		tempMovie = moviePtr[i].title;    //sets string equal to the corresponding string (title) in pointer
		if (caseInsensitiveCmp(findMovie, tempMovie)) { //checks if movie title and user input matches
			userMovie = moviePtr[i]; //userMovie temp holds all data of the matched movie
			movieFound = true; //sets movieFound to true since a match was found

			displayMovie(userMovie); //prints out movie
			cout << "\nWould you like to save the above movie? (Y or N): ";
			cin >> choice;

			if (choice == 'Y' || choice == 'y') {
				saveToFile(userMovie); //saves movie to file
				cout << "Successfully saved to 'favorites.txt'!" << endl;
				savedMov = true;
			}
		}
	}

	if (savedMov == false) {
		outFile.open("favorites.txt");
		outFile.close();
	}

	if (movieFound == false) //prints out this statement if movieFound was not changed to true
		cout << "Error: '" << findMovie << "' not found in database." << endl;
}

/*This function accepts a Movie object, passed by constant reference. It should save the
Movie object to the “favorites.txt” file. If the file does not exist, create it. If the file does
exist, add the Movie object to the end of the file
Note: this function is similar to displayMovie. The only difference is we are opening the file
and then appending to it. Also, instead of the output being "cout" we are outputting to the file
itself.*/
void saveToFile(const Movie& movieList) {

	ofstream outFile;
	static bool firstCall = true;
	
	if (firstCall) { //overwrites favorites file if it exists on the first call
		outFile.open("favorites.txt");
		firstCall = false;
	}

	else if(!firstCall){ //appends to the file if this isn't the first time the function was called
	outFile.open("favorites.txt", outFile.app);
	}

	outFile << movieList.title << ", " << movieList.gross << ", " << movieList.director << ", ";
	outFile << movieList.release << ", " << movieList.runtime << endl;

	outFile.close();
}

/*This function will determine whether or not the user wants to continue using the
program. First, ask the user if they would like to exit the program and prompt them to
either enter ‘Y’ or ‘N’. If ‘Y’ or ‘y’ is entered, the function will return false (the user no
longer wishes to continue); otherwise, return true*/
bool promptToContinue() {

	char userChoice;
	cout << "\nWould you to exit? ( Y / N ): ";
	cin >> userChoice;

	if (userChoice == 'N' || userChoice == 'n')
		return true; //returns true if user chooses to continue
	else
		return false; //returns false if user chooses to exit
}

/*This function will display all saved favorite movies by displaying all the information in the
favorites.txt file. If there are no saved movies, display an error; otherwise, simply display
all saved movies. */
void displayFavorites() {

	ifstream inFile;
	string lineRead;
	inFile.open("favorites.txt");
	int lineCount = numberOfLines(inFile);

	if(lineCount > 0){
		for (int i = 0; i < lineCount; i++) {

			getline(inFile, lineRead, ',');
			cout << endl << setw(20) << "Title: " << lineRead << endl;
			inFile.ignore();

			getline(inFile, lineRead, ',');
			cout << setw(20) << "Gross: " << lineRead << " billion dollars" << endl;
			inFile.ignore();

			getline(inFile, lineRead, ',');
			cout << setw(19) << "Director:" << lineRead << endl;
			inFile.ignore();

			getline(inFile, lineRead, ',');
			cout << setw(20) << "Relase Date: " << lineRead << endl;
			inFile.ignore();

			getline(inFile, lineRead);
			cout << setw(20) << "Runtime: " << lineRead << " minutes" << endl;

		}
	}

	else {
		cout << "\n*******ERROR: THERE ARE NO SAVED MOVIES*******" << endl;
	}
	
}
/* SAMPLE RUN 1
Please enter filename: asdujasd.txt
ERROR: the file cannot be found
Please enter filename: movies.txt

Enter a movie title to search for: The lord of the

			 Title: The Lord of the Rings: The Return of the King
			 Gross: 1.12 billion dollars
		  Director: Peter Jackson
	   Relase Date: 12/17/03
		   Runtime: 200 minutes

Would you like to save the above movie? (Y or N): Y
Successfully saved to 'favorites.txt'!

Would you to exit? ( Y / N ): N

Enter a movie title to search for: tItAnIc

			 Title: Titanic
			 Gross: 2.187 billion dollars
		  Director: James Cameron
	   Relase Date: 12/19/97
		   Runtime: 195 minutes

Would you like to save the above movie? (Y or N): Y
Successfully saved to 'favorites.txt'!

Would you to exit? ( Y / N ): n

Enter a movie title to search for: UlTrOn

			 Title: Avengers: Age of Ultron
			 Gross: 1.405 billion dollars
		  Director: Joss Whedon
	   Relase Date: 5/1/15
		   Runtime: 141 minutes

Would you like to save the above movie? (Y or N): Y
Successfully saved to 'favorites.txt'!

Would you to exit? ( Y / N ): Y
Your saved movies are:


			 Title: The Lord of the Rings: The Return of the King
			 Gross: 1.12 billion dollars
		  Director: Peter Jackson
	   Relase Date: 12/17/03
		   Runtime: 200 minutes

			 Title: Titanic
			 Gross: 2.187 billion dollars
		  Director: James Cameron
	   Relase Date: 12/19/97
		   Runtime: 195 minutes

			 Title: Avengers: Age of Ultron
			 Gross: 1.405 billion dollars
		  Director: Joss Whedon
	   Relase Date: 5/1/15
		   Runtime: 141 minutes


C:\Users\ferdz\source\repos\Assign3\Debug\Assign3.exe (process 8608) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

SAMPLE RUN 2 (No movies saved)

Please enter filename: movies.txt

Enter a movie title to search for: Ultron

			 Title: Avengers: Age of Ultron
			 Gross: 1.405 billion dollars
		  Director: Joss Whedon
	   Relase Date: 5/1/15
		   Runtime: 141 minutes

Would you like to save the above movie? (Y or N): n

Would you to exit? ( Y / N ): Y
ERROR: No movies have been saved

C:\Users\ferdz\source\repos\Assign3\Debug\Assign3.exe (process 14984) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/