#include<iostream>
using namespace std;
int main ()
{
    int num , fact = 1;
    cin>>num;
    
    // Factorial of negative number doesn't exist
    // Read more here - https://www.quora.com/Is-the-factorial-of-a-negative-number-possible
    if(num < 0)
        cout << "Not Possible";
    else
    {
        for(int i = 1; i <= num; i++)
            fact = fact * i;
    }
    
    cout << "Fact " << num << ": " << fact;
}
// Time complexity: O(N)
// Space complexity: O(1)