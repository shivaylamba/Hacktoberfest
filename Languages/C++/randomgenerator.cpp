#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int main(){
int a ; cin>> a;
int  b; cin>> b;
int num = (rand() % (a - b + 1)) + b;
cout << num;
return 0;
}
