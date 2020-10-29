#include<iostream.h>          //opening headerfile iostream for in-out
#include<conio.h>             //opening headerfile conio for clrscr();
#include<stdlib.h>            //opening headerfile stdlib for 
random(int);
char tic[3][3];               //global matrix declerations
int d,e,f,a,t,i,j,x,y;        //global variables declerations
void display();               //displays the matrix
void user();                  //function for user's move
void newdisp();               //function for display of matrix after 
every
move
void pc();                    //function for pc's move
int check();                  //function for finding out the winner
int horcheck();               //function for horizontal line check
int vercheck();               //function for vertical line check
int diagcheck();              //function for diagonal line check
main()                        //main function
{
clrscr();                     //clears the previous output screen
randomize();                  //initialize random function calling
int d=random(2);              //random function call
for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	tic[i][j]=' ';        //assigning space ' ' to all elements of matrix
display();                    //display function call
d==0?user():pc();             //random starting of the game depending 
on d
getch();                      //provides output by getting input 
without
returning to program
return 0;                     //return int to main function
}
void display()                //display function definition
{
for(t=0;t<3;t++)
	{
	cout<<"		"<<tic[t][0]<<" | "<<tic[t][1]<<" | "<<tic[t][2]<<endl;
//figure formation
	if(t!=2)
	cout<<"		--|---|--"<<endl;
	}
}
void user()                  //user function definition
{
cout<<"		

ENTER THE CO-ORDINATES WHERE YOU WANT TO PUT UR 'X' i.e
0,1,2
";
cin>>x>>y;
if((x<0)||(x>2)&&(y<0)||(y>2))  //check for valid co-ordinates
	{
	cout<<"		

ENTER THE CORRECT CO-ORDINATES";
	user();    //user function call
	}
else
	{
	if(tic[x][y]==' ')    //check for vacant space at entered co-ordinates
		{
		tic[x][y]='X';  //assigning user 'X' to the co-ordinates
		newdisp();    //newdisp function call
		}
	else
		{
		cout<<"		

THIS POSITION IS ALREADY FILLED. CHOOSE SOME OTHER
CO-ORDINATES";
		user();       //user function call
		}
	}
d=check();            //check function call
if(d==0)
pc();                 //pc function call
else
	{
	cout<<"		

YOU ARE THE WINNER";
	getche();     //requires enter to return to program. prevents return
without display
	exit(1);      //program termination
	}
}
void newdisp()        //newdisp function definition
{
for(t=0;t<3;t++)
	{
	cout<<"		"<<tic[t][0]<<" | "<<tic[t][1]<<" | "<<tic[t][2]<<endl;
//displays new tictactoe after user or pc turn
	if(t!=2)
	cout<<"		--|---|--"<<endl;
	}
}
void pc()          //pc function call
{
int f,z;
randomize();       //initialize random function calling
cout<<"		

THIS IS THE COMPUTER'S MOVE 

";
for(i=0;i<=20;i++)
	{
	f=random(3);
	z=random(3);
	if(tic[f][z]==' ')      //check for vacant space at entered 
co-ordinates
		{
		tic[f][z]='O';  //assigning pc 'O' to the co-ordinates
		goto x;         //exiting for loop to display new tictactoe
		}
	else
	continue;               //
	}
x:newdisp();                    //newdisp function call
d=check();                      //check function call
if(d==0)
user();                         //user function call
else
	{
	cout<<"		

I'M THE WINNER";
	getche();           //requires enter to return to program. prevents
return without display
	exit(1);            //program termination
	}
}
check()                     //check function definition
{
horcheck();                 //horcheck function call
vercheck();                 //vercheck function call
diagcheck();                //diagcheck function call
return (d||e||f);
}
horcheck()                  //horcheck function definition
{
if(((tic[0][0]==tic[0][1])&&(tic[0][1]==tic[0][2])&&(tic[0][1]!='
'))||((tic[1][0]==tic[1][1])&&(tic[1][1]==tic[1][2])&&(tic[1][1]!='
'))||((tic[2][0]==tic[2][1])&&(tic[2][1]==tic[2][2])&&(tic[2][2]!=' 
')))
d=1;                        //checks each element of a horizontal line 
to
be same
else                        //returns 1 if all 3 elements of any
horizontal line are same
d=0;                        //else returns 0
return d;
}
vercheck()                  //vercheck function definition
{
if(((tic[0][0]==tic[1][0])&&(tic[1][0]==tic[2][0])&&(tic[0][0]!='
'))||((tic[0][1]==tic[1][1])&&(tic[1][1]==tic[2][1])&&(tic[0][1]!='
'))||((tic[0][2]==tic[1][2])&&(tic[1][2]==tic[2][2])&&(tic[0][2]!=' 
')))
e=1;                        //checks each element of a vertical line to 
be
same
else                        //returns 1 if all 3 elements of any 
vertical
line are same
e=0;                        //else returns 0
return e;
}
diagcheck()                 //diagcheck function definition
{
if(((tic[0][0]==tic[1][1])&&(tic[1][1]==tic[2][2])&&(tic[0][0]!='
'))||((tic[0][2]==tic[1][1])&&(tic[1][1]==tic[2][0])&&(tic[1][1]!=' 
')))
f=1;                        //checks each element of a diagonal line to 
be
same
else                        //returns 1 if all 3 elements of any 
diagonal
line are same
f=0;                        //else returns 0
return f;
}
