// Given a N x N matrix where every cell has some number of coins. Count number of ways to reach bottom right cell of matrix from top left cell with exactly K coins. We can move to (i+1, j) or (i, j+1) from a cell (i, j).


// Input:
// 2
// 16
// 3
// 1 2 3 4 6 5 9 8 7
// 12
// 3
// 1 2 3 4 6 5 3 2 1

// Output:
// 0
// 2

#include <iostream>
#include<unordered_map>
#include<cstring>
#include<string>
using namespace std;
#define mod 1000000007

// A 3d Dp solution 
long long int noOfWays(int arr[][200] , int row , int col , int k , unordered_map<string,long long int> &state){
    if(k<0) return 0 ;
    if(row <0 || col<0){
        return 0 ;
    }
    if(row == 0  && col == 0 && k==arr[row][col]){
        return 1;
    }
    // adding the subproblem answers by cahching the answers 
    string ans = to_string(row) +"|" + to_string(col) + "|" + to_string(k) ;
    
    if(state.find(ans) != state.end()){
        return state[ans];
    }
    
    state[ans] = noOfWays(arr,row-1,col,k-arr[row][col],state) + noOfWays(arr,row,col-1,k-arr[row][col],state); 
    return state[ans]; 
}

int main() {
    int t ; 
    cin >> t; 
    int arr[200][200]; 
    int k ; 
    int n ; 
    while(t--){
        cin >> k >> n ; 
        for(int i=0 ;i<n;i++){
            for(int j=0 ;j<n ;j++){
                cin >> arr[i][j] ; 
            }
        }
        unordered_map<string,long long int> state;
        long long int ans = noOfWays(arr,n-1,n-1,k,state);
        cout << ans << endl; 
    }
    
	//code
	return 0;
}