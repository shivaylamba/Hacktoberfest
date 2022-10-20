/* Tower of Hanoi using recursion (C++ program)
Implementation of Tower of HANOI in using C++ program, Learn: What is Tower of Hanoi? How to implement using recursion in C++?
Submitted by Abhishek Jain, on July 23, 2017

The Tower of Hanoi is a mathematical puzzle invented by the French mathematician Edouard Lucas in 1883.

There are three pegs, source(A), Auxiliary (B) and Destination(C). Peg A contains a set of disks stacked to resemble a tower, with the largest disk at the bottom and the smallest disk at the top. figure 1 Illustrate the initial configuration of the pegs for 3 disks. The objective is to transfer the entire tower of disks in peg A to peg C maintaining the same order of the disks.

Obeying the following rules:

Only one disk can be transfer at a time.
Each move consists of taking the upper disk from one of the peg and placing it on the top of another peg i.e. a disk can only be moved if it is the uppermost disk of the peg.
Never a larger disk is placed on a smaller disk during the transfer */



#include<iostream>
using namespace std;

//tower of HANOI function implementation
void TOH(int n,char Sour, char Aux,char Des)
{ 
	if(n==1)
	{
		cout<<"Move Disk "<<n<<" from "<<Sour<<" to "<<Des<<endl;
		return;
	}
	
	TOH(n-1,Sour,Des,Aux);
	cout<<"Move Disk "<<n<<" from "<<Sour<<" to "<<Des<<endl;
	TOH(n-1,Aux,Sour,Des);
}

//main program
int main()
{ 
	int n;
	
	cout<<"Enter no. of disks:";	
	cin>>n;
	//calling the TOH 
	TOH(n,'A','B','C');
	
	return 0;
}