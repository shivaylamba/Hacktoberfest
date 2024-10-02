/*
C++ STL | Set 1 (vector)
Implement different operations on a vector A .
Input:
The first line of input contains an integer T denoting the no of test cases . 
Then T test cases follow. The first line of input contains an integer Q denoting 
the no of queries . Then in the next line are Q space separated queries .
A query can be of five types 
1. a x (Adds an element x to the vector A at the end )
2. b (Sorts the vector A in ascending order )
3. c (Reverses the vector A)
4. d (prints the size of the vector)
5. e (prints space separated values of the vector)
5. f  (Sorts the vector A in descending order)
Output:
The output for each test case will  be space separated integers denoting the results 
of each query . 
Constraints:
1<=T<=100
1<=Q<=100
Example:
Input
2
6
a 4 a 6 a 7 b c e
4
a 55 a 11 d e
Output
7 6 4
2 55 11
Explanation :
For the first test case
There are six queries. Queries are performed in this order
1. a 4 { Vector has 4  }
2. a 7 {vector has 7 }
3. a 6 {vector has 6}
4. b {sorts the vector in ascending order, vector now is 5 6 7}
5. c {reverse the vector }
6. e {prints the element of the vectors 7 6 4}
For the sec test case 
There are four queries. Queries are performed in this order
1. a 55  (vector A has 55}
2. a 11  (vector A has 55 ,11}
3. d      (prints the size of the vector A ie. 2 )
4. e      (prints the elements of the vector A ie 55 11)
Note:The Input/Output format and Example given are used for system's internal purpose, 
and should be used by a user for Expected Output only. As it is a function problem, 
hence a user should not read any input from stdin/console. The task is to complete 
the function specified, and not to write the full code.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void add_to_vector(vector<int> &A,int x);


void sort_vector_asc(vector<int> &A);


void reverse_vector(vector<int> &A);

int size_of_vector(vector<int> &A);

void sort_vector_desc(vector<int> &A);

void print_vector(vector<int> &A);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		vector<int> A;
		int q;
		cin>>q;
		while(q--)
		{
			char c;
			cin>>c;
			if(c=='a')
			{
				int x;
				cin>>x;
				add_to_vector(A,x);
			}
			if(c=='b')
			{
				sort_vector_asc(A);
			}
			if(c=='c')
			{
				reverse_vector(A);
			}
			if(c=='d')
			{
				cout<<size_of_vector(A)<<" ";
			}
			if(c=='e')
			{
				print_vector(A);
				
			}
			if(c=='f')
			{
				sort_vector_desc(A);
			}
			
		}
cout<<endl;
	}
	return 0;
}
// } Driver Code Ends
/*You are required to complete below methods*/
/*inserts an element x at 
the back of the vector A */
void add_to_vector(vector<int> &A,int x)
{
	//Your code here
    A.push_back(x);
    
}
/*sort the vector A in ascending order*/
void sort_vector_asc(vector<int> &A)
{
	//Your code here
    sort(A.begin(),A.end());
}
/*reverses the vector A*/
void reverse_vector(vector<int> &A)
{
	//Your code here
    reverse(A.begin(),A.end());
}
/*returns the size of the vector  A */
int size_of_vector(vector<int> &A)
{
	//Your code here
    return A.size();
}
/*sorts the vector A in descending order*/
void sort_vector_desc(vector<int> &A)
{
	//Your code here
	   // sort(A.begin(),A.end());
    // reverse(A.begin(),A.end());
        sort(A.begin(),A.end(),greater<int>());

}
/*prints space separated 
elements of vector A*/
void print_vector(vector<int> &A)
{
	//Your code here
	for(int x:A){
	    cout<<x<<" ";
	}
}
