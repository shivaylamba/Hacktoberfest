#include <iostream>
using namespace std;
 //Compiler version g++ 6.3.0

 int main()
 {
 	int n;
 	cin >> n;
 	int a[n];
 	for (int z = 0; z < n; z++){
 		cin >> a[z];
 	}
 	for (int i=0; i<n; i++){
 		for (int j=0; j<n ; j++){
 			if(a[j]>a[i]){
 				int temp = a[i];
 				a[i] = a[j];
 				a[j] = temp;
 			}
 		}
 	}
 	for (int i=n-1; i>-1; i--){
 		cout << a[i]<< " ";
 	}
 	return 0;
 }
