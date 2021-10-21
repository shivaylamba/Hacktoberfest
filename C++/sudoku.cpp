#include<iostream>
#include<vector>
using namespace std;
bool issafe(vector<vector<int>>&arr, int row, int col,int value){
    for(int i=0;i<arr.size();i++){
        if(arr[i][col]==value){
            return false;
        }
    }
    for(int i=0;i<arr.size();i++){
        if(arr[row][i]==value){
            return false;
        }
    }
    row=(row/3)*3;
    col=(col/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i+row][j+col]==value){
                return false;
            }
        }
    }
    return true;
}
void display(vector<vector<int>>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
void sudoku(vector<vector<int>>&arr, int row, int col){
    if(row==arr.size()-1 && col==arr.size()){
        
        display(arr);
        return ;
    }
    if(col==arr[0].size()){
        row+=1;
        col=0;
    }
    if(arr[row][col]!=0){
        sudoku(arr,row,col+1);
    }

    else{
        for(int value=1;value<=9;value++)
        {
            if(issafe(arr,row,col,value))
            {
                arr[row][col]=value;
                sudoku(arr,row,col+1);
                arr[row][col]=0;
            }
        }
    }
}

void sudoku(){
    vector<vector<int>>arr={{5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},
    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}};
    sudoku(arr,0,0);
}


int main(){

    sudoku();
    return 0;
}
