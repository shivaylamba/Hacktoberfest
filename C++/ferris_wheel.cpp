/*
Author : Aditya Choubey

Problem Statement :
There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.

Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. 
You know the weight of every child.

What is the minimum number of gondolas needed for the children?

This program prints the solution to the above problem.
*/
#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main()
{
    int n;
    ull x;
    cin >> n >> x;

    vector<ull> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end(), greater<ull>());

    int c = 0;
    int j = n - 1;
    int i = 0;
    while(i <= j)
    {
        if(weights[i] + weights[j] <= x)
        {
            c++;
            i++;
            j--;
        }
        else
        {
            c++;
            i++;
        }
    }

    cout << c << endl;
    return 0;
}