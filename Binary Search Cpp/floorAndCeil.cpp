//functions to find the floor and ceil of an element in a sorted array

//to find floor
int elementFloor(vector<int> arr, int num){

    int n = arr.size();
    int start = 0;
    int end = n-1;

    int floor = -1;
    while(start <= end){

        int mid = start + (end-start)/2;

        if(arr[mid] == num) return arr[mid];

        if(arr[mid] < num){
            floor = arr[mid];
            start = mid+1;
        } 
        else end = mid-1;
    }
    
    return floor;
}

//to find ceil
int elementCeil(vector<int> arr, int num){
    
    int n = arr.size();
    int start = 0;
    int end = n-1;

    int ceil = -1;
    while(start <= end){

        int mid = start + (end-start)/2;

        if(arr[mid] == num) return arr[mid];

        if(arr[mid] > num){
            ceil = arr[mid];
            end = mid-1;
        }
        else start = mid+1;
    }
    
    return ceil;
}