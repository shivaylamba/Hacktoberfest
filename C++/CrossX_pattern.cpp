#include <iostream>
using namespace std;
 
void printPattern(int n)
{
    // Print all rows one by one
    for (int i = 1; i <= n; i++) {
 
        // Print characters of current row
        for (int j = 1; j <= n; j++) {
            // For i = 1, we print a '$' only in
            // first and last columns
            // For i = 2, we print a '$' only in
            // second and second last columns
            // In general, we print a '$' only in
            // i-th and n+1-i th columns
 
            if (j == i || j == (n + 1 - i))
                cout << "*";
            else
                cout << " ";
        }
 
        // Print a newline before printing the
        // next row.
        cout << endl;
    }
}
 
// Driver Code
int main()
{
    // n denotes the number of lines in which
    // we want to make X pattern
    int n = 6;
 
    // Function Call
    printPattern(n);
    return 0;
}
