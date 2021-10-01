//C++ program to find intersection of two
// sorted arrays(Handling Duplicates)
#include <bits/stdc++.h>
using namespace std;
vector<int> findIntersection(int arr1[], int arr2[], int m, int n)
{
    //store the union of both arrays
    vector<int> ans;
    int i = 0;
    int j = 0;
    while (i < m && j < n)
    {
        //if duplicates in any array is found move iterator ahead
        while (i < m - 1 && arr1[i] == arr1[i + 1])
        {
            i++;
        }
        while (j < n - 1 && arr2[j] == arr1[j + 1])
        {
            j++;
        }
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        //both pointing to same element
        else
        {
            ans.push_back(arr[i]);
            i++;
            j++;
        }
        return ans;
    }
    //driver code
    int main()
    {
        findIntersection(arr1, arr2, m, n);
        return 0;
    }