//function to search an element in a 2d Sorted Matrix

pair<int, int> binarySearch2D(vector<vector<int>> arr, int num){

    int col = arr[0].size();
    int row = arr.size();

    int i = 0;
    int j = col-1;

    while(i < row && j >= 0){

        if(arr[i][j] == num){
            pair<int, int> p = make_pair(i, j);
            return p;
        }

        if(num > arr[i][j]) i++;
        else j--;
    }

    pair<int, int> p = make_pair(-1, -1);
    return p;
}