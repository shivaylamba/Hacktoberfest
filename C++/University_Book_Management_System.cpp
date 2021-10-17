#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
#include<sstream>

using namespace std;


#define SIZE 5
const int MAX_BOOK_ID =13;
const int  DATE_SIZE=11 ;
const int MAX_COPY_NUMBER=17;
const int  MAX_BOOKS= 200 ;
const int	MAX_CATEGORIES= 30 ;
const int	 MAX_STUDENTS=100 ;
const int	  MAX_BOOK_NAME= 60 ;
const int	   MAX_CATEGORY_NAME= 20 ;
const int    MAX_STUDENT_NAME= 60 ;
const int		 MAX_REGISTRATION_NUMBER= 12;
const int MAX_CATEGORY_NUMBER= 4 ;
  int const MAX_USER_NAME = 30;
int const MAX_PASSWORD = 10;

struct Book 
 {
 char Id[13] ;
 char Name[60];
  int Edition;
 };

 struct Category{
 	
char Id[4];
 char Name[20] ; 
 };


struct User
{
	char userName[30];
	char password[10];
};
enum month
 { January=1, February , March , April , May , June , July ,August, September , October ,November ,December};

struct Date{
	int Day;
	int Month;
	int Year;
};
 struct BookCopy{
 	char Id[13];
	Date PurchaseDate ;
 };
enum BookStatus
{
	Returned = 1, Issued = 0
};

struct BookIssue
{
	char regNo[12] ;
	char bookCopyId[13] ;
	BookStatus status;
	 Date issueDate;
};
 struct Student
 {
   char RegistrationNo[12];
    char Name[60];
    int Session;  
    Date AdmissionDate ;
   };
void loadUser(User arr[], int size) 
{
ifstream file;
file.open("users.csv");
	for (int i=0 ; i<SIZE ; i++)
	{
		if(file.eof())
		{
			break ; 
		}
		file.getline(arr[i].userName,30, ',');
		file.getline(arr[i].password,10, '\n');
		
	
	}
	
	file.close();
}

bool findUser(User arr[], int size, User toFind) 
{
	for(int i=0 ; i<SIZE ; i++)
	{
		if ((!strcmp(arr[i].userName, toFind.userName)) && (!strcmp(arr[i].password,toFind.password)))
		{
			return true;
			break;
		}
		else
		    {
		        cout << "False";
		    return false;
		    }
	}
}

bool isValidBookId(char bookId[])
{
	int i;

	for (i = 0; i < 3; i++)
	{
		if (!isdigit(bookId[i]))
		{
			cout << "Enter a number for book Category! Accorging to Format DDD-AA-DDDDD" << endl << endl;

			return false;
		}
	}

	if (bookId[3] != '-')
	{
		cout << "Enter a Hyphen before Language code! According to Format DDD(-)AA-DDDDD" << endl << endl;

		return false;
	}

	if ((!((int)bookId[4] >= 65) && !((int)bookId[4] <= 90)) && (!((int)bookId[5] >= 65) && !((int)bookId[5] <= 90)))
	{
		cout << "Enter a capital Letter for Language Code! According to Format DDD-AA-DDDDD" << endl << endl;

		return false;
	}

	if (bookId[6] != '-')
	{
		cout << "Enter a Hyphen before Book code! According to Format DDD-AA(-)DDDDD" << endl << endl;

		return false;
	}

	for (i = 7; i < MAX_BOOK_ID - 1; i++)
	{
		if (!isdigit(bookId[i]))
		{
			cout << "Enter a number for book Code! Accorging to Format DDD-AA-DDDDD" << endl << endl;

			return false;
		}
	}

	return true;
}

bool isValidbookName(char bookName[])
{
	int n, i = 0;

	while ((bookName[i] != 0) && (i < MAX_BOOK_NAME))
	{
		n = bookName[i];

		if (n == 32)
		{
			if ((int)bookName[i + 1] == 32)
			{
				cout << "Please Enter a Valid Name, You can't enter two Consective Spaces!" << endl << endl;

				return false;
			}
		}
		else if ((n == 44))
		{
			if ((int)bookName[i + 1] == 44)
			{
				cout << "Please Enter a Valid Name, You can't enter two Consective Commas!" << endl << endl;

				return false;
			}
		}
		else if ((n == 58))
		{
			if ((int)bookName[i + 1] == 58)
			{
				cout << "Please Enter a Valid Name, You can't enter two Consective Colons!" << endl << endl;

				return false;
			}
		}

		i++;
	}

	for (int i = 0; i < MAX_BOOK_NAME; i++)
	{
		if (isalpha(bookName[i]) || (bookName[i] == 32) || (bookName[i] == 44) || (bookName[i] == 58) || (bookName[i] == 0))
		{
			continue;
		}
		else
		{
			cout << "Enter a Valid Name, Name only consist of Alphabets, colons, spaces and commas!" << endl << endl;

			return false;
		}
	}

	return true;
}

bool isValidCopyNumber(char bookCopy[])
{
	int i;

	for (i = 0; i < 3; i++)
	{
		if (!isdigit(bookCopy[i]))
		{
			cout << "Enter a number for book Category! Accorging to Format DDD-AA-DDDDD" << endl << endl;

			return false;
		}
	}

	if (bookCopy[3] != '-')
	{
		cout << "Enter a Hyphen before Language code! According to Format DDD(-)AA-DDDDD" << endl << endl;

		return false;
	}

	if (!(((int)bookCopy[4] >= 65) && ((int)bookCopy[4] <= 90)) && !(((int)bookCopy[5] >= 65) && ((int)bookCopy[5] <= 90)))
	{
		cout << "Enter a capital Letter for Language Code! According to Format DDD-AA-DDDDD" << endl << endl;

		return false;
	}

	if (bookCopy[6] != '-')
	{
		cout << "Enter a Hyphen before Book code! According to Format DDD-AA(-)DDDDD" << endl << endl;

		return false;
	}

	for (i = 7; i < MAX_BOOK_ID - 1; i++)
	{
		if (!isdigit(bookCopy[i]))
		{
			cout << "Enter a number for book Code! Accorging to Format DDD-AA-DDDDD" << endl << endl;

			return false;
		}
	}

	if (bookCopy[12] != '#')
	{
		cout << "Copy Number must be append with Book ID using # sign!" << endl << endl;

		return false;
	}

	for (i = 13; i < MAX_COPY_NUMBER - 1; i++)
	{
		if (!isdigit(bookCopy[i]))
		{
			cout << "Invalid Copy Number, it must be a number!" << endl << endl;

			return false;
		}
	}

	return true;
}

bool isValidCategoryName(char bookCategory[])
{
	for (int i = 0; i < MAX_CATEGORY_NAME; i++)
	{
		if (!isalpha(bookCategory[i]) && bookCategory[i] != 0)
		{
			cout << "Category Name can only be an Alphabet!" << endl << endl;

			return false;
		}
	}

	return true;
}

bool isValidCategoryNumber(char bookCategory[])
{
	for (int i = 0; i < MAX_CATEGORY_NUMBER - 1; i++)
	{
		if (!isdigit(bookCategory[i]))
		{
			cout << "Book Category can only be a number!" << endl << endl;

			cout << bookCategory[i] << " at " << i << "th place is inValid!" << endl;

			return false;
		}
	}

	return true;
}
bool isValidRegistrationNo(char regNo[12])
{	bool Valid=true;
	int x;
	int i=0,j=0;
	while (regNo[j]!='\0')
		{

			if ( j<=3)
				{
					if (regNo[j]>='0' && regNo[j]<='9')
						Valid=true;
					else
						Valid=false;
				}
			if ( (j>=5 ) && ( j<=6))
				{
					if (regNo[j]>='A'&&regNo[j]<='Z')
						Valid=true;
					else
						Valid=false;

				}

			if((j>=8 ) && ( j<=10))
				{
					if(regNo[j]>='0' && regNo[j]<='9')
						Valid=true;
					else
						Valid=false;

				}

			if(regNo[4]!='-')
				Valid=false;
			if (regNo[7]!='-')
				Valid=false;
			j++;
		}

	if (Valid==false)
		cout<<" NOT VALID";
	else
		cout<<"VALID ";

	return Valid;

}
bool isValidDate(Date date) 
{
	bool dateValid=true;
	int x;
	
for(int i ; i<11;i++)
	{
	
		
					if ( date.Day>=1 && date.Day<=31 )
						dateValid=true;
					else
						dateValid=false;
	   
			
		if( i==2 )
		{
				cout<<"-";
	    }
		
	
					if ( date.Month>=1 && date.Month<=12 )
						dateValid=true;
					else
						dateValid=false;
	   		
			if(i==5 )
		{
				cout<<"-";
	    }		
		
	
					if ( (date.Year>=1900 ) && ( date.Year<=2020))
				
					
						dateValid=true;
					else
						dateValid=false;
	
	     
         	if ( date.Month==2 && date.Day<=29 )
						dateValid=true;
					else
						dateValid=false;
     }
			
		

	if (dateValid==false)
		cout<<" Date NOT VALID";
	else
		cout<<"VALID Date ";

	return dateValid;

}
bool isValidStudentName(char stdName[60]) 
{
		int i=0;
	bool namevalid=true;




	for(int i=0 ; i<60 ; i++)
		{
			if(!isalpha(stdName[i]))
				namevalid=false;
		}

	i++;

	if(namevalid=false)
		cout<<"NAME NOT VALID";
	else
		cout<<"NAME VALID";

	return namevalid;}


bool isValidLoginId(char userName[])
{
	bool login = false;

	for (int i = 0; i < MAX_USER_NAME; i++)
	{
		if (((userName[i] > 0) && (userName[i] <= 45) || (userName[i] == 47)) || ((userName[i] >= 58) && (userName[i] <= 63)) || ((userName[i] >= 91) && (userName[i] <= 96)) || ((userName[i] >= 123) && (userName[i] <= 127)))
		{
	
			return false;
		}

		if (userName[i] == 64)
		{
			login = true;
		}
	}

	if (login)
	{
		return true;
	}
	else
	{
		cout << "Invalid Username! " << endl << endl;

		return false;
	}
}


	
bool isExist(Category arr[], int arraySize, char catId[]) 
{bool x=false;
	for (int i = 0; i < MAX_CATEGORIES; i++)
	{
		if(!strcmp(arr[i].Id,catId))
		
	{
		x=false;
		break;
		}
		
		else 
	{
	     x=true;
		continue;}
		
}
return true;
}

 void readInCategory(Category& category)
 {
 
				
					cin.ignore();

					for (int i = 0; i < MAX_CATEGORY_NUMBER; i++)
					{
						cin.get(category.Id[i]);
					}

					for (int i = 0; i < MAX_CATEGORY_NAME; i++)
					{
						if (cin.peek() == '\n')
						{
							break;
						}

						cin.get(category.Name[i]);	
                    }
 }
 
bool addCategory(Category arr[], int arraySize, Category newCategory) 
{
	bool isAdded = false;
	char  compare[MAX_CATEGORY_NUMBER]={0};

	for (int i = 0; i < MAX_CATEGORIES; i++)
	{
	if(!strcmp(arr[i].Id,compare))
			{
				strcpy(arr[i].Id , newCategory.Id);

				isAdded = true;
			}

		

		if (isAdded==true)
		{
			
		strcpy(arr[i].Name , newCategory.Name);
		cout << "\nCategory Added Successfully!"  << endl;
	
		return true;
		}
	}

	cout << "\nThere was an error!" << endl << endl;

	return false;
}
 bool editCategory(Category arr[], int arraySize, char catId[MAX_CATEGORIES], Category newData) 
{
	bool isUpdated = false;

	for (int i = 0; i < MAX_CATEGORIES; i++)
	{
	
		if( (!strcmp(arr[0].Id , catId)) &&  (!strcmp(arr[1].Id , catId))  && (!strcmp(arr[1].Id , catId)) )
		{
			
	        	strcpy(arr[i].Id , newData.Id);

			isUpdated = true;
		}
	
		if (isUpdated)
		{	strcpy(arr[i].Name , newData.Name);
			

			break;
		}
	}

	cout << "\nCategory has been updated successfully!" << endl << endl;

	return true;
}
bool deleteCategory(Category arr[], int arraySize, char catId[MAX_CATEGORIES]) 
{
	bool isDeleted = false;

	for (int i = 0; i < MAX_CATEGORIES; i++)
	{	
	if( (!strcmp(arr[0].Id , catId)) &&  (!strcmp(arr[1].Id , catId))  && (!strcmp(arr[1].Id , catId)) )
	{
		strcpy(arr[i].Id , 0);
			

			isDeleted = true;
		}
		else if (i == MAX_CATEGORIES - 1)
		{
			cout << "\nThere was an error while deleting the Category!" << endl << endl;

			return false;
		}

		if (isDeleted)
		{
		
			{	
			strcpy(arr[i].Name , 0);
			}

			break;
		}
	}

	cout << "\nCategory has been deleted Successfully!" << endl << endl;

	return true;
}
void printCategories(Category arr[], int arraySize)
{
	cout << "\tCATEGORY ID\tNAME" << endl << endl;

	for (int i = 0; i < MAX_CATEGORIES; i++)
	{
		cout << "\t";


			cout << arr[i].Id;
		

		cout << "\t\t";

		
			if ( !strcmp(arr[i].Name , 0))
			{
				break;
			}

			cout << arr[i].Name;
		}

		cout << endl;

}
bool saveCategories(Category arr[], int arraySize) 

{
	ofstream saveCategories;

	saveCategories.open("categories.csv");

	for (int i = 0; i < MAX_CATEGORIES; i++)
	{
		
			saveCategories << arr[i].Id;
		

		saveCategories << " ";

		
			saveCategories << arr[i].Name;
		

		saveCategories << endl;
	}

	saveCategories.close();

	return true;
}
bool loadCategories(Category arr[], int arraySize) 
{
	ifstream loadCategories;

	loadCategories.open("loadcategories.csv");

	for (int i = 0; i < MAX_CATEGORIES; i++)
	{
	
			if (loadCategories.peek() == ' ')
			{
				break;
			}

			loadCategories >> arr[i].Id;
		

		
			loadCategories >>  arr[i].Name;
		
	}

	loadCategories.close();

	return true;
}

bool isExist(Book arr[], int arraySize, char bookId[])  
{bool flag=false;
	for (int i = 0; i < MAX_BOOKS; i++)
	{
		if(!strcmp(arr[i].Id,bookId))
		
		{
		flag=false;
		break;}
		else 
		{
		flag=true;
		continue;
}
}
return true;
}

void readInBook(Book& book)
 {
 
				
					if(book.Edition > 15)
					{	
						cout << "\n\nEditions can only be 15 or less!" << endl << endl;
					}
					
					for (int i = 0; i < MAX_BOOK_ID; i++)
					{
						cin.get(book.Id[i]);
					}

					cin >>book.Edition;

					for (int i = 0; i < MAX_BOOK_NAME; i++)
					{
						if (cin.peek() == '\n')
						{
							break;
						}

						cin.get(book.Name[i]);
					}

 }

bool addBook(Book arr[], int arraySize, Book newBook)
{
	bool isAdded = false;

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		if ((newBook.Id == arr[0].Id) && (newBook.Id == arr[1].Id) && (newBook.Id == arr[2].Id))
		{
		
			(strcpy(	arr[i].Id ,newBook.Id));
			

			isAdded = true;
		}
	

		if (isAdded)
		{
			arr[i].Edition =newBook.Edition;

			
			(strcpy(	arr[i].Name ,newBook.Name));
			

			break;
		}
	}

	cout << "\nBook Added Successfully!" << endl << endl;

	return true;
}

bool editBook(Book arr[], int arraySize, char bookId[MAX_BOOKS], Book newData) 
{
	bool isUpdated = false;
	int compared = 0;

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		compared = 0;

	
		

			if ((arr[i].Id != bookId))
			{
				break;
			}
			
			else
			{
				compared++;
			}
	

		if (compared == 12)
		{
			
			strcpy(	arr[i].Id , newData.Id);

				isUpdated = true;
		
		}

		if (isUpdated)
		{
			arr[i].Edition = newData.Edition;

		strcpy(	arr[i].Name ,newData.Name);
			

			break;
		}
	}

	cout << "Book has been updated successfully!" << endl << endl;

	return true;
}

bool deleteBook (Book arr[], int arraySize, char bookId[MAX_BOOKS]) 
{
	bool isDeleted = false;
	int compared;

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		compared = 0;

	
			 if (arr[i].Id != bookId)
			{
				break;
			}
			else
			{
				compared++;
			}
	

		if (compared == 12)
		{
				strcpy(arr[i].Id , 0);
				strcpy(arr[i].Name , 0);
				arr[i].Edition =0;
				isDeleted = true;
			
		}

	
	}
if(isDeleted==true)
	cout << "Book has been deleted Successfully!" << endl << endl;

	return true;
}

void printBooks(Book arr[], int arraySize)
{
	bool isPrinted = false;

	cout << "\tBOOKS ID\tNAME\t\t\tEDITIONS\t" << endl << endl;

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		isPrinted = false;
	
		cout << "\t";
		
		
			cout << arr[i].Id;
         	cout<<"\t";
	
			cout << arr[i].Name;
	
		if (isPrinted)
		{
			cout << "\t";
			cout << arr[i].Edition;
			cout << "\t";
		}

	

		cout << endl;
	}
}
bool saveBooks(Book arr[], int arraySize) 
{
	ofstream saveBooks;
	bool isSaved = false;

	saveBooks.open("savebooks.csv");

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		
			saveBooks << arr[i].Id;

			isSaved = true;
		

		if (isSaved == true)
		{
			saveBooks << " ";
			saveBooks << arr[i].Edition;
			saveBooks << " ";
		}

	
			saveBooks << arr[i].Name;
	

		saveBooks << endl;
	}

	saveBooks.close();
	
	return true;
}
bool loadBooks(Book arr[], int arraySize) 
{

	ifstream loadBooks;
	bool isLoaded = false;

	loadBooks.open("loadbook.csv");

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		
			if (loadBooks.peek() == ' ')
			{
				break;
			}

			loadBooks >> arr[i].Id;

			isLoaded = true;
		

		if (isLoaded)
		{
			int convert;

			loadBooks >> convert;

			arr[i].Edition = convert;
		}

		loadBooks >> arr[i].Name;
		
	}

	loadBooks.close();

	return true;
}

bool isExist(BookCopy arr[], int arraySize, char copyId[]) 
{
bool flag=false;
	for (int i = 0; i < MAX_BOOKS; i++)
	{
		if(!strcmp(arr[i].Id,copyId))
		{
		
		flag=false;
		break;}
		else 
	{
		flag=true;
		continue;}
		
}
return true;	
}

void  readInBookCopy(BookCopy  &bookCopy)
 {
 
				
							for (int i = 0; i < MAX_COPY_NUMBER; i++)
					{
						cin.get(bookCopy.Id[i]);
					}

					for (int i = 0; i < DATE_SIZE; i++)
					{
						if (cin.peek() == '\n')
						{
							break;
						}

						cin>>bookCopy.PurchaseDate.Day;
							cin>>bookCopy.PurchaseDate.Month;
								cin>>bookCopy.PurchaseDate.Year;
					    
					}

			
 }

bool addBookCopy(BookCopy arr[], int arraySize, BookCopy newBookCopy) 
{
	bool isAdded = false;
	int compared = 0;

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		compared = 0;

			

			if ((arr[i].Id != newBookCopy.Id))
			{
				break;
			}
			else
			{
				compared++;
			}
		

		if (compared == 12)
		{
			
				strcpy(	arr[i].Id , newBookCopy.Id);

				isAdded = true;
		
		}

		if (isAdded==true)
		{
		arr[i].PurchaseDate.Day = newBookCopy.PurchaseDate.Day;
			arr[i].PurchaseDate.Month =newBookCopy.PurchaseDate.Month;
		arr[i].PurchaseDate.Year= newBookCopy.PurchaseDate.Year;
       	break;
		}
	}

	cout << "Book Copy Added Successfully!" <<  endl;

	return true;
}

bool deleteBookCopy(BookCopy arr[], int arraySize, char bookCopyId[]) 
{
	bool isDeleted = false;
	int compared = 0;

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		compared = 0;

		if (i == MAX_BOOKS - 1)
			{
				cout << "\nThere was no such Book ID found!" << endl << endl;

				return false;
			}

			if ((arr[i].Id != bookCopyId))
			{
				break;
			}
			else
			{
				compared++;
			}
		

		if (compared == 17)
		{
			
			strcpy(arr[i].Id , 0);

				isDeleted = true;
	
		}

		if (isDeleted)
		{
				arr[i].PurchaseDate.Day = 0;
			arr[i].PurchaseDate.Month =0;
		arr[i].PurchaseDate.Year= 0;
			
		

			break;
		}
	}

	return true;
}

bool editBookCopy(BookCopy arr[], int arraySize, char bookCopyId[], BookCopy newData)
{
	bool isUpdated = false;
	int compared = 0;

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		compared = 0;

		
			if (i == MAX_BOOKS - 1)
			{
				cout << "\nThere was no such Book ID found!" << endl << endl;

				return false;
			}

			if (arr[i].Id != bookCopyId)
			{
				break;
			}
			else
			{
				compared++;
         	}

		cout << "Compared charaters are: " << compared << endl;

		if (compared == 16)
		{
			strcpy(arr[i].Id , newData.Id);

				isUpdated = true;
			
		}

		if (isUpdated)
		{
		arr[i].PurchaseDate.Day = newData.PurchaseDate.Day;
			arr[i].PurchaseDate.Month =newData.PurchaseDate.Month;
		arr[i].PurchaseDate.Year= newData.PurchaseDate.Year;
	
			

			break;
		}
	}

	return true;
}

void printBookCopies(BookCopy arr[], int arraySize, char bookId[]) 
{
	int compared = 0;

	cout << "\tCOPY ID\t\t\tPURCHASE DATE" << endl << endl;

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		compared = 0;

	
			if (arr[i].Id != bookId)
			{
				break;
			}
			else
			{
				compared++;
			}
		

		if (compared == 12)
		{
			cout << "\t";

			
				cout << arr[i].Id;
			

			cout << "\t\t";

			cout<<arr[i].PurchaseDate.Day<<arr[i].PurchaseDate.Month<<arr[i].PurchaseDate.Year;
			
		}

		cout << endl;
	}
}
bool saveBookCopies(BookCopy arr[], int arraySize) 
{
	ofstream saveSamples;

	saveSamples.open("savebookcopy.csv");

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		
			saveSamples << arr[i].Id;
		

		saveSamples << " ";


			saveSamples <<arr[i].PurchaseDate.Day<<arr[i].PurchaseDate.Month<<arr[i].PurchaseDate.Year;
		
		saveSamples << endl;
	}

	saveSamples.close();

	return true;
}

bool LoadBookSamples(char CopyId[][MAX_COPY_NUMBER], char PublishedDates[][DATE_SIZE], int ArraySize, char fileName[])
{
	ifstream loadsamples;

	loadsamples.open(fileName);

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		for (int j = 0; j < MAX_COPY_NUMBER; j++)
		{
			if (loadsamples.peek() == 32)
			{
				break;
			}

			loadsamples >> CopyId[i][j];
		}

		for (int j = 0; j < DATE_SIZE; j++)
		{
			loadsamples >> PublishedDates[i][j];
		}
	}

	loadsamples.close();

	return true;
}

bool isExist(Student arr[], int arraySize, char regNo[]) 
{
bool flag=false;
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if(!strcmp(arr[i].RegistrationNo ,regNo))
		
		{
		flag=false;
		break;}
		else 
		{
		flag=true;
		continue;
	}
}
return true;	
}
void readInStudent(Student& student) 
 {
 
				
				
					
					for (int i = 0; i < MAX_REGISTRATION_NUMBER; i++)
					{
						cin.get(student.RegistrationNo[i]);
					}

					cin >>student.Session;

					for (int i = 0; i < MAX_STUDENT_NAME; i++)
					{
						if (cin.peek() == '\n')
						{
							break;
						}

						cin.get(student.Name[i]);
					}

 }

bool addStudent(Student arr[], int arraySize, Student newStudent) 
 {
	bool isAdded = false;

	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if ((!strcmp(newStudent.RegistrationNo , arr[0].RegistrationNo)) && (!strcmp(newStudent.RegistrationNo ,arr[1].RegistrationNo)) && (!strcmp(newStudent.RegistrationNo , arr[2].RegistrationNo)))
		{
		
			(strcpy(	arr[i].RegistrationNo ,newStudent.RegistrationNo));
			

			isAdded = true;
		}
	

		if (isAdded)
		{
			arr[i].Session  =newStudent.Session ;

			
			(strcpy(arr[i].Name ,newStudent.Name));
			

			break;
		}
	}

	cout << "\nBook Added Successfully!" << endl << endl;

	return true;
}

bool editStudent(Student arr[], int arraySize, char regNo[], Student newData) 
 {
	bool isUpdated = false;
	int compared = 0;

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		compared = 0;

			if ((arr[i].RegistrationNo != regNo))
			{
				break;
			}
			
			else
			{
				compared++;
			}
	

		if (compared == 12)
		{
			
			strcpy(	arr[i].RegistrationNo , newData.RegistrationNo);

				isUpdated = true;
		
		}

		if (isUpdated)
		{
			arr[i].Session = newData.Session;

		strcpy(	arr[i].Name ,newData.Name);
			

			break;
		}
	}

	cout << "Book has been updated successfully!" << endl << endl;

	return true;
}
bool deleteStudent (Student arr[], int arraySize, char regNo[]) 
{
	bool isDeleted = false;
	int compared;

	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		compared = 0;

	
			 if (arr[i].RegistrationNo != regNo)
			{
				break;
			}
			else
			{
				compared++;
			}
	

		if (compared == 12)
		{
				strcpy(arr[i].RegistrationNo , 0);
				strcpy(arr[i].Name , 0);
				arr[i].Session =0;
				isDeleted = true;
			
		}

	
	}
if(isDeleted==true)
	cout << "Book has been deleted Successfully!" << endl << endl;

	return true;
}
bool saveStudents(Student arr[], int arraySize) 
 
{
	ofstream saveStudents;
	bool isSaved = false;

	saveStudents.open("saveStudents.csv");

	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		
			saveStudents << arr[i].RegistrationNo;

			isSaved = true;
		

		if (isSaved == true)
		{
			saveStudents << " ";
			saveStudents << arr[i].Session;
			saveStudents << " ";
		}

	
			saveStudents << arr[i].Name;
	

		saveStudents << endl;
	}

	saveStudents.close();
	
	return true;
}
bool loadStudents(Student arr[], int arraySize) 

{

	ifstream loadStudents;
	bool isLoaded = false;

	loadStudents.open("loadstudents.csv");

	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		
			if (loadStudents.peek() == ' ')
			{
				break;
			}

			loadStudents >> arr[i].RegistrationNo;

			isLoaded = true;
		

		if (isLoaded)
		{
			int convert;

			loadStudents >> convert;

			arr[i].Session = convert;
		}

		loadStudents >> arr[i].Name;
		
	}

	loadStudents.close();

	return true;
}

void printStudents(Student arr[], int arraySize) 
{
	bool isPrinted = false;

	cout << "\tBOOKS ID\tNAME\t\t\tEDITIONS\t" << endl << endl;

	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		isPrinted = false;
	
		cout << "\t";
		
		
			cout << arr[i].RegistrationNo;
         	cout<<"\t";
	
			cout << arr[i].Name;
	
		if (isPrinted)
		{
			cout << "\t";
			cout << arr[i].Session;
			cout << "\t";
		}

		cout << endl;
	}
}

bool issueBook(BookIssue arr[], int size, BookIssue toIssue) 
{	bool issue = false;
	
	 int compared;
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if ((!strcmp(toIssue.regNo , arr[0].regNo)) && (!strcmp(toIssue.regNo ,arr[1].regNo)) && (!strcmp(toIssue.regNo , arr[2].regNo)))
		{
		
			(strcpy(	arr[i].regNo ,toIssue.regNo));
			

			issue = true;
		}
		if (issue)
		{

		compared = 0;

			

			if ((arr[i].bookCopyId != toIssue.bookCopyId))
			{
				break;
			}
			else
			{
				compared++;
			}
		

		if (compared == 12)
		{
			
				strcpy(	arr[i].bookCopyId , toIssue.bookCopyId);

				issue= true;
		
		}

	}

	cout << "\nBook has been issued to " << arr[i].regNo << endl;
   toIssue.status=Issued;}
   
	return true;
	
}

void checkBookstatus(BookIssue booksIssued[], BookCopy bookCopies[], int IssueSize, int bookCopySize, char copyId[])
{
	for (int i = 0; i < MAX_BOOKS; i++)
	{
		if (!strcmp(booksIssued[i].bookCopyId, copyId))
		{
			if (booksIssued[i].status == Issued)
			{
				cout << "Book is currently issued to " << booksIssued[i].regNo << endl << endl;
			}
			else
			{
				cout << "\nBook Copy is Available!" << endl << endl;
			}
		}
		else
		{
			cout << "\nBook Copy is Available!" << endl << endl;
		}
	}
}

void studentCurrentBook(BookIssue arr[], int size, char regNo[])
{
	bool isStudent = false;

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		if (!strcmp(arr[i].regNo, regNo))
		{
			cout << arr[i].regNo << " has book " << arr[i].bookCopyId << endl;
		}
	}
}

int returnBook(BookIssue arr[], int size, char copyIdtoReturn[])
{
	

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		if (!strcmp(arr[i].bookCopyId, copyIdtoReturn))
		{
			if (((arr[i].issueDate.Day - arr[i].issueDate.Month) > 14))
			{
				cout << "Student " << arr[i].regNo << " has returned the Book with late return fine of " << (((arr[i].issueDate.Day - arr[i].issueDate.Month) - 14) * 10) << " Rs." << endl << endl;

				return (((arr[i].issueDate.Day- arr[i].issueDate.Month) - 14) * 10);
			}
		}
		else
		{
			cout << "Student " << arr[i].regNo << " has returned the book without any Fine!" << endl << endl;

			return 0;
		}
	}
}

void saveBookIssue(BookIssue arr[], int size)
{
	ofstream saveIssued;

	saveIssued.open("bookhistory.csv");

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		saveIssued << arr[i].bookCopyId << "," << arr[i].regNo << "," << arr[i].status << ",";
		saveIssued << arr[i].issueDate.Day << "-" << arr[i].issueDate.Month << "-" << arr[i].issueDate.Year << endl;
	}

	saveIssued.close();
}

void loadBookIssue(BookIssue arr[], int size)
{
	ifstream loadIssued;

	loadIssued.open("bookhistory.csv");

	for (int i = 0; i < MAX_BOOKS; i++)
	{
		int getStatus = 0;
		int getMonth = 0;

		loadIssued.getline(arr[i].bookCopyId, MAX_COPY_NUMBER, ',');
		loadIssued.getline(arr[i].regNo, MAX_REGISTRATION_NUMBER, ',');
		
		loadIssued >> getStatus;
		loadIssued >> arr[i].issueDate.Day;
		loadIssued.ignore(1, '-');
		loadIssued >> getMonth;
		loadIssued.ignore(1, '-');
		loadIssued >> arr[i].issueDate.Year;

		arr[i].issueDate.Month = getMonth;
	}
}

void printMenu()
{
cout<<" Choose the following option"<<endl;
cout<<" 1 Category Management(A,E,L,D)"<<endl;
cout<<" 2 Books Management(A,E,L,D)"<<endl;
 cout<<"3 Book Copies Management(A,E,L,D) "<<endl;
 cout<<"4 Student Management(A,E,L,D)"<<endl;
 cout<<"5 Book Issue Management(I,R,S,B)"<<endl;
 cout<<"9 Logout(9L)"<<endl;
 cout<< "0  Exit Program(0E)  "<<endl;
}

void TakeMenuInput(int& mainOption, char& subOption)
{
	while (true)
	{
		cout << "Choose the Option: ";
		cin >> mainOption;
		cin.get(subOption);

		if (((mainOption == 1)|| (mainOption == 5)||(mainOption ==4 ) || (mainOption == 2) || (mainOption == 3) || (mainOption == 0)) && ((subOption == 'A') ||(subOption == 'I') ||(subOption == 'R') ||(subOption == 'S') ||(subOption == 'B') || (subOption == 'E') || (subOption == 'L') || (subOption == 'D')))
		{
			break;
		}
		else
		{
			cout << "Please choose a Valid a Option!" << endl;

			cin.ignore();
		}
	}
}
int main()
{
	int mainOption , edition = 0;
	char subOption;
 int arraySize;
	Category catarr[MAX_CATEGORIES];
Book bookarr[MAX_BOOKS];
BookCopy bookcopyarr[MAX_BOOKS];
Student studentarr[MAX_STUDENTS];
	cout << "\n\n** Welcome to University Library Management System **" << endl << endl;

User toFind;	
User arr[SIZE];
bool r;
loadUser( arr,  SIZE);
for (int i=0;i<SIZE;i++)
	{
		cout<<arr[i].userName;
		cout<<arr[i].password;
	}
cout<<"Enter the username= ";
cin>>toFind.userName;
cout<<"Enter the password= ";
cin>>toFind.password;
r=findUser( arr,SIZE,toFind);
if (r==true)
{cout<<"You have been successfully logged in to the system";
cout<<endl;

	while (true)
	{
		printMenu();
		TakeMenuInput(mainOption, subOption);

		if (mainOption == 0)
		{
			if (subOption == 'E')
			{
			

				cout << "\n\nSaveing Categories: ";
				cin.ignore();
			
		saveCategories( catarr,  arraySize) ;
		
				cout << "\n\nSaveing Books: ";
			
				saveBooks( bookarr, arraySize) ;

				cout << "\n\n Saveing Book Samples: ";
			
			 saveBookCopies( bookcopyarr,  arraySize ); 
		
				cout << "\n\n Saveing Students: ";
			
			 saveStudents(studentarr, arraySize); 
		
				break;
			}
		}
		else if (mainOption == 1)
		{
			if (subOption == 'A')
			{
				Category newCategory={0};
				
				do
				{	cout << "\nEnter the details of Category (ID and Name) : ";

					 readInCategory( newCategory);
					 
					 
					 
				} while ((!isValidCategoryNumber(newCategory.Id)) && (!isValidCategoryName(newCategory.Name)));

				 addCategory( catarr,  arraySize,  newCategory) ;
			}
			
			else if (subOption == 'D')
			{     char catId[MAX_CATEGORIES];
			Category arr;

				do
				{
					cout << "\nEnter the Category ID to delete: ";

					
						cin>>catId;
					

				} while (!isValidCategoryNumber(catId));

			 deleteCategory(catarr, arraySize, catId) ;
			}
			else if (subOption == 'L')
			{
				printBooks(bookarr, arraySize);
					}
					
			else if (subOption == 'E')
			{
				Category newData={0};
              char catId[MAX_CATEGORIES]={0};
				do
				{
					cout << "\nEnter Category ID to edit: ";

					cin.ignore();

					for (int i = 0; i < MAX_CATEGORY_NUMBER; i++)
					{
						if (cin.peek() == '\n')
						{
							break;
						}

						cin.get(catId[i]);
					}

				} while (!isValidCategoryNumber(catId));

				do
				{
					cout << "\nEnter the new details of the Category: ";
                    readInCategory( newData);
					 
					

				} while (!isValidCategoryNumber(newData.Id) || !isValidCategoryName(newData.Name));

				editCategory(catarr,arraySize,  catId, newData) ;
					}
		}
		else if (mainOption == 2)
		{
			if (subOption == 'A')
			{
		 Book newBook={0};

				do
				{
					cout << "\nEnter the details of the Book (ID, Edition, Name): ";
					
					readInBook(newBook);
					
					
				} while (!isValidBookId(newBook.Id) || !isValidbookName(newBook.Name) || newBook.Edition > 15);

			addBook( bookarr,  arraySize,  newBook);
					}
			else if (subOption == 'E')
			{  
			 char bookId[MAX_BOOKS];
			  Book newData;
			 Book newBook={0};
				

				do
				{
					cout << "\nEnter Book ID to Edit: ";

					cin.ignore();

					for (int i = 0; i < MAX_BOOK_ID; i++)
					{
						cin.get(bookId[i]);
					}

				} while (!isValidBookId(bookId));

				do
				{
					cout << "Enter the new details of the book: ";

					 readInBook(newData);
					 
					 
				} while (!isValidBookId(newData.Id) || !isValidbookName(newData.Name));
                editBook( bookarr,  arraySize,  bookId,  newData);
				}
			else if (subOption == 'D')
			{char bookId[MAX_BOOKS]={0};
			
				do
				{
					cout << "Enter Book ID to delete: ";

					cin.ignore();

					for (int i = 0; i < MAX_BOOKS; i++)
					{
						cin.get(bookId[i]);
					}

				} while (!isValidBookId(bookId));
               deleteBook ( bookarr, arraySize,  bookId) ;
				
			}
			else if (subOption == 'L')
			{
			printBooks(bookarr, arraySize);
			}
		}
		else if (mainOption == 3)
		{
			if (subOption == 'A')
			{
		
                BookCopy newBookCopy={0};
			
				do
				{
					cout << "Enter the details of the Sample(ID, DATE OF PURCHASE): ";
                 readInBookCopy( newBookCopy) ;
					
			} while (!isValidCopyNumber(newBookCopy.Id));

			addBookCopy( bookcopyarr, arraySize, newBookCopy);
				}
			else if (subOption == 'E')
			{char bookCopyId[MAX_COPY_NUMBER]={0};
					char newCopyId[MAX_COPY_NUMBER] = { 0 };
				char newPublishDate[DATE_SIZE] = { 0 };
                BookCopy newData={0};
				do
				{
					cout << "Enter the Book Copy to Edit: ";

					for (int i = 0; i < MAX_COPY_NUMBER - 1; i++)
					{
						cin.get(bookCopyId[i]);
					}

				} while (!isValidCopyNumber(bookCopyId));

				do
				{
					cout << "\nEnter the new details of the book copy: ";
                    readInBookCopy( newData) ;
				} while (!isValidCopyNumber(newCopyId));
 
				editBookCopy( bookcopyarr, arraySize,  bookCopyId,  newData);
						}
			else if (subOption == 'L')
			{
				char bookId[MAX_BOOK_ID] = { 0 };

				do
				{
					cout << "Enter the book ID for details: ";

					cin.ignore();

					for (int i = 0; i < MAX_BOOK_ID; i++)
					{
						cin.get(bookId[i]);
					}

				} while (!isValidBookId(bookId));

			 printBookCopies(bookcopyarr, arraySize, bookId) ;
			}
			else if (subOption == 'D')
			{
				char bookCopyId[MAX_COPY_NUMBER] = { 0 };

				do
				{
					cout << "Enter the Book Sample ID to delete: ";

					cin.ignore();

					for (int i = 0; i < MAX_COPY_NUMBER; i++)
					{
						cin.get(bookCopyId[i]);
					}

				} while (!isValidCopyNumber(bookCopyId));
              
			   deleteBookCopy(bookcopyarr, arraySize,bookCopyId);
				
			}
		}
			else if (mainOption == 4)
		{
			if (subOption == 'A')
			{
		Student newStudent={0};

				do
				{
					cout << "\nEnter the details of the Book (ID, Edition, Name): ";
					readInStudent(newStudent);
					
					
				} while (!isValidBookId(newStudent.RegistrationNo) || !isValidbookName(newStudent.Name) || newStudent.Session > 15);
            addStudent( studentarr,  arraySize,  newStudent);
					}
			else if (subOption == 'E')
			{  
			 char regNo[MAX_REGISTRATION_NUMBER];
			  Student newData;
			 Book newBook={0};
				

				do
				{
					cout << "\nEnter Book ID to Edit: ";

					cin.ignore();

					for (int i = 0; i < MAX_REGISTRATION_NUMBER; i++)
					{
						cin.get(regNo[i]);
					}

				} while (!isValidRegistrationNo(regNo));

				do
				{
					cout << "Enter the new details of the book: ";

					 readInStudent(newData);
					 
					 
				} while (!isValidRegistrationNo(newData.RegistrationNo) || !isValidStudentName(newData.Name));
               
			editStudent(studentarr, arraySize, regNo, newData) ;
				}
			else if (subOption == 'D')
			{char regNo[MAX_REGISTRATION_NUMBER]={0};
			
				do
				{
					cout << "Enter Book ID to delete: ";

					cin.ignore();

					for (int i = 0; i < MAX_REGISTRATION_NUMBER; i++)
					{
						cin.get(regNo[i]);
					}

				} while (!isValidRegistrationNo(regNo));
               	deleteStudent ( studentarr, arraySize, regNo);
			}
			else if (subOption == 'L')
			{
			printStudents( studentarr, arraySize) ;
			}
		}
		else if (mainOption == 5)
				{	BookIssue booksIssued[MAX_BOOKS];
					BookCopy bookCopies[MAX_BOOKS];
						Student students[MAX_STUDENTS];
					for (int i = 0; i < MAX_BOOKS; i++)
					{
						strcpy(booksIssued[i].bookCopyId, bookCopies[i].Id);
					}
					
					if (subOption == 'I')
					{
						BookIssue Book;

						do
						{
							cout << "\nEnter Registration No: ";

							cin.getline(Book.regNo, MAX_REGISTRATION_NUMBER, '\n');

						} while ((!isValidRegistrationNo(Book.regNo)) && (!isExist(students, arraySize, Book.regNo)));

						do
						{
							cout << "\nEnter Book ID to be Issued: " << endl << endl;

							cin.getline(Book.bookCopyId, MAX_BOOK_ID);

						} while ((!isValidBookId(Book.bookCopyId)) && (!isExist(bookCopies, arraySize, Book.bookCopyId)));

						if (Book.status != Issued)
						{
							issueBook(booksIssued, arraySize, Book);
						}
						else
						{
							checkBookstatus(booksIssued, bookCopies, arraySize, arraySize, Book.bookCopyId);
						}
					}
					else if (subOption == 'R')
					{
						char copyIdtoReturn[MAX_COPY_NUMBER] = { 0 };

						do
						{
							cout << "\nEnter Book Copy Number to return: ";

							cin.getline(copyIdtoReturn, MAX_COPY_NUMBER);

						} while ((!isValidCopyNumber(copyIdtoReturn)) || (!isExist(bookCopies, arraySize, copyIdtoReturn)));

						returnBook(booksIssued, arraySize, copyIdtoReturn);
					}
					else if(subOption == 'S')
					{
						char regNo[MAX_REGISTRATION_NUMBER] = { 0 };

						do
						{
							cout << "\nEnter Registration No of Student: ";

							cin.getline(regNo, MAX_REGISTRATION_NUMBER, '\n');

						} while ((!isValidRegistrationNo(regNo)) && (!isExist(students, arraySize, regNo)));

						studentCurrentBook(booksIssued, arraySize, regNo);
					}
					else if (subOption == 'B')
					{
						char copyId[MAX_COPY_NUMBER] = { 0 };

						do
						{
							cout << "\nEnter Copy ID of the Book: ";

							cin.getline(copyId, MAX_COPY_NUMBER);

						} while ((!isValidCopyNumber(copyId)) || (!isExist(bookCopies, arraySize, copyId)));

						checkBookstatus(booksIssued, bookCopies, arraySize, arraySize, copyId);
					}
				}
	}
}

else
{cout<<"You are not a registred user ";
}

}

