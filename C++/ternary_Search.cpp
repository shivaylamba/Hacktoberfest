#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_ELS 1000000

int tS(int l, int r, int key, std::vector<int>arr)
{
    if (l < r){
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;
        int first = arr[l];
        int last = arr[r];
        int ans = 0;

        if (key == arr[mid1])
            return mid1;
        else if (key == arr[mid2])
            return mid2;
        else if(key == first)
            return l;
        else if(key == last)
            return r;

        if (key < arr[mid1]){
            ans = tS(l, mid1-1, key, arr);
        } else if(key > arr[mid2]){
            ans = tS(mid2+1, r, key, arr);
        } else{
            ans = tS(mid1+1, mid2-1, key, arr);
        }
        return ans;
    } else{
        if(key == arr[l])
            return l;
    }
    return -1;
}

int main(){
    std::vector<int>arr;
    int n = 0;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter all the elements of the array, each in a new line: \n";
    for(int i=0; i<n; i++){
        int inp = 0;
        std::cin >> inp;
        arr.push_back(inp);
    }

    // let's say if the array is NOT sorted, then just sort it using C++ library:
    std::sort(arr.begin(), arr.end());
    std::cout << "Sorted Array: \n";
    for(int i=0; i<arr.size(); i++)
        std::cout << arr[i] << ", ";
    std::cout << "\n";

    int key = 0;
    std::cout << "Enter the elment you'd like to find: ";
    std::cin >> key;
    // calling the tS or ternary search function:
    if(n == 1)
        std::cout << "There's only one element in the array!\n";
    else{
        int ans = tS(0, n-1, key, arr);
        if(ans == -1)
            std::cout << "Sorry! the key: " << key << " is not present in the array!\n";
        else{
            std::cout << "The element was found at index: " << ans << " of the sorted array\n";
        }
    }
}