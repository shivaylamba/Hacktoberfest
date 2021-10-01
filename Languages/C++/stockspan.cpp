#include <iostream>
using namespace std;
#include<stack>
int* stockSpan(int *price, int size)  {
	// Write your code here
   int *a=new int[size];
    int i=0;
    stack<int>s;
    s.push(0);
    a[0]=1;
    for(i=1;i<size;i++) 
    {
     while (!s.empty() && price[s.top()] <price[i]) {
            s.pop(); 
     }
        a[i] = (s.empty()) ? (i + 1) : (i - s.top()); 
  
        s.push(i); 
    }
        return a;
    
}  
int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
