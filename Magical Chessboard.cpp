
/* Problem: John has a magical chessboard. It looks like a normal chessboard except its size is N.
            Therefore the number of cells in the chessboard is N*N. He is interested in counting the number of squares
            in the chessboard. It is very tough task for him, so he is looking for your help. */

#include <iostream>

using namespace std;

int main(){
    
    int N;
    cout<<"Enter the size of the square: ";
    cin>>N;
    
    int number_of_squares {0};
    
    for(int i {1}; i<=N; i++){
        number_of_squares += i*i;
    }
    
    cout<<"The number of squares in the chessboard are "<<number_of_squares<<endl;
    
    return 0;
}