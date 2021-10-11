// October 11th, 2021 by Kevindar

/*
Knapsack 0-1 Problem

Description:
	Given weights and profits of n items , and given a knapsack ( container ) of capacity 'W' , we need to return the maximum profit such that the weights done not exceeds the Knapsack capacity.
In other words :
Given two integer arrays Profits[0..n-1] and weights[0..n-1] which represent profits and weights associated with n items respectively and given an integer Knapsack_Capacity 'W' we need to return the maximum profit which can be obtained .
	
Constraint :
		The objects(weights) follow a binary property (either You  completely pick an object or don't pick it (0-1 property) . 
*/

#include <iostream>
using namespace std;

int max(int a, int b){
    return (a > b) ? a : b;
}

int knapsack(int * w, int * v, int m, int n){

    int ** B = new int * [n + 1];

    for (int x = 0; x < n + 1; x++) {
        B[x] = new int[m + 1];
    }

    for(int item = 1; item <= n; item++){
        for( int capacity = 1; capacity <= m; capacity++ ){
            if(item == 0 || capacity == 0){
                B[item][capacity] = 0;
            }
            else if(w[item - 1] <= capacity){
                B[item][capacity] = max(B[item - 1][capacity],
                    B[item - 1][capacity - w[item - 1]] + v[item - 1]);
            }
            else {
                B[item][capacity] = B[item - 1][capacity];
            }
        }
    }
    return B[n][m];
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;
    
    int * weights = new int[n];
    int * value = new int[n];
  
    cout << "Enter weight of each items separated by space, and hit [ENTER]" << endl;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
  
    cout << "Enter value of each items separated by space, and hit [ENTER]" << endl;
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    int maxWeight;
    cout << "Enter maximum weight capacity: ";
    cin >> maxWeight;

    cout << knapsack(weights, value, maxWeight, n);
}
