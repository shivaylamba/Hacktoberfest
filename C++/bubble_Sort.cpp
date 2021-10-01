/*

// Stable Sorting Algorithm

// Sorting in ascending order

// Time Complexity: 
    for worst case - O(n^2)
    for best case - O(n)
    
// Space Complexity: constant ('1')

// Bubble Sort: (note that for an array of length 5, 4 steps are used for sorting)
    a[5] = {3, 4, 2, 5, 1}
        Sorting:
        {3, 4, 2, 1, [5]}         [] - represents sorted array
        
        {3, 2, 4, 1, [5]}
        {3, 2, 1, [4, 5]}

        {2, 3, 1, [4, 5]}
        {2, 1, [3, 4, 5]}

        [1, 2, 3, 4, 5]

*/


#include <iostream>
using namespace std;

int main(){

    //our array will be the size of 'n' provided by the user
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    //taking input of the array from the user:
    int a[n];
    cout << "Enter elements: \n";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    //Bubble Sort:
    int x = 1; //declaring a variable to count steps (steps will run 'n - 1' times)
    while(x < n){
        for(int i = 0; i < n - x; i++){
            if(a[i + 1] < a[i]){
                // Swapping if (i + 1)th element < (i)th element
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
        x++;
    }

    //Returning the sorted array:
    cout << "Sorted array: \n";
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;

  return 0;
}
