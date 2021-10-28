#include <iostream>
 
using namespace std;
 
void tower(int n, char source, char des, char via){
if(n == 1){
    cout << "Moved the ring "<< n << " from " << source << " to " << des << " via " << via << ".\n";
 
}
else{
    tower(n-1,source, via, des);
    cout << "Moved the ring " << n << " from " << source << " to " << des << " via " << via << ".\n";
    tower(n-1,via,des,source);
}
 
}
 
int main()
{
    int rings;
    char source='A';
    char des = 'B';
    char via = 'C';
    cout << "Enter the number of rings : "; 
    cin >> rings;
    tower(rings,source,des,via);
 
    return 0;
}