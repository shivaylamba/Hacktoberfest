#include <iostream>
using namespace std;
 
void printRLE(string s)
{
    for (int i = 0; s[i] != '\0'; i++) {
 
        
        int count = 1;
        while (s[i] == s[i + 1]) {
            i++;
            count++;
        }
        if(count == 1)
        {
            cout << s[i]<<endl;
        }
        else
        {
            cout << s[i] << count << " ";
        }
        
    }
 
    cout << endl;
}
 

int main()
{
    string l;
    
    cin>>l;
    
    printRLE(l);
    
    // printRLE("ccccOddEEE");

    return 0;
}