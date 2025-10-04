#include <iostream>
#include <vector>
using namespace std;

int sumUptoTarget(vector<vector<int>>& matrix, int target) {
    int sum = 0;
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            if(matrix[i][j] <= target)
                sum += matrix[i][j];
            else
                return sum;
        }
    }
    return sum;
}

int main() {
    vector<vector<int>> matrix = {{1,3,5,7},
                                  {10,11,16,20},
                                  {23,30,34,60}};
    int target = 10;
    cout << sumUptoTarget(matrix, target) << endl;
    return 0;
}
